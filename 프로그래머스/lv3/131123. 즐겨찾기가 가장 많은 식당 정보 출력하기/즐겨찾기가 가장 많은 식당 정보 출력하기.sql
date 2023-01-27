SELECT food_type, rest_id, rest_name, favorites
FROM rest_info
WHERE favorites in (SELECT MAX(favorites)
                   FROM rest_info
                    GROUP BY food_type
                   )
GROUP BY food_type
ORDER BY food_type desc