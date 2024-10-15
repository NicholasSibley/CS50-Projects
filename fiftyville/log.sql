-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Learning more about the actual theft

SELECT description
    FROM crime_scene_reports
        WHERE month = 7
        AND day = 28
        AND street = 'Humphrey Street';

-- Theft took place at 10:15 am at the bakery.  Interviews were
-- conducted with three witnesses.  Each one mentions the bakery.


-- Access interview logs.

SELECT transcript
    FROM interviews
        WHERE month = 7
        AND day = 28
        AND year = 2023;

-- Clue 1
-- Transcript claims thief entered a car in the bakery parking lot
-- and drive away within 10 minutes of the theft.  Recommend searching
-- security footage.

-- Clue 2
-- Transcript claims the thief was someone they recognized.  On the
-- morning of the theft, but prior to the theft interviewee claims
-- they saw the thief by the ATM on Leggett Street withdrawing money.

-- Clue 3
-- Transcript claims the thief called and spoke with someone for less
-- than a minute after committing the theft, but prior to leaving.
-- Interviewee claims they heard the thief say that they were planning
-- to take the earliest flight out of town on the 29th.  The thief
-- then asked the person on the other end of the phone to purchase a
-- ticket.


-- Address Clue 1
SELECT DISTINCT(people.name), people.license_plate
    FROM people
        JOIN bakery_security_logs
        ON people.license_plate = bakery_security_logs.license_plate
        WHERE people.license_plate IN (

            SELECT license_plate
                FROM bakery_security_logs
                    WHERE year = 2023
                    AND month = 7
                    AND day = 28
                    AND hour = 10
                    AND minute
                    BETWEEN 16 AND 26);

-- Suspect fled the scene in a vehicle with one of the following license
-- plate numbers.  The license plate number is associated with the adjoining
-- name.
--   NAME   | LICENSE_PLATE |
--+---------+---------------+
--| Vanessa | 5P2BI95       |
--| Barry   | 6P58WS2       |
--| Iman    | L93JTIZ       |
--| Sofia   | G412CB7       |
--| Luca    | 4328GD8       |
--| Diana   | 322W7JE       |
--| Kelsey  | 0NTHK55       |
--| Bruce   | 94KL13X       |


-- Address Clue 2
SELECT amount, account_number
    FROM atm_transactions
        WHERE year = 2023
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street';

-- Suspect withdrew one of these amounts from one of these account numbers from
-- the atm on Leggett Street the morning of the robbery:
-- AMOUNT | ACCOUNT_NUMBER |
--+--------+----------------+
--| 48     | 28500762       |
--| 20     | 28296815       |
--| 60     | 76054385       |
--| 50     | 49610011       |
--| 80     | 16153065       |
--| 10     | 86363979       |
--| 20     | 25506511       |
--| 30     | 81061156       |
--| 35     | 26013199       |


-- Address Clue 3
SELECT * FROM flights
    WHERE year = 2023
        AND month = 7
        AND day = 29
        ORDER BY hour, minute;

SELECT city
    FROM airports
    JOIN flights
    ON airports.id = flights.destination_airport_id
    WHERE airports.id = 4;

-- Suspect departed town aboard flight 36 at 8:20 am on 07/29/2023 bound
-- for New York City.


-- Associate bank account numbers with suspect names

SELECT name
FROM (
SELECT people.name
    FROM people
        JOIN bank_accounts
        ON people.id = bank_accounts.person_id
        WHERE account_number IN (

            SELECT account_number
                FROM atm_transactions
                    WHERE year = 2023
                    AND month = 7
                    AND day = 28
                    AND atm_location = 'Leggett Street'
)
)
INTERSECT
SELECT name
    FROM (
        SELECT people.name
            FROM people
            JOIN bakery_security_logs
            ON people.license_plate = bakery_security_logs.license_plate
            WHERE year = 2023
            AND month = 7
            AND day = 28
            AND minute BETWEEN 16 AND 26
    );

-- The following suspects drive a vehicle from the suspected license plate pool and also
-- possess a bank account that withdrew money from the suspected atm at the suspected time.
-- Suspect must be one of these four people.
--| name  |
--+-------+
--| Bruce |
--| Diana |
--| Iman  |
--| Luca  |


-- Cross reference suspect names with passengers on flight 36.

SELECT DISTINCT(people.name)
    FROM people
    JOIN passengers
    ON people. passport_number = passengers.passport_number
        JOIN flights
        ON passengers.flight_id = flights.id
        WHERE flights.id = 36
        AND (
        people.name = 'Bruce'
        OR people.name = 'Diana'
        OR people.name = 'Iman'
        OR people.name = 'Luca'
        );

-- Suspects narrowed down to the following two people:
-- Bruce
-- Luca


-- Find caller from Clue 3.

SELECT people.name, phone_calls.receiver
    FROM people
        JOIN phone_calls
        ON people.phone_number = phone_calls.caller
            WHERE year = 2023
            AND month = 7
            AND day = 28
            AND duration < 60;

-- Perpetrator must be Buce.  He called (375) 555-8161.


-- Find accomplice.  Accomplice must be the person Bruce called.

SELECT people.name
    FROM people
        WHERE phone_number = '(375) 555-8161';

-- Accomplice is Robin.
