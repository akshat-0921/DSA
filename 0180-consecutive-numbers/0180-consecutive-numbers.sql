# Write your MySQL query statement below
select distinct log1.num as ConsecutiveNums
from Logs log1, Logs log2, Logs log3
where log1.id+1=log2.id and
log2.id+1=log3.id and
log1.num=log2.num and
log2.num=log3.num