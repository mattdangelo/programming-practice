# Write your MySQL query statement below

SELECT unique_id, name
FROM Employees e LEFT JOIN EmployeeUNI ON e.id = EmployeeUNI.id