-- write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
SELECT name
FROM people
JOIN movies ON people.id = movies.id
WHERE movies.year = 2004
ORDER BY people.birth ASC


SELECT name
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.title = 'Toy Story';


Your query should output a table with a single column for the name of each person.
People with the same birth year may be listed in any order.
No need to worry about people who have no birth year listed, so long as those who do have a birth year are listed in order.
