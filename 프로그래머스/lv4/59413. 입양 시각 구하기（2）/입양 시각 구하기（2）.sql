-- 코드를 입력하세요
SET @HOUR = -1;

SELECT @HOUR := @HOUR + 1 AS HOUR, (SELECT COUNT(*) AS COUNT
                                    FROM ANIMAL_OUTS
                                    WHERE HOUR(datetime) = @HOUR
                                    ) AS COUNT
FROM ANIMAL_OUTS
WHERE @HOUR < 23