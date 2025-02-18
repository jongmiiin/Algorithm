SELECT HISTORY_ID, CAR_ID, date_format(START_DATE, '%Y-%m-%d') AS START_DATE, 
        date_format(END_DATE, '%Y-%m-%d') AS END_DATE, 
        if(DATEDIFF(END_DATE, START_DATE) >= 29, '장기 대여', '단기 대여') AS RENT_TYPE
FROM car_rental_company_rental_history
WHERE start_date LIKE '2022-09%'
ORDER BY history_id desc