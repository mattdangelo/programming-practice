# Write your MySQL query statement below

SELECT employee_id, department_id AS department_id
FROM Employee e
WHERE primary_flag = 'Y'
GROUP BY employee_id
UNION
SELECT employee_id, department_id AS department_id
FROM Employee e
GROUP BY employee_id
HAVING count(employee_id) = 1