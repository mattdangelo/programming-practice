# Write your MySQL query statement below

SELECT IFNULL(
  (SELECT salary
  FROM Employee
  WHERE salary != (
    SELECT MAX(salary)
    FROM Employee
  )
  GROUP BY salary
  ORDER BY salary DESC
  LIMIT 1),
  NULL) AS SecondHighestSalary
