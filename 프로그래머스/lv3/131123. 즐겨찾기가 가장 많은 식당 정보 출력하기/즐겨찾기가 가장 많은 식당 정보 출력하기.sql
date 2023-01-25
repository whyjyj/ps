-- 코드를 입력하세요
SELECT food_type, rest_id, rest_name, favorites
FROM rest_info a
WHERE favorites = (
    SELECT MAX(favorites)
    FROM rest_info b
    WHERE b.food_type = a.food_type
)
GROUP BY food_type
ORDER BY food_type desc