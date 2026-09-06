# Write your MySQL query statement below
-- select name as Employee from employee e where salary >(select salary from employee where id = e.managerId);

-- select e.name as Employee from Employee e left join Employee m on e.managerId=m.id where e.salary>m.salary;
-- select e.name as Employee from Employee e join Employee m on e.managerId=m.id where e.salary>m.salary;
select e.name as Employee from Employee e left join Employee m on e.managerId=m.id where e.salary>m.salary;

-- Question 8: Employee Earns Less Than Manager
-- Solution
-- SELECT e1.name
-- FROM Employee e1
-- JOIN Employee e2
-- ON e1.managerId=e2.id
-- WHERE e1.salary<e2.salary;



-- Question 9: Manager and Employee Salary Difference

-- Return

-- |Employee|Manager|Difference|

-- Solution
-- SELECT
-- e1.name,
-- e2.name,
-- e2.salary-e1.salary AS Difference
-- FROM Employee e1
-- JOIN Employee e2
-- ON e1.managerId=e2.id;



