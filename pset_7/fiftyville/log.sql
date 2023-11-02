-- Keep a log of any SQL queries you execute as you solve the mystery.

-- find crime scene description
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
-- info given: theft took place @ 10:15am at the Humphrey Street bakery, littering took place @ 16:36

-- get transcripts from the date the robbery took place
SELECT transcript
FROM interviews
WHERE month = 7 AND (day = 28 or day = 29);
-- info given:
-- (1) +/- 10 mins of theft, got into car in bakery parking lot
-- (2) before theft (morning), saw thief withdrawing money from ATM on Leggett Street
-- (3) thief leaving bakery -> called someone who talked < 1 min. thief plans to take earliest flight out of fiftyville tomorrow, person on phone purchased ticket

Our neighboring courthouse has a very annoying rooster that crows loudly at 6am every day. My sons Robert and Patrick took the rooster to a city far, far away, so it may never bother us again. My sons have successfully arrived in Paris.

-- find possible suspects
SELECT COUNT(name)
FROM people;
