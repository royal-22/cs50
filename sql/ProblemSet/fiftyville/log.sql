-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE year=2021 and month = 7 and day = 28;
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time - each of their interview transcripts mentions the bakery.

SELECT activity, hour, minute, license_plate FROM bakery_security_logs WHERE year=2021 and month = 7 and day = 28 AND (license_plate = "5P2BI95" OR license_plate = "94KL13X" OR license_plate = "6P58WS2" OR license_plate = "4328GD8" OR license_plate = "G412CB7" OR license_plate = "L93JTIZ" OR license_plate = "322W7JE");

/* 
10|16|exit|5P2BI95
10|18|exit|94KL13X
10|18|exit|6P58WS2
10|19|exit|4328GD8
10|20|exit|G412CB7
10|21|exit|L93JTIZ
10|23|exit|322W7JE
10|23|exit|0NTHK55
10|35|exit|1106N58
*/

/* 
entrance|8|18|L93JTIZ
entrance|8|23|94KL13X
entrance|8|36|322W7JE
entrance|9|14|4328GD8
entrance|9|15|5P2BI95
entrance|9|20|6P58WS2
entrance|9|28|G412CB7
exit|10|16|5P2BI95 maybe
exit|10|18|94KL13X maybe
exit|10|18|6P58WS2 maybe
exit|10|19|4328GD8 maybe -- NOT NOW
exit|10|20|G412CB7 maybe
exit|10|21|L93JTIZ maybe
exit|10|23|322W7JE maybe
*/

SELECT id, transcript FROM interviews WHERE year=2021 AND month=7 AND day=28;

/*
161|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
162|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
163|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
*/

SELECT caller, receiver, duration FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

/*
(130) 555-0289|(996) 555-8899|51
(499) 555-9472|(892) 555-8872|36
(367) 555-5533|(375) 555-8161|45
(609) 555-5876|(389) 555-5198|60
(636) 555-4198|(670) 555-8598|69
(499) 555-9472|(717) 555-1342|50
(286) 555-6063|(676) 555-6554|43
(770) 555-1861|(725) 555-3243|49
(669) 555-6918|(971) 555-6468|67
(031) 555-6622|(910) 555-3251|38
(016) 555-9166|(336) 555-0077|88
(751) 555-6567|(594) 555-6254|61
(826) 555-1652|(066) 555-9701|55
(338) 555-6650|(704) 555-2131|54
(367) 555-5533|(704) 555-5790|75
*/

SELECT name, license_plate FROM people WHERE phone_number IN(SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60);
/*
Kenny|30G67EN
Sofia|G412CB7 MAYBE
Benista|8X428L0
Taylor|1106N58
Diana|322W7JE MAYBE
Kelsey|0NTHK55
Bruce|94KL13X  MAYBE
Carina|Q12B3Z3
*/
SELECT license_plate, name FROM people WHERE phone_number IN(SELECT receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 caller = "(770) 555-1861");
-- GW362R6|Philip
SELECT phone_number FROM people WHERE name="Diana";
/*
(770) 555-1861
*/

SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street";
/*
28500762
28296815
76054385
49610011
16153065
86363979
25506511
81061156
26013199
*/

SELECT name FROM people 
JOIN bank_accounts ON people.id = bank_accounts.person_id 
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number 
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
/*
Bruce
Diana
Brooke
Kenny
Iman
Luca
Taylor
Benista
*/

SELECT city FROM airports WHERE id IN(SELECT origin_airport_id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour); 

SELECT destination_airport_id FROM flights 
JOIN passengers ON flights.id = passengers.flight_id 
JOIN people ON passengers.passport_number = people.passport_number WHERE people.license_plate = "322W7JE" AND flights.year = 2021 AND flights.month = 7 AND flights.day = 29;
-- 6

SELECT full_name, city FROM airports 
WHERE id IN (SELECT destination_airport_id FROM flights 
JOIN passengers ON flights.id = passengers.flight_id 
JOIN people ON passengers.passport_number = people.passport_number WHERE people.license_plate = "322W7JE" AND flights.year = 2021 AND flights.month = 7 AND flights.day = 29);