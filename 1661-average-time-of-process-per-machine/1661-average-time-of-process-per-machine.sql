# Write your MySQL query statement below

select machine_id, round(avg(duration), 3) as processing_time  from (
    select 
        a1.machine_id, a1.timestamp as start, a2.timestamp as end, a2.timestamp - a1.timestamp as duration
    from 
        activity as a1 
    inner join 
        activity as a2 
    on 
        a1.machine_id = a2.machine_id 
        and a1.process_id = a2.process_id 
        and a1.activity_type = 'start' 
        and a2.activity_type = 'end'
) as a3 group by machine_id;
    