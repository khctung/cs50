-- Keep a log of any SQL queries you execute as you solve the mystery.

-- find crime scene description
SELECT description
FROM crime_scene_reports
WHERE year = 2023
AND month = 7
AND day = 28
AND street = 'Humphrey Street';
-- info given: theft took place @ 10:15am at the Humphrey Street bakery, interviews mention work bakery

-- get transcripts that mention "bakery"
SELECT transcript
FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28
AND transcript
LIKE "%bakery%";
-- info given:
-- (1) within 10 mins of theft, got into car in bakery parking lot
-- (2) before theft (morning), saw thief withdrawing money from ATM on Leggett Street
-- (3) thief leaving bakery -> called someone who talked < 1 min. thief plans to take earliest flight out of fiftyville tomorrow, person on phone purchased ticket

-- storing current suspects into a table
-- suspects generated via checking (1) from transcript: bakery security log transcripts within 10 mins of theft
CREATE TABLE suspects (
  suspect_name TEXT NOT NULL
);
INSERT INTO suspects (suspect_name)
VALUES (
    SELECT name
    FROM people
    JOIN bakery_security_logs
    ON bakery_security_logs.license_plate = people.license_plate
    WHERE bakery_security_logs.month = 7
    AND bakery_security_logs.day = 28
    AND bakery_security_logs.hour = 10
    AND (bakery_security_logs.minute >= 15 OR bakery_security_logs.minute <= 25)
);
-- current list of suspects: Brandon, Sophia, Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey, Taylor, Denise, Thomas, Jeremy

-- suspects generated via checking (2) from transcript: withdrawing money from ATM on Legett Street -> check atm_transations
INSERT INTO suspects (name)
VALUES (
    SELECT name
    FROM people
    JOIN bank_accounts ON bank_accounts.person_id = people.id
    JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
    WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
);

-- Finding the names associated with the corresponding account numbers. Putting these names in the 'Suspect List'
SELECT name, atm_transactions.amount
  FROM people
  JOIN bank_accounts
    ON people.id = bank_accounts.person_id
  JOIN atm_transactions
    ON bank_accounts.account_number = atm_transactions.account_number
 WHERE atm_transactions.year = 2021
   AND atm_transactions.month = 7
   AND atm_transactions.day = 28
   AND atm_transactions.atm_location = 'Leggett Street'
   AND atm_transactions.transaction_type = 'withdraw';



SELECT * FROM suspects;
-- code to view current suspects



-- find possible suspects
SELECT COUNT(name)
FROM people;
