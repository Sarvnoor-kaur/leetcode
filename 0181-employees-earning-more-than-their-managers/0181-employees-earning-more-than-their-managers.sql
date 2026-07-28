# Write your MySQL query statement below
-- select name as Employee from employee e where salary >(select salary from employee where id = e.managerId);

select e.name as Employee from Employee e left join Employee m on e.managerId=m.id where e.salary>m.salary;
