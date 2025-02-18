SELECT CAR_ID, CAR_TYPE, DAILY_FEE, OPTIONS
FROM car_rental_company_Car
WHERE options like '%네비게이션%'
ORDER BY car_id desc