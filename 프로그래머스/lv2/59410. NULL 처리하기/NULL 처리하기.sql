-- 코드를 입력하세요
SELECT animal_type, 
    IF(name is not null, name, "No name") AS name, 
    sex_upon_intake
FROM animal_ins