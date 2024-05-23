# Write your MySQL query statement below
# select v.customer_id, count(v.customer_id) from visits as v right join transactions as t on t.visit_id = v.visit_id;

# select * from visits as v left join transactions as t on t.visit_id = v.visit_id group by v.customer_id having t.transaction_id is null;

select customer_id, COUNT(*) AS count_no_trans 
from visits as v 
left join transactions as t on t.visit_id = v.visit_id 
where t.visit_id is null
group by customer_id;