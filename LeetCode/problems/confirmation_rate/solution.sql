# Write your MySQL query statement below

SELECT s.user_id, ROUND(COUNT(IF(c.action = 'confirmed', 1, NULL)) / COUNT(*), 2) AS confirmation_rate
FROM Signups s LEFT JOIN Confirmations c ON s.user_id = c.user_id
GROUP BY user_id