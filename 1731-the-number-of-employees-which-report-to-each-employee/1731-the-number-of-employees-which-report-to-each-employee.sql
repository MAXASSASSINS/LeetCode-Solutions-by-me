# Write your MySQL query statement below
select t.employee_id, name, t.reports_count, t.average_age
from
    employees as e
right join
(    select 
        reports_to as employee_id, count(employee_id) as reports_count, round(avg(age), 0) as average_age
    from
        employees
    group by
        reports_to
    having 
        reports_to is not null
    order by
        employee_id
) as t
on
    e.employee_id = t.employee_id;
