# Write your MySQL query statement below


-- select u.name, COALESCE(sum(r.distance),0) as travelled_distance from Users u left join Rides r on u.id=r.user_id group by u.id,u.name order by travelled_distance desc ,u.name asc
select u.name, ifnull(sum(r.distance),0) as travelled_distance from Users u left join Rides r on u.id=r.user_id group by u.id,u.name order by travelled_distance desc ,u.name asc


-- SELECT 
--     u.name,
--     COALESCE(SUM(r.distance), 0) AS travelled_distance
-- FROM Users u
-- LEFT JOIN Rides r
-- ON u.id = r.user_id
-- GROUP BY u.id
-- ORDER BY travelled_distance DESC, u.name ASC;