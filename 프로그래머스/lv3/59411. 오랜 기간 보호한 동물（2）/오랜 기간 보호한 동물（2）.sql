-- 코드를 입력하세요
SELECT o.animal_id, o.name
FROM animal_outs o
LEFT JOIN animal_ins i
    ON o.animal_id = i.animal_id
WHERE i.datetime is not null
ORDER BY datediff(o.datetime, i.datetime) DESC
LIMIT 2
