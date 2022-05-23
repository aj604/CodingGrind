-- My Solution to LC 197 - Rising Temperature
-- https://leetcode.com/problems/rising-temperature
--
-- Faster than 48.73%

SELECT T.id from Weather T, Weather Y
WHERE DATEDIFF(DAY, T.recordDate, Y.recordDate) = -1
AND T.temperature > Y.temperature