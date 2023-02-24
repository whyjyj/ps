-- 코드를 입력하세요
SELECT MONTH(start_date) as MONTH, car_id, COUNT(*) AS records
FROM car_rental_company_rental_history
WHERE car_id IN (SELECT car_id
                FROM car_rental_company_rental_history
                WHERE start_date between "2022-08-01" AND "2022-10-31"
                GROUP BY car_id
                HAVING COUNT(*) >= 5 AND (start_date between "2022-08-01" AND "2022-10-31"))
GROUP BY 1, 2
ORDER BY 1, 2 DESC