-- Task 1
SELECT name, country
FROM ships LEFT JOIN outcomes ON name=ship
JOIN classes ON ships.class=classes.class
WHERE outcomes.result<>'sunk' OR outcomes.result IS NULL;


-- Task 2
SELECT name, displacement, numguns
FROM classes c JOIN ships s ON s.class=c.class
WHERE displacement = (SELECT MIN(displacement)
    FROM classes) AND
      numguns = (SELECT MAX(numguns)
          FROM classes c1
          WHERE c1.class= c.class);

-- Task 3
SELECT battle
FROM outcomes o1
WHERE not exists (SELECT *
    FROM outcomes o2
    WHERE o1.battle = o2.battle and o1.ship <> o2.ship);

-- Better solution:
SELECT BATTLE, COUNT(*) AS C FROM OUTCOMES O1
GROUP BY O1.BATTLE
HAVING C=1;
# Empty set (0.00 sec)


-- Task 4
-- Б)
SELECT class, COUNT(DISTINCT name) FROM ships s
    JOIN outcomes o ON s.name=o.ship
WHERE result='sunk' AND class IN (SELECT c.class FROM classes c
    JOIN ships s ON c.class=s.class
GROUP BY c.class HAVING COUNT(name)>5)
GROUP BY class;
