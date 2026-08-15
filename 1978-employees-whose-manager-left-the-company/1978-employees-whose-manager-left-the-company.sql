# Write your MySQL query statement below

select e.employee_id from Employees e left join Employees m on e.manager_id=m.employee_id where e.salary <30000 and m.employee_id is null  AND e.manager_id IS NOT NULL order by e.employee_id