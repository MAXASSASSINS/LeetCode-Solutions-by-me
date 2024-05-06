# Write your MySQL query statement below
select e.name, uni.unique_id from employees as e left join EmployeeUNI as uni on e.id = uni.id;