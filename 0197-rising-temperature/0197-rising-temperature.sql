-- select id from (select id,recordDate,temperature,LAG(temperature) OVER(ORDER BY recordDate) as prev,LAG(recordDate) OVER(ORDER BY recordDate) as prevdate from Weather) as t where temperature >prev and DATEDIFF(recordDate,prevdate)=1; 

select w1.id from Weather w1 join Weather w2 on DATEDIFF(w1.recordDate,w2.recordDate)=1 where w1.temperature > w2.temperature 



-- we can do it using self join also
-- Question 2: Falling Temperature

-- Return the ids where today's temperature is lower than yesterday's.

-- Solution
-- SELECT w1.id
-- FROM Weather w1
-- JOIN Weather w2
-- ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
-- WHERE w1.temperature < w2.temperature;

-- Question 3: Same Temperature

-- Return all dates where today's temperature is exactly the same as yesterday's.

-- Solution
-- SELECT w1.recordDate
-- FROM Weather w1
-- JOIN Weather w2
-- ON DATEDIFF(w1.recordDate, w2.recordDate)=1
-- WHERE w1.temperature = w2.temperature;

-- Question 4: Temperature Increased by More Than 5 Degrees

-- Return the ids.

-- Solution
-- SELECT w1.id
-- FROM Weather w1
-- JOIN Weather w2
-- ON DATEDIFF(w1.recordDate,w2.recordDate)=1
-- WHERE w1.temperature - w2.temperature > 5;


-- Question 5: Largest Increase

-- Return the day having the maximum increase.

-- Solution
-- SELECT
-- w1.id,
-- (w1.temperature-w2.temperature) AS IncreaseTemp
-- FROM Weather w1
-- JOIN Weather w2
-- ON DATEDIFF(w1.recordDate,w2.recordDate)=1
-- ORDER BY IncreaseTemp DESC
-- LIMIT 1;



-- Question 6: Difference Between Two Consecutive Days

-- Return

-- | id | Difference |

-- Solution
-- SELECT
-- w1.id,
-- ABS(w1.temperature-w2.temperature) AS Difference
-- FROM Weather w1
-- JOIN Weather w2
-- ON DATEDIFF(w1.recordDate,w2.recordDate)=1;