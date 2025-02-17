SELECT book_id, date_format(published_date, '%Y-%m-%d') as PUBLISHED_DATE
FROM book
WHERE published_date LIKE '2021%' AND category = '인문'
ORDER BY published_date