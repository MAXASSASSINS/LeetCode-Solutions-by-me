# Write your MySQL query statement below
select
    case 
        when t2.minsal = t2.maxsal then null
        else
            t2.minsal
    end as SecondHighestSalary
from
(    select min(t1.salary) as minsal, max(t1.salary) as maxsal
    from
        (select distinct salary
        from
            employee
        order by salary desc
        limit 2) as t1) as t2