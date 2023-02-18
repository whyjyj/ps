SELECT fp.category, fp.price as MAX_PRICE, fp.product_name
FROM food_product fp, (SELECT category, Max(price) as price
                        FROM food_product
                        GROUP BY category
                       HAVING category in ('과자', '국', '김치', '식용유')
                        ) fp2
WHERE fp.category = fp2.category AND fp.price = fp2.price
ORDER BY max_price DESC