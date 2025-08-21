# Write your MySQL query statement below
select s.user_id, count(s.follower_id) as followers_count from Followers s 
group by user_id