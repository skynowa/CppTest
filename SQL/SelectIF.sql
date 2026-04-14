/**
 * \file  SelectIF.sql
 * \brief Select columns with IF (using aliases)
 */

SELECT
    ID,
    ConfNum,
    IF (BookingAccount = 1, 'BookedNet', 'Tripnet') AS BookingAccount,
    IF (ID >= 17361120, 'v3', 'v2') AS Version
FROM triptake.BookedBcomBookings;
