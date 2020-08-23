-- Task 1
-- Б)
select distinct ships.name
from battles, ships
where launched=year(date); -- join with a special clause
# +----------------+
# | name           |
# +----------------+
# | Hood           |
# | Iowa           |
# | King George V  |
# | Missouri       |
# | Musashi        |
# | New Jersey     |
# | North Carolina |
# | South Dakota   |
# | Washington     |
# | West Virginia  |
# | Wisconsin      |
# | Yamato         |
# +----------------+
# 12 rows in set (0.00 sec)

-- Task 2

-- Д) принцип на изключването
select distinct country,
(select count(*) from classes c2 join ships s on c2.class=s.class
join outcomes o on s.name=o.ship
where c2.country=c.country and result='sunk') from classes c
where(select count(*) from classes c2
join ships s on c2.class=s.class
where c2.country=c.country)<=3;