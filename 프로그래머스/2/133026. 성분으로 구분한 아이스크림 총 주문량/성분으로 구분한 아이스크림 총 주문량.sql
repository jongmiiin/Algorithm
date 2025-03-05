SELECT i.ingredient_type, SUM(f.total_order) AS total_order
# SELECT *
FROM first_half f JOIN icecream_info i
ON i.flavor = f.flavor
# WHERE i.flavor = f.flavor
GROUP BY ingredient_type
# HAVING i.flavor = f.flavor
ORDER BY total_order