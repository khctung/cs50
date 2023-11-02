-- write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
SELECT title
FROM movies
WHERE id IN (
  SELECT movie_id FROM stars JOIN people ON stars.person_id = people.id WHERE name = 'Bradley Cooper'
) AND id IN (
  SELECT movie_id FROM stars JOIN people ON stars.person_id = people.id WHERE name = 'Jennifer Lawrence'
);



Your query should output a table with a single column for the title of each movie.
You may assume that there is only one person in the database with the name Bradley Cooper.
You may assume that there is only one person in the database with the name Jennifer Lawrence.
