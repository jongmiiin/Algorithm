SELECT ANIMAL_TYPE, COUNT(*) AS count
FROM animal_ins
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE