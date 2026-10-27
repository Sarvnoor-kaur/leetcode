# Write your MySQL query statement below
(select u.name as results from Users u join MovieRating mo on u.user_id=mo.user_id join Movies m on mo.movie_id=m.movie_id group by u.user_id,u.name order by count(*) desc ,u.name asc limit 1)

UNION ALL

(select m.title as results from Movies m join MovieRating mo on m.movie_id = mo.movie_id where  mo.created_at >= '2020-02-01' and mo.created_at<'2020-03-01' group by mo.movie_id,m.title  order by avg(mo.rating) desc,m.title asc limit 1)