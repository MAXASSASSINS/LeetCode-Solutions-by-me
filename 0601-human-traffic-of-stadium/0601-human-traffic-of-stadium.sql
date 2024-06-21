select * from
(
    (select c.id, c.visit_date, c.people
    from
        stadium a,
        stadium b,
        stadium c
    where
        a.id = b.id + 1
        and a.id = c.id + 2
        and a.id = any (select id from stadium)
        and b.id = any (select id from stadium)
        and c.id = any (select id from stadium)
        and a.people >= 100
        and b.people >= 100 
        and c.people >= 100)
union
(    select a.id, a.visit_date, a.people
    from
        stadium a,
        stadium b,
        stadium c
    where
        a.id = b.id + 1
        and a.id = c.id + 2
        and a.id = any (select id from stadium)
        and b.id = any (select id from stadium)
        and c.id = any (select id from stadium)
        and a.people >= 100
        and b.people >= 100 
        and c.people >= 100)
union
(    select b.id, b.visit_date, b.people
    from
        stadium a,
        stadium b,
        stadium c
    where
        a.id = b.id + 1
        and a.id = c.id + 2
        and a.id = any (select id from stadium)
        and b.id = any (select id from stadium)
        and c.id = any (select id from stadium)
        and a.people >= 100
        and b.people >= 100 
        and c.people >= 100)
) as t1
order by 
    t1.visit_date