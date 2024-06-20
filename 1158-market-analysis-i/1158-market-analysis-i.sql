select 
    user_id as buyer_id, join_date, 
    case 
        when t1.cnt is null then 0
        else t1.cnt
    end as orders_in_2019
from
    users
left join
    (
        select 
            buyer_id, count(order_id) as cnt
        from 
            orders 
        where 
            order_date like '2019-%' 
        group by buyer_id
    ) as t1
on
    user_id = buyer_id