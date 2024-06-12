# Write your MySQL query statement below


select d.name as department,e.name as employee, t.maxsal as salary
from
    employee as e,
    (    
        select departmentid, max(salary) as maxsal
        from
            employee
        group by
            departmentid
    ) as t,
    department as d
where
    e.departmentId = t.departmentid
    and e.departmentId = d.id
    and e.salary = t.maxsal

