# Write your MySQL query statement below

SELECT * From Users
WHERE regexp_like(mail, '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$')