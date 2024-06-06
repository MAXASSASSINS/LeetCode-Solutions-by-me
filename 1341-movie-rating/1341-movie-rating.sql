    (select u.name as results
        from
            movierating as mr
        inner join
            users as u
        on
            u.user_id = mr.user_id
        group by
            mr.user_id
        order by
            count(mr.user_id) DESC, u.name
        limit 1)
    union all
    select t1.results as results from
    (
        select m.title as results, mr.created_at, avg(mr.rating) 
        from
            MovieRating as mr
        inner join
            Movies as m
        on
            mr.movie_id = m.movie_id
        where
            datediff(mr.created_at, '2020-02-01') <= 28
            and datediff(mr.created_at, '2020-02-01') >= 0
        group by
            mr.movie_id
        order by
            avg(mr.rating) DESC , m.title ASC
        limit 1
    ) as t1



    