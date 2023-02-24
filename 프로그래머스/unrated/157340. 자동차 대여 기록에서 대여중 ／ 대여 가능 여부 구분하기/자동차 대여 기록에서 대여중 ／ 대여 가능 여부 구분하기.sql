-- 코드를 입력하세요
SELECT car_id, 
        IF(car_id IN(SELECT car_id
                    FROM car_rental_company_rental_history
                    WHERE start_date <= "2022-10-16" AND "2022-10-16" <= end_date),
          "대여중", "대여 가능") AS AVAILABILITY
FROM car_rental_company_rental_history
GROUP BY 1
ORDER BY 1 DESC
