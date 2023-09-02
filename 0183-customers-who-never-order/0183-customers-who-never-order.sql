# Write your MySQL query statement below
# select name as Customers
select name as Customers from (
select customers.id, customers.name, orders.customerId
from customers left join orders on orders.customerId = customers.id) as temp
where temp.customerId is null;