# Write your MySQL query statement below
SELECT person_name from (SELECT person_name,turn,
sum(weight) over (order by turn) AS come FROM queue) p1
where come<=1000 order by turn DESC limit 1;