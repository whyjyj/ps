-- 코드를 입력하세요
SELECT Hour(datetime) AS hour, COUNT(*) AS count
FROM animal_outs
GROUP BY hour
Having hour between 9 and 19
ORDER BY 1