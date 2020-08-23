-- Task 1
-- A)

SELECT t.name, title
FROM movie m JOIN (SELECT name, cert
    FROM movieexec
    WHERE cert IN (SELECT producerc
                    FROM movie
                    WHERE title='Pretty Woman')) t
    ON m.producerc=t.cert;


-- Task 2
-- Г)

select STUDIONAME, STARNAME, COUNT(*) from MOVIE M
join STARSIN S on M.TITLE = S.MOVIETITLE and M.YEAR = S.MOVIEYEAR
group by STUDIONAME, STARNAME
having COUNT(*) >= ALL(select COUNT(*) from MOVIE, STARSIN
                       where TITLE = MOVIETITLE and YEAR = MOVIEYEAR and STUDIONAME = M.STUDIONAME group by STUDIONAME, STARNAME);