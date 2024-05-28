-- Write your PostgreSQL query statement below
SELECT id, SUM(count) AS num
FROM (SELECT accepter_id AS id, COUNT(accepter_id)
      FROM RequestAccepted
      GROUP BY accepter_id
      UNION ALL
      SELECT requester_id AS id, COUNT(requester_id)
      FROM RequestAccepted
      GROUP BY requester_id) AS counts
GROUP BY id
ORDER BY num DESC
LIMIT 1
