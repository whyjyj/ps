-- 코드를 입력하세요
SELECT m.member_name, r.review_text, date_format(r.review_date, "%Y-%m-%d") as review_date
FROM member_profile m
JOIN rest_review r
ON m.member_id = r.member_id
WHERE m.member_id = (SELECT member_id
    FROM rest_review
    GROUP BY member_id
    ORDER BY count(*) DESC
    LIMIT 1)
ORDER BY review_date ASC, review_text ASC