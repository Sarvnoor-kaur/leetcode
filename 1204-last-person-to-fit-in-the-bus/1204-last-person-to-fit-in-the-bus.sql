# Write your MySQL query statement below

select person_name from (select person_name,turn,weight,SUM(weight)over (order by turn ) as total_weight from Queue) as t where total_weight<=1000 ORDER BY turn DESC limit 1;