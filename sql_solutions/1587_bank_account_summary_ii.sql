select u.name, sum(t.amount) as balance
from users u left join transactions t on u.account = t.account
group by u.account
having balance>10000;
