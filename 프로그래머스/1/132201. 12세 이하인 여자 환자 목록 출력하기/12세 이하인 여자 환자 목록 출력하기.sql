SELECT PT_NAME, PT_NO, GEND_CD, AGE, if(TLNO IS NULL, 'NONE', TLNO)
FROM patient
WHERE age <= 12 and gend_cd = 'W'
ORDER BY age desc, pt_name