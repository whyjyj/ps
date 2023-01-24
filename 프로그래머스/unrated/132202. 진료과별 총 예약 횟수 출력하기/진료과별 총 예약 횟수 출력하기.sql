-- 코드를 입력하세요
SELECT mcdp_cd as 진료과코드, count(apnt_no) as 5월예약건수
FROM appointment
WHERE datediff(apnt_ymd, '2022-05-01') <= 30 and datediff(apnt_ymd, '2022-05-01') >= 0
GROUP BY mcdp_cd
ORDER BY 5월예약건수 ASC, mcdp_cd asc