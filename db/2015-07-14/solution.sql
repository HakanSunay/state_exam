-- Task 1
-- Г)
SELECT starName
FROM STARSIN
JOIN MOVIE ON movieTitle = title AND movieYear = year
WHERE starName NOT LIKE '%a' AND inColor = 'y'
INTERSECT
SELECT starName FROM STARSIN
JOIN MOVIE ON movieTitle = title AND movieYear = year
WHERE inColor = 'n';

-- Task 2
-- Б)
SELECT name, YEAR(birthdate), COUNT(DISTINCT studioName) FROM MOVIESTAR
LEFT OUTER JOIN STARSIN ON name = starname
LEFT JOIN MOVIE ON movieTitle = title AND movieYear = year
GROUP BY name
HAVING COUNT(title) <= 5;