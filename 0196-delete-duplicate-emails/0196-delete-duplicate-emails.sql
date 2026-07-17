# Write your MySQL query statement below
-- select email from Person group by email having count(email)=1;
delete from Person where id not in (select * from (select min(id) from Person group by email) as t);