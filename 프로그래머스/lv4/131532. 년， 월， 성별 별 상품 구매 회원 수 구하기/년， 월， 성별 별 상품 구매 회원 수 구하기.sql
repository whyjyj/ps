-- 코드를 입력하세요
SELECT Year(sales_date) AS year, Month(sales_date) AS month, gender, COUNT(DISTINCT ui.user_id) AS users
FROM user_info ui
JOIN online_sale os ON ui.user_id = os.user_id
WHERE gender IS NOT NULL
GROUP BY 1, 2, 3
ORDER BY 1, 2, 3