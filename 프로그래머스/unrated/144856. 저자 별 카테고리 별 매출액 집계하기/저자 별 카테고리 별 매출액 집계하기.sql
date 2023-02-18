-- 코드를 입력하세요
SELECT b.author_id, a.author_name, b.category, SUM(b.price * s.sales) as total_sales
FROM book b
JOIN author a ON b.author_id = a.author_id
JOIN (SELECT book_id, Sum(sales) as sales FROM book_sales WHERE Year(sales_date) = '2022' AND MONTH(sales_date) = '01' GROUP BY book_id) s ON b.book_id = s.book_id
GROUP BY author_id, category
ORDER BY author_id ASC, category desc

