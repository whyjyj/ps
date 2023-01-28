-- 코드를 입력하세요
SELECT history_id, car_id, date_format(start_date, "%Y-%m-%d") as START_DATE, 
    date_format(end_date, "%Y-%m-%d") as END_DATE , 
    if(datediff(end_date, start_date) + 1 >= 30, "장기 대여", "단기 대여") as RENT_TYPE
FROM car_rental_company_rental_history
WHERE YEAR(start_date) = 2022 and MONTH(start_date) = 9
ORDER BY history_id DESC