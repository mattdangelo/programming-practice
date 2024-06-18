-- Write your PostgreSQL query statement below
SELECT ROUND(CAST(SUM(i1.tiv_2016) AS NUMERIC), 2) AS tiv_2016
FROM Insurance i1
LEFT JOIN LATERAL (
    SELECT *
    FROM Insurance i2
    WHERE i1.lat = i2.lat AND i1.lon = i2.lon AND i1.pid != i2.pid
    ORDER BY pid
    LIMIT 1
) i2 ON TRUE
WHERE i1.tiv_2015 IN (
    SELECT tiv_2015 
    FROM Insurance i3
    WHERE i1.pid != i3.pid
)
AND i2.pid IS NULL
