-- Task 1
-- Б)
SELECT c.country , COUNT(o.result)
FROM classes c  JOIN ships s ON c.class=s.class
    JOIN outcomes o ON s.name=o.ship
WHERE result='sunk'
GROUP BY c.country;

-- Task 2
-- А) LGTM
-- Comma notation followed by WHERE is the same as JOIN ... ON