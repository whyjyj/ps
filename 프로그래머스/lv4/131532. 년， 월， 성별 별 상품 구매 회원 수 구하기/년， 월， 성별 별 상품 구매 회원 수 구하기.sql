-- 코드를 입력하세요
SELECT Year(sales_date) as YEAR, Month(sales_date) as MONTH, gender, count(DISTINCT os.user_id) as USERS
FROM user_info ui
JOIN online_sale os
ON ui.user_id = os.user_id
WHERE ui.gender IS NOT NULL
GROUP BY YEAR, MONTH, gender
ORDER BY YEAR, MONTH, gender