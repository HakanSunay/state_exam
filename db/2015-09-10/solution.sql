-- Task 1
-- Б)
SELECT * FROM (SELECT name, address FROM MOVIESTAR WHERE gender = 'F' UNION SELECT name, address FROM STUDIO) T
WHERE T.address LIKE '%Sofia%'
ORDER BY T.address;

-- Task 2
-- Г)
SELECT name, address, AVG(length) AS avgLength FROM STUDIO
LEFT JOIN MOVIE ON name = studioName
WHERE NAME NOT IN (SELECT studioName FROM MOVIE WHERE inColor = 'n' GROUP BY studioName HAVING COUNT(*) > 3)
GROUP BY name, address;