-- Keep a log of any SQL queries you execute as you solve the mystery.
-- find crime scene description
SELECT description
FROM crime_scene_reports
WHERE YEAR = 2023
AND MONTH = 7
AND DAY = 28
AND street = 'Humphrey Street';
-- info given: theft took place @ 10:15am at the Humphrey Street bakery, interviews mention work bakery

-- get transcripts that mention "bakery"
SELECT transcript
FROM interviews
WHERE YEAR = 2023
AND MONTH = 7
AND DAY = 28
AND transcript LIKE "%bakery%";
-- info given:
-- (1) within 10 mins of theft, got into car in bakery parking lot
-- (2) before theft (morning), saw thief withdrawing money from ATM on Leggett Street
-- (3) thief leaving bakery -> called someone who talked < 1 min. thief plans to take earliest flight out of fiftyville tomorrow, person on phone purchased ticket

-- storing current suspects into a table
-- suspects generated via checking (1) from transcript: bakery security log transcripts within 10 mins of theft
CREATE TABLE suspects (name TEXT NOT NULL);

INSERT INTO suspects (name)
SELECT name
FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.year = 2023
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND (bakery_security_logs.minute >= 15 OR bakery_security_logs.minute <= 25);
-- current list of suspects: Brandon, Sophia, Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey, Taylor, Denise, Thomas, Jeremy

-- suspects generated via checking (2) from transcript: withdrawing money from ATM on Legett Street -> check atm_transations
-- delete from suspect list if suspect is NOT in this list (because then no overlap w previous suspects)
DELETE FROM suspects
WHERE suspects.name NOT IN (
  SELECT name
  FROM people
  JOIN bank_accounts ON people.id = bank_accounts.person_id
  JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
  WHERE atm_transactions.year = 2023
  AND atm_transactions.month = 7
  AND atm_transactions.day = 28
  AND atm_transactions.atm_location = 'Leggett Street'
  AND atm_transactions.transaction_type = 'withdraw'
);
-- remaining list of suspects: Bruce, Luca, Iman, Diana, Taylor

-- suspects generated via checking (3) from transcript: talked on phone for < 1 min -> check duration of phone calls

DELETE FROM suspects
WHERE suspects.name NOT IN (
  SELECT name
  FROM people
  JOIN phone_calls ON phone_calls.caller = people.name
  WHERE phone_calls.year = 2023
  AND phone_calls.month = 7
  AND phone_calls.day = 28
  AND phone_calls.duration <= 1
  AND atm_transactions.transaction_type = 'withdraw'
);


SELECT * FROM suspects;

-- code to view current suspects
-- find possible suspects
SELECT
  COUNT(name)
FROM
  people;
