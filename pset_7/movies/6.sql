-- write a SQL query to determine the average rating of all movies released in 2012.
SELECT AVG(rating)
from ratings
WHERE movie_id
IN (SELECT id FROM movies WHERE year = 2012);

SELECT title FROM shows WHERE id IN
 (SELECT show_id FROM stars WHERE person_id =
  (SELECT id FROM people WHERE name = 'Steve Carell'));


Your query should output a table with a single column and a single row (not counting the header) containing the average rating.
