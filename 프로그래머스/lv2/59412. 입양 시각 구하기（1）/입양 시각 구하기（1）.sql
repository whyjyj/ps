-- 코드를 입력하세요
SELECT hour(datetime) as hour, count(*) as count
FROM animal_outs
GROUP BY hour(datetime)
HAVING hour >= 9 and hour < 20
ORDER BY hour