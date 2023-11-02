-- Keep a log of any SQL queries you execute as you solve the mystery.

-- find crime scene description
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
-- info given: theft took place @ 10:15am at the Humphrey Street bakery, littering took place @ 16:36

SELECT transcript
FROM interviews
WHERE month = 7 AND day = 28;

-- find possible suspects
SELECT COUNT(name)
FROM people;
