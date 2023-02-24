-- 코드를 입력하세요
SELECT a.author_id, a.author_name, category, SUM(price * total_cnt) AS total_sales
FROM book b
JOIN author a ON b.author_id = a.author_id
JOIN (SELECT book_id, SUM(sales) as total_cnt
    FROM book_sales
    WHERE Year(sales_date) = "2022" AND Month(sales_date) = "01"
     GROUP BY book_id) bs ON b.book_id = bs.book_id
GROUP BY 1, 3
ORDER BY 1, 3 DESC
