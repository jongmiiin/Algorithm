SELECT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM developer_infos
WHERE skill_1 = 'Python' or skill_2 = 'Python' or skill_3 = 'Python'
ORDER BY ID