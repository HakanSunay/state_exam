-- Task 1

SELECT studioname, title, year
FROM movie m
WHERE year=(SELECT MAX(year)
    FROM MOVIE
    WHERE studioname=m.studioname);


-- Task 2

SELECT name, sum(length)
FROM movieexec JOIN movie ON producerc = cert
where cert in (SELECT distinct producerc from movie where year < 1980)
group by name


-- Task 3

SELECT starname, title, name, networth
FROM starsin JOIN movie ON movietitle=title AND movieyear=year
    JOIN (SELECT cert, networth, name
    FROM movieexec
    WHERE networth = (select max(networth) from movieexec)) t
    on t.cert = movie.producerc;

-- Task 4

-- В)
SELECT name, title, year
FROM movie JOIN movieexec ON producerc=cert
WHERE cert = ANY (SELECT producerc
FROM movie
WHERE title='Interstellar');
