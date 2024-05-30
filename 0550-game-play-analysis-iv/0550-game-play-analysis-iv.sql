# Write your MySQL query statement below

select 
    round(sum(datediff(a.event_date, t1.min_event_date) = 1) / count(distinct a.player_id),2)
    as fraction
from
    activity as a
inner join (
    select 
        player_id, event_date, min(event_date) as min_event_date
    from
        activity
    group by
        player_id
) as t1
on
    a.player_id = t1.player_id
    