SELECT 
    activity_date AS day, 
    COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date BETWEEN '2019-07-28' AND DATE_ADD('2019-07-27', INTERVAL 30 DAY)
GROUP BY activity_date
ORDER BY activity_date;
