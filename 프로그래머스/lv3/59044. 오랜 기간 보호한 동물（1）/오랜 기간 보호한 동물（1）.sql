-- 코드를 입력하세요
SELECT i.name, i.datetime
FROM animal_ins i
LEFT JOIN animal_outs o
ON i.animal_id = o.animal_id
WHERE o.animal_id is null
ORDER BY i.datetime ASC
LIMIT 3