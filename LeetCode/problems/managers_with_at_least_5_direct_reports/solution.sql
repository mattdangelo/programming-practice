# Write your MySQL query statement below
SELECT m.name
FROM Employee m LEFT JOIN Employee e ON e.managerId = m.id
GROUP BY m.id
HAVING COUNT(*) >= 5