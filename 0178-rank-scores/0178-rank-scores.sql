# Write your MySQL query statement below
select s.score as score, t.rank as 'rank'
from    
    scores as s,
    (        
        select s2.score, sum(if(s2.score <= s3.score,1,0)) as `rank`
        from
            (select distinct score from scores) as s2,
            (select distinct score from scores) as s3
        group by s2.score
        order by s2.score desc
    ) as t
where
    s.score = t.score
order by
    s.score desc
