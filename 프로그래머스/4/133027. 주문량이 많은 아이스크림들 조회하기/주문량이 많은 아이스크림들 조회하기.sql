SELECT flavor
FROM (
    SELECT flavor, total_order
    FROM first_half
    UNION ALL
    SELECT flavor, total_order
    FROM july
) as t
GROUP BY FLAVOR
ORDER BY SUM(total_order) DESC
LIMIT 3