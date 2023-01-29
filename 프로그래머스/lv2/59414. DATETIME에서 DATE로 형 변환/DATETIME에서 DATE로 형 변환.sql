-- 코드를 입력하세요
SELECT animal_id, name, date_format(datetime, "%Y-%m-%d")
FROM animal_ins
ORDER BY animal_id ASC
