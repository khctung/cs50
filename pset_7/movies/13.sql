-- write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.

SELECT DISTINCT name
FROM people
JOIN directors ON people.id = directors.person_id
JOIN movies ON directors.movie_id = movies.id
JOIN ratings ON movies.id = ratings.movie_id
WHERE ratings.rating >= 9.0;

SELECT title
FROM movies
WHERE id IN (
  SELECT movie_id
  FROM stars
  JOIN people
  ON stars.person_id = people.id
  WHERE name = 'Bradley Cooper'
) AND id IN (
  SELECT movie_id
  FROM stars
  JOIN people
  ON stars.person_id = people.id
  WHERE name = 'Jennifer Lawrence'
);






Your query should output a table with a single column for the name of each person.
There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
Kevin Bacon himself should not be included in the resulting list.
