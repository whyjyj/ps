-- 코드를 입력하세요
SELECT product_code, SUM(price * sales_amount) AS sales
FROM product p
JOIN offline_sale off ON p.product_id = off.product_id
GROUP BY product_code
ORDER BY sales DESC, product_code ASC