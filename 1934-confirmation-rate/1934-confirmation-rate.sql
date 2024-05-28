
# select 
#     s.user_id
# from
#     signups as s
# left join
# ( 
# )


select 
    s.user_id, round(COALESCE(t3.confirmedCnt/t3.total, 0),2) as confirmation_rate 
from
    signups as s
left join
(
    select 
        t1.user_id, t1.total, t2.confirmedCnt 
    from (
        select 
            user_id, count(user_id) as total
        from 
            confirmations
        group by
            user_id
        ) as t1
    inner join
    (
        select 
            user_id, count(action) as confirmedCnt
        from 
            confirmations
        group by 
            user_id, action
        having 
            action = 'confirmed'
    ) as t2
    on 
        t1.user_id = t2.user_id
) as t3
on 
    s.user_id = t3.user_id

 