-- 코드를 입력하세요
SELECT CAR_ID, 
if (CAR_ID in (
    select CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where START_DATE <= '2022-10-16' and END_DATE >='2022-10-16'
), '대여중', '대여 가능') as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
group by car_id
order by CAR_ID desc