# Write your MySQL query statement below
select *,case when x+y>z and y+z>x and x+z>y then 'Yes' else 'No' end as triangle from Triangle;




-- Question 4: Largest Side

-- Output

-- |LargestSide|

-- SELECT *,
-- GREATEST(x,y,z) AS LargestSide
-- FROM Triangle;


-- Question 5: Right Triangle

-- Example

-- 3 4 5 → Yes

-- 5 12 13 → Yes

-- 4 5 6 → No

-- Solution
-- SELECT *,
-- CASE
-- WHEN POW(GREATEST(x,y,z),2)
-- =
-- POW(x,2)+POW(y,2)+POW(z,2)
-- -
-- POW(GREATEST(x,y,z),2)

-- THEN 'Yes'

-- ELSE 'No'

-- END AS RightTriangle
-- FROM Triangle;




-- count valid triangles
-- Question 10: Count Valid Triangles

-- Output

-- 3

-- Solution

-- SELECT COUNT(*) AS ValidTriangles
-- FROM Triangle
-- WHERE
-- x+y>z
-- AND x+z>y
-- AND y+z>x;




-- Question 11: Count Invalid Triangles
-- SELECT COUNT(*) AS InvalidTriangles
-- FROM Triangle
-- WHERE
-- x+y<=z
-- OR x+z<=y
-- OR y+z<=x;




-- Question 15: Return Only the Largest Triangle
-- SELECT *
-- FROM Triangle
-- ORDER BY x+y+z DESC
-- LIMIT 1;
