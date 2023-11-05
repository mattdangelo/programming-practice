# Write your MySQL query statement below

SELECT manager.employee_id, manager.name, COUNT(*) AS reports_count, ROUND(AVG(emp.age)) AS average_age
FROM Employees manager LEFT JOIN Employees emp ON manager.employee_id = emp.reports_to
WHERE emp.employee_id IS NOT NULL
GROUP BY manager.employee_id
HAVING COUNT(*) > 0
ORDER BY manager.employee_id