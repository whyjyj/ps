-- 코드를 입력하세요
SELECT MONTH(start_date) as month, car_id, count(*) as RECORDS
FROM car_rental_company_rental_history
WHERE car_id in (SELECT car_id
                FROM car_rental_company_rental_history
                WHERE (date_format(start_date, "%Y-%m") like "2022-08" or 
                    date_format(start_date, "%Y-%m") like "2022-09" or
                    date_format(start_date, "%Y-%m") like "2022-10")
                GROUP BY car_id
                HAVING count(*) >= 5)
        AND MONTH(start_date) BETWEEN 8 AND 10
GROUP BY month, car_id
HAVING records > 0
ORDER BY month ASC, car_id DESC