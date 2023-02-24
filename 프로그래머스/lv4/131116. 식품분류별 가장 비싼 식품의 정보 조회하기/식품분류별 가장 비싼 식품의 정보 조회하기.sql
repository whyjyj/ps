-- 코드를 입력하세요
SELECT category, price, product_name
FROM food_product
WHERE (category, price) in (SELECT category, MAX(PRICE) as max_price
                            FROM food_product
                            GROUP BY category
                            HAVING category = '과자' OR category = '국' OR 
                                category = '김치' OR category = '식용유' )
ORDER BY 2 DESC
