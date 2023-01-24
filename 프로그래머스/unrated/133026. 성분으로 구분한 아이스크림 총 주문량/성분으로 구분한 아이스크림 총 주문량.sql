-- 코드를 입력하세요
SELECT ingredient_type, SUM(f.total_order) as TOTAL_ORDER
FROM first_half f 
    INNER JOIN icecream_info i
    ON f.flavor = i.flavor
GROUP BY i.ingredient_type
ORDER BY TOTAL_ORDER ASC