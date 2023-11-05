-- write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
SELECT DISTINCT name
FROM people
JOIN stars ON people.id = stars.person_id  -- was told if join then don't select // fix it
WHERE movie_id IN (
  SELECT movie_id
  FROM stars
  WHERE person_id IN (
    SELECT id
    FROM people
    WHERE name = 'Kevin Bacon' AND birth = 1958
  )
) AND name != 'Kevin Bacon';
