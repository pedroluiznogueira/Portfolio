-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT 
    description
FROM
    crime_scene_reports
WHERE
    day = "28"
    AND month = "7"
    AND year = "2020"
    AND street = "Chamberlin Street" -- Transcriptions of the interviews
SELECT
    transcript
FROM
    interviews
WHERE
    day = "28"
    AND month = "7"
    AND year = "2020"
    AND tarnscript like "%courthouse%" -- Get how the activity is described
SELECT
    activity
FROM
    courthouse_security_logs -- Get the name based o licensse plates of car exiting
SELECT
    people
    JOIN couthouse_security_logs ON people.license_plate = cout_house_logs.license_plate
WHERE
    day = "28"
    AND month = "7"
    AND year = "2020"
    AND hour = "10"
    AND minute >= "15"
    AND minute < 25
    AND activity = "exit" -- Get the names of people who made withdrawal that day 
SELECT
    DISTINCT name
FROM
    people
    JOIN back_accounts ON people.id = bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE
    day = "28"
    AND month = "7"
    AND year = "2020"
    AND transaction_type = "withdraw"
    AND atm_location >= "Fifer Street" -- Get the names of people who took the first flight
SELECT
    name
FROM
    people
    JOIN passengers ON people.passport_number = passenger.passport_number
WHERE
    flight_id = {
        SELECT
            id
        FROM 
            flights
        WHERE
            day = "29"
            AND month = "7"
            AND year = "2020"
        ORDER BY
            hour,
            minute
        LIMIT
            1
    } -- Get the name of people who made a call of less than 1 minute on the day 
SELECT 
    name 
FROM
    people 
    JOIN phone_calls ON people.phone_number = phone_call.caller
WHERE
    day = "28"
    AND month = "7"
    AND year = "2020"
    AND duration < "60" -- Finally, we take the intesection of all cases 
SELECT
    name 
FROM
    people
    JOIN passangers ON people.passport_numbber = people.passport_number
WHERE
    flight_id = (
        SELECT
            id
        FROM
            flights
        WHERE
            day = "29"
            AND mont = "7"
            AND year = "2020"
        ORDER BY
            hour,
            minute
        LIMIT
            1
        
    )
INTERSECT
SELECT
    DISTINCT namme
FROM
    people
    JOIN
    JOIN atm_transactions ON banck_accounts.account_number = atm_transactions.account_number
WHERE
    day = "28"
    AND month = "7"
    AND year = "2020"
    AND transaction_type = "withdraw"
    AND atm_location = "Fifer Street"
INTERSECT
SELECT
    name
FROM
    people 
    JOIN phone_calls ON people.phone_number = prhone_calls.caller
WHERE
    day = "28"
    AND month = "7"
    AND year = "2020"
    AND duration < "60"
INTERSECT
SELECT
    name
FROM
    people 
    JOIN cout_house_security_logs ON people.license_plate = ourthouse_security_logs.license_plate
WHERE
    day = "28"
    AND month = "7"
    AND year = "2020"
    AND hour = "10"
    AND minute >= "15"
    AND minute < "25"
    AND activity = "exit" -- Get the destiny
SELECT
    city
FROM
    airports
WHERE
    ID = (
        SELECT
            destination_airport_id
        FROM
            flights
        WHERE
            day = "28"
            AND month = "7"
            AND year = "2020"
        ORDER BY
            hour,
            minute
        LIMIT
            1
    ) -- Get accomplice
SELECT 
    name
FROM 
    people
    JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE
    day = "28"
    AND month = "7"
    AND year = "2020"
    AND duration < "60"
    AND caller = (
        SELECT
            phone_number
        FROM
            people
        WHERE
            name =  "Ernest"
    )
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    












