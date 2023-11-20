# Write your MySQL query statement below

SELECT ROUND(100 * SUM(d.order_date = d.customer_pref_delivery_date) / COUNT(*), 2) AS immediate_percentage
FROM Delivery d
WHERE (customer_id, order_date) IN (
    SELECT customer_id, MIN(order_date)
    FROM Delivery d
    GROUP BY customer_id
)
