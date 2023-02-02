-- 코드를 입력하세요
SELECT user_id, product_id
FROM online_sale
GROUP BY 1, 2
HAVING count(*) > 1
ORDER BY 1, 2 DESC