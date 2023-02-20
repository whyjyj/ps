-- 코드를 입력하세요
SELECT mem.member_name, rev.review_text, date_format(rev.review_date, "%Y-%m-%d") as review_date
FROM member_profile mem
JOIN rest_review rev ON mem.member_id = rev.member_id
WHERE mem.member_id = (SELECT member_id
                    FROM rest_review
                    GROUP BY member_id
                    ORDER BY count(*) DESC
                    LIMIT 1)
ORDER BY 3, 2