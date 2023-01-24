-- 코드를 입력하세요
SELECT animal_type, count(animal_id)
FROM animal_ins
GROUP BY animal_type
HAVING animal_type = 'Cat' or animal_type = 'Dog'
ORDER BY animal_type ASC