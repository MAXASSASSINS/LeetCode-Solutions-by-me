# Write your MySQL query statement below
select x,y,z, if ((x + y > z and y + z > x and x + z > y) = 0, "No", "Yes") as triangle
from
    triangle