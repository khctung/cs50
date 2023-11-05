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
SELECT DISTINCT name
FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.year = 2023
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND (bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <= 25); -- is b/w 15 and 25 because we're given that it's within 10 mins of theft
SELECT * FROM suspects;
-- current list of suspects: Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey

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
SELECT * FROM suspects;
-- remaining list of suspects: Bruce, Luca, Iman, Diana

-- suspects generated via checking (3) from transcript: talked on phone for < 1 min -> check duration of phone calls
-- delete from suspect list if suspect is NOT in this list (because then no overlap w previous suspects)
DELETE FROM suspects
WHERE suspects.name NOT IN (
  SELECT name
  FROM people
  JOIN phone_calls ON phone_calls.caller = people.phone_number
  WHERE phone_calls.year = 2023
  AND phone_calls.month = 7
  AND phone_calls.day = 28
  AND phone_calls.duration <= 60
);
SELECT * FROM suspects;
-- remaining list of suspects: Bruce, Diana

-- suspects generated via checking (3) from transcript: went on earliest flight out of fiftyville -> check flights + passengers
SELECT flights.id, full_name, city, flights.hour, flights.minute
FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE flights.origin_airport_id = (
  SELECT id
  FROM airports
  WHERE city = 'Fiftyville'
  AND flights.year = 2023
  AND flights.month = 7
  AND flights.day = 29
)
ORDER BY flights.hour, flights.minute
LIMIT 1;

-- now we know that earliest possible flight is at 8:20 so the thief boarded this flight and went to New York City
-- delete from suspect list if suspect is NOT in this list (because then no overlap w previous suspects)
DELETE FROM suspects
WHERE suspects.name NOT IN (
  SELECT name
  FROM people
  JOIN passengers ON passengers.passport_number = people.passport_number
  JOIN flights ON flights.id = passengers.flight_id
  JOIN airports ON airports.id = flights.origin_airport_id
  WHERE airports.city = "Fiftyville"
  AND flights.year = 2023
  AND flights.month = 7
  AND flights.day = 29
  AND flights.hour = 8
  AND flights.minute = 20
);
SELECT * FROM suspects;
-- remaining suspects: Bruce

-- Now we need to figure out the accomplice by seeing who Bruce called
SELECT receiver_name.name
FROM phone_calls
JOIN people AS caller_name ON phone_calls.caller = caller_name.phone_number
JOIN people AS receiver_name ON phone_calls.receiver = receiver_name.phone_number
WHERE caller_name.name = suspects.name
AND phone_calls.year = 2023
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration <= 60;
-- the person returned is Robin, so we know that the accomplice is robin
