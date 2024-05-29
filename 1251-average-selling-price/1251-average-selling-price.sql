# Write your MySQL query statement below
select 
    p.product_id, round(COALESCE(sum(us.units*p.price) / sum(units),0), 2) as average_price
from 
    prices as p
left join
    unitssold as us
on
    p.product_id = us.product_id
    and us.purchase_date >= p.start_date
    and us.purchase_date <= p.end_date
group by 1;