-- 코드를 입력하세요
SELECT mcdp_cd AS '진료과 코드', count(*) AS 5월예약건수
FROM appointment
WHERE Year(apnt_ymd) = "2022" AND MONTH(apnt_ymd) = "05"
GROUP BY mcdp_cd
ORDER BY 2, 1