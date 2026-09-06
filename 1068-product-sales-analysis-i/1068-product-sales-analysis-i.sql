# Write your MySQL query statement below


select p.product_name,a.year,a.price from Sales a join Product p on a.product_id=p.product_id;