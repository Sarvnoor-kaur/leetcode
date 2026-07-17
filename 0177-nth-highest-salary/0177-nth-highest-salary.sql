CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    RETURN (
        -- SELECT Salary
        -- FROM (
        --     SELECT Salary,
        --            DENSE_RANK() OVER (ORDER BY Salary DESC) AS rnk
        --     FROM Employee
        -- ) AS t
        -- WHERE rnk = N
        -- LIMIT 1

        select salary from(select salary ,DENSE_RANK() over (order by salary desc) as rnk from Employee) as t where rnk=n limit 1
    );
END