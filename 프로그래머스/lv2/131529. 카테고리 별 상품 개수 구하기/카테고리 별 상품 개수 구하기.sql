-- 코드를 입력하세요
SELECT left(product_code, 2) as Category, count(product_id) as Products
FROM product
GROUP BY category