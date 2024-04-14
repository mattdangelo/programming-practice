# Write your MySQL query statement below

SELECT DISTINCT l.num AS ConsecutiveNums 
FROM Logs l
LEFT JOIN Logs l1 ON l1.id = l.id - 1 AND l.num = l1.num
LEFT JOIN Logs l2 ON l2.id = l.id - 2 AND l.num = l2.num
WHERE l1.id IS NOT NULL AND l2.id IS NOT NULL
