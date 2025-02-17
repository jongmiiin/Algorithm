SELECT COUNT(user_id) as USERS
FROM user_info
WHERE joined like '2021%' and age >= 20 and age <= 29