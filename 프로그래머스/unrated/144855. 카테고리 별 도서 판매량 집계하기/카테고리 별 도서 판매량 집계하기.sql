-- 코드를 입력하세요
SELECT b.category, sum(s.sales) as TOTAL_SALES
FROM book b
JOIN book_sales s
ON b.book_id = s.book_id
WHERE date_format(s.sales_date, "%Y-%m") = "2022-01"
GROUP BY b.category
ORDER BY b.category ASC