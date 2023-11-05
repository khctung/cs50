-- write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
SELECT title
FROM movies
WHERE id IN (
  SELECT movie_id
  FROM stars
  WHERE people.id = stars.person_id
  AND stars.movie_id = movies.id
  AND people.name = 'Bradley Cooper';
) AND id IN (
  SELECT movie_id
  FROM stars
  WHERE people.id = stars.person_id
  AND stars.movie_id = movies.id
  AND people.name = 'Jennifer Lawrence';
);
