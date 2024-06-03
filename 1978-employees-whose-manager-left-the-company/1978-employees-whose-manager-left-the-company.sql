# Write your MySQL query statement below
# select t1.employee_id
# from
# (    select employee_id, manager_id
#     from
#         employees
#     where
#         manager_id is not null
#         and salary < 30000
# ) as t1
# where 
#     t1.manager_id not in (select employee_id from employees)
        
select employee_id
from
    employees
where
    manager_id is not null
    and salary < 30000
    and manager_id not in (select employee_id from employees)
order by
    employee_id