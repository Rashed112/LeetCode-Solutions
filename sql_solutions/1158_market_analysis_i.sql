select u.user_id as buyer_id, u.join_date, ifnull(count(o.item_id), 0) as orders_in_2019
from users u left join orders o 
on u.user_id = o.buyer_id and year(o.order_date)='2019'
group by u.user_id
