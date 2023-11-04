# Write your MySQL query statement below

SELECT second_day.id
FROM Weather first_day JOIN Weather second_day ON DATE_ADD(first_day.recordDate, INTERVAL 1 DAY) = second_day.recordDate
WHERE second_day.temperature > first_day.temperature
