# Write your MySQL query statement below
select p.product_name, t1.units as unit
from
    products as p
right join
(
select product_id, sum(unit) as units
from
    orders
where 
    order_date like '2020-02-__'
group by
    product_id
having 
    units >= 100
) as t1
on 
    p.product_id = t1.product_id