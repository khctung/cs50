-- write a SQL query to list the names of all people who starred in Toy Story.
SELECT name
FROM people
JOIN stars ON movies.id = stars.movie_id
AND JOIN people ON stars.movie_id = people.id
WHERE movies.id = 'Toy Story';

Your query should output a table with a single column for the name of each person.
You may assume that there is only one movie in the database with the title Toy Story.
