-- 코드를 입력하세요
SET @HOUR = -1;

SELECT @HOUR := @HOUR + 1 AS HOUR, 
        (SELECT COUNT(*)
        FROM animal_outs
        WHERE @HOUR = HOUR(datetime)) AS COUNT
FROM animal_outs
WHERE @HOUR < 23

