# Write your MySQL query statement below
select query_name, ROUND(avg(rating/position),2) as quality, ROUND(
        (SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*)) * 100, 
        2
    ) AS poor_query_percentage
from Queries 
group by query_name;