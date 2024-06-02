-- Write your PostgreSQL query statement below

SELECT ROUND(COUNT(nd.player_id)::NUMERIC / COUNT(el.player_id)::NUMERIC, 2) AS fraction 
FROM (SELECT DISTINCT ON(player_id) player_id, event_date
      FROM Activity
      ORDER BY player_id, event_date) AS el
LEFT JOIN Activity nd ON el.player_id = nd.player_id AND el.event_date + 1 = nd.event_date
