-- Write your PostgreSQL query statement below

SELECT result AS results
FROM (
    -- QRY 1 - User who has rated the greatest number of movies
    (SELECT u.name AS result, mr.user_id
     FROM MovieRating mr
     INNER JOIN Users u ON u.user_id = mr.user_id
     GROUP BY mr.user_id, u.name
     ORDER BY COUNT(movie_id) DESC, u.name
     LIMIT 1)
    UNION
    -- QRY 2 - Movie with highest avg rating in Feb 2020
    (SELECT m.title AS result, AVG(rating)
     FROM MovieRating mr
     INNER JOIN Movies m ON m.movie_id = mr.movie_id
     WHERE created_at < '2020-03-01' AND created_at >= '2020-02-01'
     GROUP BY mr.movie_id, m.title
     ORDER BY AVG(rating) DESC, m.title
     LIMIT 1)
)

