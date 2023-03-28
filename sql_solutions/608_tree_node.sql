select id, 'Root' as type from tree
where p_id is null
union
select id, 'Inner' as type from tree
where p_id is not null and id in (select distinct p_id from tree where p_id is not null)
union
select id, 'Leaf' as type from tree
where p_id is not null and id not in (select distinct p_id from tree where p_id is not null)
order by id; 
