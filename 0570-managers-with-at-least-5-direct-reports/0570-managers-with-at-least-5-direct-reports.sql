# Write your MySQL query statement below


select e.name from 
    employee as e
inner join
(
    select 
        e.managerId, count(e.managerId) as cnt
    from
        employee as e
    group by
        e.managerId
) as t1
on
    e.id = t1.managerId
    and t1.cnt >= 5
    

    
