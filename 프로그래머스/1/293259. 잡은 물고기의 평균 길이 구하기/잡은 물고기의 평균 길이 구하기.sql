SELECT ROUND(AVG(if(LENGTH IS NULL, 10, LENGTH)), 2) AS AVERAGE_LENGTH
FROM fish_info

