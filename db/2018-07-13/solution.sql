-- Task 1
SELECT S.NAME,
       MIN(M.YEAR) AS FIRST_MOVIE,
       MAX(M.YEAR) AS LAST_MOVIE,
       COUNT(*) AS ALL_MOVIES
FROM STUDIO S
JOIN MOVIE M ON S.NAME=M.STUDIONAME
WHERE S.NAME LIKE 'M%'
GROUP BY S.NAME;
# +------+-------------+------------+------------+
# | NAME | FIRST_MOVIE | LAST_MOVIE | ALL_MOVIES |
# +------+-------------+------------+------------+
# | MGM  |        1938 |       1995 |          3 |
# +------+-------------+------------+------------+
# 1 row in set (0.00 sec)

-- Task 2
SELECT SS.STARNAME,
       COUNT(*) as ALL_MOVIES
FROM STARSIN SS
JOIN MOVIESTAR MS ON SS.STARNAME=MS.NAME
WHERE MS.GENDER='M'
GROUP BY SS.STARNAME
ORDER BY ALL_MOVIES DESC LIMIT 1;
# +----------------+------------+
# | starname       | ALL_MOVIES |
# +----------------+------------+
# | Sandra Bullock |          1 |
# +----------------+------------+
# 1 row in set (0.00 sec)