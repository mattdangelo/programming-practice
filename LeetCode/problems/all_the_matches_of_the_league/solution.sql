# Write your MySQL query statement below
SELECT home_team.team_name AS home_team, away_team.team_name AS away_team 
FROM teams AS home_team CROSS JOIN teams AS away_team
WHERE home_team.team_name <> away_team.team_name