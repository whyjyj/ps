-- 코드를 입력하세요
SELECT book_id, author_name, date_format(published_date, "%Y-%m-%d") as published_date
FROM book b
JOIN author a ON b.author_id = a.author_id
WHERE category = '경제'
ORDER BY 3