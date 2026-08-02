# Write your MySQL query statement below
with newtable as
(
    select 
        query_name,
        rating/position as quality,
        CASE 
            WHEN rating<3 THEN 1
            ELSE NULL
        END as is_poor
    from Queries
)
select 
    query_name,
    ROUND(SUM(quality)/count(query_name),2) as quality,
    ROUND((count(is_poor)/count(*))*100,2) as poor_query_percentage
from newtable 
group by query_name
