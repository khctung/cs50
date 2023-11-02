-- write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
SELECT name
FROM movie 
ORDER BY birth


Your query should output a table with a single column for the name of each person.
People with the same birth year may be listed in any order.
No need to worry about people who have no birth year listed, so long as those who do have a birth year are listed in order.
