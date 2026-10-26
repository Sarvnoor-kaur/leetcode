# Write your MySQL query statement below
-- select max(num) as num from (select num from MyNumbers group by num having count(*)=1)as t
SELECT (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
    ORDER BY num DESC
    LIMIT 1
) AS num;


-- Outer SELECT
--      ↓
-- "What is the value returned by this inner query?"
--      ↓
-- Inner query → no value
--      ↓
-- SQL represents no value as NULL