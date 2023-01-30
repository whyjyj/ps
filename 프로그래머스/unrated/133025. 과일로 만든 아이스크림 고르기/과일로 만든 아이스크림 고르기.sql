-- 코드를 입력하세요
SELECT fh.flavor
FROM first_half fh
    JOIN icecream_info i
    ON fh.flavor = i.flavor
WHERE fh.total_order >= 3000 AND i.ingredient_type = "fruit_based"
ORDER BY fh.total_order DESC