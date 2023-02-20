-- 코드를 입력하세요
SELECT fh.flavor
FROM first_half fh
JOIN (SELECT flavor, SUM(total_order) as total_order
    FROM JULY
    GROUP BY flavor) j ON fh.flavor = j.flavor
ORDER BY (fh.total_order + j.total_order) DESC
LIMIT 3
