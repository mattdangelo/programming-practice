# Write your MySQL query statement below

SELECT product_name, year, price
FROM Sales s LEFT JOIN Product ON s.product_id = Product.product_id
