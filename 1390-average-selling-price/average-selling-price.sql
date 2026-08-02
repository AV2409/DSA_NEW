with newtable as
(
    select 
        p.product_id,p.price,
        COALESCE(u.units,0) as units
    from Prices p
    LEFT JOIN UnitsSold u
    on p.product_id=u.product_id and u.purchase_date between p.start_date and p.end_date
)
select 
    product_id,COALESCE(ROUND(SUM(price*units)/SUM(units),2),0) as average_price
from newtable
group by product_id
