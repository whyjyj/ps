-- 코드를 입력하세요
SELECT animal_type, count(*) as count
FROM animal_ins
GROUP BY animal_type
HAVING animal_type = "Cat" OR animal_type = "Dog"
ORDER BY animal_type ASC