-- 코드를 입력하세요
SELECT pt_name, pt_no, gend_cd, age, if(tlno is null, "NONE", tlno) as tlno
FROM patient
WHERE age <= 12 and gend_cd = "W"
ORDER BY age DESC, pt_name ASC