-- 코드를 입력하세요
SELECT fp.product_id, product_name, (price * total_amount) AS total_sales
FROM food_product fp
JOIN (SELECT product_id, SUM(amount) as total_amount
    FROM food_order
    WHERE date_format(produce_date, "%Y-%m") = "2022-05"
    GROUP BY product_id) sub
ON fp.product_id = sub.product_id
ORDER BY 3 DESC, 1