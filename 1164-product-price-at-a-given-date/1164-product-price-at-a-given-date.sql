# Write your MySQL query statement below

select p.product_id, p.new_price as price
from
    products as p,
    (
    select 
        product_id, max(change_date) as max_change_date
    from
        products
    where 
        datediff('2019-08-16', change_date) >= 0
    group by
        product_id
    ) as t1
where
    p.product_id = t1.product_id
    and p.change_date = t1.max_change_date
union all
    select 
        product_id, 10 as price
    from
        products
    group by
        product_id
    having
        min(change_date) > '2019-08-16'
        
