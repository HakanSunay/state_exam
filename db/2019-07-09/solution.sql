-- Task 1
-- NORMAL JOIN TO GET ONLY THOSE STUDIOS THAT HAVE MOVIE RECORDS
-- GROUPING BY STUDIO NAME AND FILTERING ON CNT < 2
SELECT S.NAME, COUNT(M.TITLE) as CNT FROM STUDIO S
JOIN MOVIE M ON S.NAME = M.STUDIONAME
GROUP BY S.NAME
HAVING CNT < 2;
# +------+-----+
# | NAME | CNT |
# +------+-----+
# | Fox  |   1 |
# +------+-----+
# 1 row in set (0.00 sec)

-- Task 2
SELECT NAME FROM MOVIEEXEC
WHERE NETWORTH IN (SELECT MIN(NETWORTH) FROM MOVIEEXEC);

# I manually added 2 records with same network - 9
# +---------------+
# | NAME          |
# +---------------+
# | Hidaet Yusein |
# | Hakan Halil   |
# +---------------+
# 2 rows in set (0.00 sec)