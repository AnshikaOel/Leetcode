# Write your MySQL query statement below
select a1.player_id ,min(a1.event_date) as first_login from Activity a1 join Activity a2 on a1.player_id=a2.player_id group by a1.player_id