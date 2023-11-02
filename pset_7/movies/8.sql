-- write a SQL query to list the names of all people who starred in Toy Story.
SELECT name
FROM people
JOIN movies ON ratings.movie_id = movies.id
WHERE movies.year = 2010
ORDER BY rating DESC, title ASC;

Your query should output a table with a single column for the name of each person.
You may assume that there is only one movie in the database with the title Toy Story.
