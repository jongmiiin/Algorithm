SELECT b.book_id, a.author_name, date_format(b.published_date, '%Y-%m-%d') as published_date
FROM book b, author a
WHERE b.author_id = a.author_id and b.category = '경제'
ORDER BY b.published_date