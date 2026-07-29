# Write your MySQL query statement below
-- select distinct num as ConsecutiveNums from (select num,LAG(num) OVER (order by id) as prev,LEAD(num) OVER(order by id) as next from Logs )as t where num=prev and num=next;
SELECT DISTINCT l1.num AS ConsecutiveNums
FROM Logs l1
JOIN Logs l2
ON l1.id = l2.id - 1
JOIN Logs l3
ON l2.id = l3.id - 1
WHERE l1.num = l2.num
AND l2.num = l3.num;

-- Question 1

-- Return numbers appearing 2 consecutive times.

-- SELECT DISTINCT num
-- FROM
-- (
-- SELECT num,
-- LAG(num) OVER(ORDER BY id) prev
-- FROM Logs
-- )t
-- WHERE num=prev;


-- Question 3

-- Find rows where the current number is greater than the previous number.

-- SELECT id
-- FROM
-- (
-- SELECT *,
-- LAG(num) OVER(ORDER BY id) prev
-- FROM Logs
-- )t
-- WHERE num>prev;