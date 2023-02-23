-- 코드를 입력하세요
SELECT Year(sales_date) AS year, Month(sales_date) AS month, gender, count(distinct os.user_id) AS users
FROM user_info ui
JOIN online_sale  os ON ui.user_id = os.user_id
GROUP BY 1,2,3
HAVING gender IS NOT NULL
ORDER BY 1,2,3