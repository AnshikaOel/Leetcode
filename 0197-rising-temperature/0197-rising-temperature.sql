# Write your MySQL query statement below
select t1.id from Weather t1 inner join Weather t2 on t1.temperature>t2.temperature && DATEDIFF(t1.recordDate, t2.recordDate) = 1