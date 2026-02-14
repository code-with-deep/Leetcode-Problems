# Write your MySQL query statement below
select e1.name
from Employee e1
join Employee e2
On e1.id=e2.managerId
group by e1.name,e1.id
having count(*)>=5;
