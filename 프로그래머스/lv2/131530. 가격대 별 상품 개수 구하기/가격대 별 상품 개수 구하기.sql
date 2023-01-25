-- 코드를 입력하세요
SELECT (price div 10000) * 10000 as PRICE_GROUP, count(product_id) as PRODUCTS
FROM product
GROUP BY PRICE_GROUP
ORDER BY PRICE_GROUP