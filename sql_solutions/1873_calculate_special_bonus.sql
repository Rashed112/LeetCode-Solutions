#solution-1

select employee_id, salary*(employee_id%2)*(name not like 'M%') as bonus
from employees
order by employee_id;

#solution-2

select employee_id, if(employee_id%2 != 0 and name not like 'M%', salary, 0) as bonus
from employees
order by employee_id;
