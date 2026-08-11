# Write your MySQL query statement below
select emp.unique_id, e.name
from EmployeeUNI emp
right join Employees e
on 
emp.id = e.id 