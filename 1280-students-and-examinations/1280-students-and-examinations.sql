# Write your MySQL query statement below

# select 
#     e.student_id, s.student_name, e.subject_name
# from 
#     Examinations as e
# left join
#     Students as s
# on
#     s.student_id = e.student_id
# order by 
#     e.student_id, e.subject_name;





select t1.student_id, t1.student_name, t1.subject_name, COALESCE(t2.attended_exams, 0) AS attended_exams
from (
    select 
        s.student_id, s.student_name, su.subject_name
    from 
        students as s
    cross join
        subjects as su
    order by s.student_id, su.subject_name
) as t1
left join (
    select 
        student_id, subject_name, count(subject_name) as attended_exams
    from
        examinations
    group by
        student_id, subject_name
) as t2
on
    t1.student_id = t2.student_id
    and t1.subject_name = t2.subject_name
order by
    t1.student_id, t1.subject_name;
