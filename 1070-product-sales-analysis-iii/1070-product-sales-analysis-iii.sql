# Write your MySQL query statement below
select 
    s.product_id, s.year as first_year, s.quantity, s.price
from
    sales as s
inner join
(    
    select 
        product_id, min(year) as min_year
    from 
        sales
    group by
        product_id
) as t1
on 
    s.year = t1.min_year
    and t1.product_id = s.product_id

