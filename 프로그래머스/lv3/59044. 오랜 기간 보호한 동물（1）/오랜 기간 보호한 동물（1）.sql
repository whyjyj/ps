-- 코드를 입력하세요
SELECT ins.name, ins.datetime
FROM animal_ins ins
LEFT JOIN animal_outs outs ON ins.animal_id = outs.animal_id
WHERE ins.animal_id IS NOT NULL AND outs.animal_id IS NULL
ORDER BY 2
LIMIT 3