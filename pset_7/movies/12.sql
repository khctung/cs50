-- write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
SELECT title
FROM movies
WHERE id IN (
  SELECT id
  FROM people
  WHERE name = 'Bradley Cooper'
) AND id IN (
  SELECT movie_id
  FROM stars
  JOIN people ON stars.person_id = people.id
  WHERE name = 'Jennifer Lawrence'
);

WHERE person_id IN (
  SELECT id
  FROM people
  WHERE name = 'Jennifer Lawrence'
)
-- nested selects, replace join with a nested select
