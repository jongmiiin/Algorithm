SELECT ANIMAL_ID, NAME
FROM animal_ins
WHERE animal_type = 'DOG' AND name like '%el%'
ORDER BY name