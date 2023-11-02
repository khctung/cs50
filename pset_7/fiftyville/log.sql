-- Keep a log of any SQL queries you execute as you solve the mystery.

-- find crime scene description
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
-- info given: theft took place @ 10:15am at the Humphrey Street bakery, littering took place @ 16:36

-- get transcripts from the date the robbery took place
SELECT transcript
FROM interviews
WHERE month = 7 AND day = 28;
-- info given:
-- (1) +/- 10 mins of theft, got into car in bakery parking lot
-- (2) before theft (morning), saw thief withdrawing money from ATM on Leggett Street
-- (3) thief leaving bakery -> called someone who talked < 1 min. thief plans to take earliest flight out of fiftyville tomorrow, person on phone purchased ticket

-- storing current suspects into a table
-- suspects generated via checking bakery security log transcripts +/- 10 mins of theft
CREATE TABLE suspects (
  name TEXT NOT NULL
);
INSERT INTO suspects (name)
VALUES (
    SELECT name
    FROM people
    JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
    WHERE month = 7 AND day = 28 AND hour = 10 AND (minute >= 5 OR minute <= 25)
);
-- current list of suspects: Brandon, Sophia, Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey, Taylor, Denise, Thomas, Jeremy

INSERT INTO suspects (name)
SELECT name
FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE month = 7 AND day = 28 AND hour = 10 AND (minute >= 5 OR minute <= 25);


-- find possible suspects
SELECT COUNT(name)
FROM people;
