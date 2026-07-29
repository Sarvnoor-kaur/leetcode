-- select id from (select id,recordDate,temperature,LAG(temperature) OVER(ORDER BY recordDate) as prev,LAG(recordDate) OVER(ORDER BY recordDate) as prevdate from Weather) as t where temperature >prev and DATEDIFF(recordDate,prevdate)=1; 

select w1.id from Weather w1 join Weather w2 on DATEDIFF(w1.recordDate,w2.recordDate)=1 where w1.temperature > w2.temperature 



-- we can do it using self join also