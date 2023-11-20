# Write your MySQL query statement below

# (x + y > z)
# (y + z > x)
# (z + x > y)

SELECT x, y, z, IF(x + y > z AND y + z > x AND z + x > y, "Yes", "No") AS triangle
FROM Triangle