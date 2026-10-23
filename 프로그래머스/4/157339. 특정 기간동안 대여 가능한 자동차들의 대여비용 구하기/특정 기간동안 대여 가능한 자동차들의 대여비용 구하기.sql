SELECT 
    c.car_id, 
    c.car_type, 
    ROUND(c.daily_fee * 30 * (100-p.discount_rate)/100)AS fee
FROM CAR_RENTAL_COMPANY_CAR c
JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN p 
ON c.car_type = p.car_type and p.duration_type = '30일 이상'
WHERE c.car_type in ('세단', 'SUV')
    and c.car_id not in (
        SELECT car_id
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE start_date <= '2022-11-30' and end_date >= '2022-11-01'
    )
HAVING fee >= 500000 and fee < 2000000
ORDER BY fee desc, c.car_type asc, c.car_id