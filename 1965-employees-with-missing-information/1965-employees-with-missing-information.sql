# Write your MySQL query statement below

-- select employee_id from Employees where employee_id not in (select employee_id from salaries)
-- union all
-- select employee_id from salaries where employee_id not in (select employee_id from Employees)
-- order by employee_id


SELECT e.employee_id
FROM Employees e
LEFT JOIN Salaries s
ON e.employee_id = s.employee_id
WHERE s.employee_id IS NULL

UNION

SELECT s.employee_id
FROM Salaries s
LEFT JOIN Employees e
ON s.employee_id = e.employee_id
WHERE e.employee_id IS NULL

ORDER BY employee_id;


