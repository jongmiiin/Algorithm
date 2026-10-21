SELECT YEAR(differentiation_date) as year,
        MAX(size_of_colony) OVER(PARTITION BY(YEAR(differentiation_date))) -size_of_colony as year_dev, id
FROM ecoli_data
ORDER BY year asc, year_dev asc