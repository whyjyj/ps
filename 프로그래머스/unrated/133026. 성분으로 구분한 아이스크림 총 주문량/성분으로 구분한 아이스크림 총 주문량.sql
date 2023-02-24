-- 코드를 입력하세요
SELECT ingredient_type, SUM(total_order) AS total_orders
FROM first_half f
JOIN icecream_info i ON f.flavor = i.flavor
GROUP BY ingredient_type