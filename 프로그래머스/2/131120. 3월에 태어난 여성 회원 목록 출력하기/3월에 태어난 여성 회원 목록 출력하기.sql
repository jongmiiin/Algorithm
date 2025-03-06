SELECT member_id, member_name, gender, date_format(date_of_birth, '%Y-%m-%d') AS date_of_birth
FROM member_profile
WHERE gender = 'W' AND date_of_birth like '%03%' AND TLNO IS NOT NULL
ORDER BY member_id