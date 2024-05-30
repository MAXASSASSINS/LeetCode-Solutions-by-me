SELECT 
    ROUND(SUM(d.customer_pref_delivery_date = t1.min_order_date) * 100 / COUNT(t1.customer_id), 2) AS immediate_percentage
FROM (
    SELECT 
        customer_id, 
        MIN(order_date) AS min_order_date
    FROM 
        delivery
    GROUP BY 
        customer_id
) AS t1
INNER JOIN
    delivery AS d
ON 
    t1.customer_id = d.customer_id
AND 
    t1.min_order_date = d.order_date;


