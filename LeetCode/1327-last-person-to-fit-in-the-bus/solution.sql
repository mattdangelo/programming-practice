-- Write your PostgreSQL query statement below
SELECT person_name 
FROM (SELECT person_name, (SUM(weight) OVER (ORDER BY turn)) AS total_amount
      FROM Queue)
WHERE total_amount <= 1000
ORDER BY total_amount DESC
LIMIT 1
