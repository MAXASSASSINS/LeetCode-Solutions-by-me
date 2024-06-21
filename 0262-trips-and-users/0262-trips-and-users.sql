# select sum(if(status like 'cancelled%',1,0))
# from
#     trips, users
# where
#     datediff(request_at, "2013-10-01") <= 2
#     and (client_id = users_id or driver_id = users_id)
#     and banned = 'No'
# group by
#     request_at


select t.request_at as day, round(sum(if(t.status like 'cancelled%',1,0))/ count(t.id),2) as 'Cancellation Rate'
from
(    
    select t1.id, t1.cb, t2.db from
        (select id, banned as cb
        from
            trips
        left join
            users
        on
            client_id = users_id) as t1
    inner join
        (select id, banned as db
        from
            trips
        left join
            users
        on
            driver_id = users_id) as t2
    on
        t1.id = t2.id
    where
        t1.cb = 'No'
        and t2.db = 'No'
) as t3
inner join
    trips as t
on
    t3.id = t.id
group by
    request_at
having
    datediff(request_at, "2013-10-01") <= 2
    and datediff(request_at, "2013-10-01") >= 0






