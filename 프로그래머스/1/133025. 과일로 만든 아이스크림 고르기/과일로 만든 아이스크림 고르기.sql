SELECT FLAVOR
FROM first_half 
WHERE total_order > 3000 and flavor in (SELECT flavor
                                        FROM icecream_info
                                        WHERE ingredient_type = 'fruit_based')
ORDER BY total_order desc