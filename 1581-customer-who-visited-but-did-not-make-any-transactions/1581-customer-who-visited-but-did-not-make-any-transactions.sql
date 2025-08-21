SELECT Visits.customer_id, count(*) as count_no_trans from 
Visits left join Transactions t on Visits.visit_id=t.visit_id WHERE t.transaction_id IS NULL
group by Visits.customer_id;