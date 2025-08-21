SELECT 
  ROUND(
    COUNT(DISTINCT a_next.player_id) / COUNT(DISTINCT f.player_id),
    2
  ) AS fraction
FROM (
  SELECT player_id, MIN(event_date) AS first_login
  FROM Activity
  GROUP BY player_id
) f
LEFT JOIN Activity a_next
  ON a_next.player_id = f.player_id
 AND a_next.event_date = DATE_ADD(f.first_login, INTERVAL 1 DAY);