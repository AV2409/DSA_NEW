# Write your MySQL query statement below
with cte1 as
(
    select 
        *,
        DENSE_RANK() over(partition by product_id order by year) as rnk
    from Sales
)
select 
    product_id,
    year as first_year,
    quantity,
    price
from cte1
where rnk=1