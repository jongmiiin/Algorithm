SELECT DR_NAME,	DR_ID, MCDP_CD, date_format(hire_ymd, '%Y-%m-%d') as HIRE_YMD
FROM doctor
WHERE MCDP_CD = 'CS' or MCDP_CD = 'GS'
ORDER BY HIRE_YMD desc, dr_name