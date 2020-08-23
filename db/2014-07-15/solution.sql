-- Task 1
-- A)
select distinct maker
from product
where product.type='PC'
and maker in (select maker
from product join laptop
on product.model=laptop.model);
# +-------+
# | maker |
# +-------+
# | B     |
# | A     |
# +-------+
# 2 rows in set (0.00 sec)

-- Task 2
-- B)
select code, l.model, screen
from laptop l
inner join product p
on l.model=p.model
where maker not in (
    select maker from product
    where type = 'Printer'
    group by maker
    having count(*) > 3
    );
# +------+-------+--------+
# | code | model | screen |
# +------+-------+--------+
# |    1 | 1298  |     11 |
# |    2 | 1321  |     12 |
# |    3 | 1750  |     14 |
# |    4 | 1298  |     15 |
# |    5 | 1752  |     14 |
# |    6 | 1298  |     12 |
# +------+-------+--------+
# 6 rows in set (0.00 sec)