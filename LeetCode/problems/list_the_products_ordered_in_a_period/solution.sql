# Write your MySQL query statement below

SELECT product_name, SUM(unit) AS unit
FROM Orders o LEFT JOIN Products p ON o.product_id = p.product_id
WHERE MONTH(o.order_date) = '02' AND YEAR(o.order_date) = '2020'
GROUP BY product_name
HAVING unit >= 100