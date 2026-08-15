# Write your MySQL query statement below
-- a person who wrote the artical is also the same person who view it so

select distinct author_id as id from Views where author_id=viewer_id order by author_id;