# Write your MySQL query statement below

with cte1 as(
    select 
        *
    from Products
    where change_date<="2019-08-16"
),
cte2 as(
    select 
        *,
        ROW_NUMBER() OVER(partition by product_id order by change_date desc) as rnk
    from cte1
)
-- select * from cte2
select 
    product_id,
    new_price as price
from cte2
where rnk=1

UNION

SELECT 
    product_id,
    10 AS price
FROM Products
WHERE product_id NOT IN (
    SELECT product_id
    FROM cte1
);
