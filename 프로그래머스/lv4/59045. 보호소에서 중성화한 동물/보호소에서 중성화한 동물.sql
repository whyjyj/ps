-- 코드를 입력하세요
SELECT ins.animal_id, ins.animal_type, ins.name
FROM animal_ins ins
JOIN animal_outs outs ON ins.animal_id = outs.animal_id
WHERE sex_upon_intake like "Intact%" AND 
    (sex_upon_outcome like "Spayed%" OR sex_upon_outcome like "Neutered%")
ORDER BY animal_id