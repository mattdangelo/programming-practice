# Write your MySQL query statement below

SELECT customer_id, COUNT(*) AS count_no_trans
FROM Visits v LEFT JOIN Transactions ON v.visit_id = Transactions.visit_id
WHERE transaction_id IS NULL
GROUP BY (customer_id)
