# Write your MySQL query statement below

select contest_id, round(((count(r.user_id) / (select count(distinct(user_id)) from users)) * 100), 2) as percentage
from 
    register as r
group by
    r.contest_id
order by 
    percentage DESC,
    contest_id ASC
        
