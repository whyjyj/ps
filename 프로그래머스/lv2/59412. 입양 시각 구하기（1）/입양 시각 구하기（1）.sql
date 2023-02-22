-- 코드를 입력하세요
SELECT Hour(datetime), count(*)
FROM animal_outs
WHERE 9 <= Hour(datetime) AND Hour(datetime) < 20
GROUP BY Hour(datetime)
ORDER BY 1