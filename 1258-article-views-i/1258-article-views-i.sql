# Write your MySQL query statement below
SELECT distinct(author_id) as id FROM views
where author_id = viewer_id
order by author_id ASC;