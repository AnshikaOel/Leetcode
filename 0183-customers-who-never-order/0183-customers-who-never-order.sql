# Write your MySQL query statement below
# select c.name as Customers from Customers c inner join Orders o on where c.id not in (se) 
select name as Customers from Customers where id not in (
select customerId from Orders)