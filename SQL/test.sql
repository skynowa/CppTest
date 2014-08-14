SQL


// increment
UPDATE T_PERSON SET F_ADGE = F_ADGE + 10;

// show last N records
SELECT * FROM triptake.BookedBookingInfos ORDER BY id DESC LIMIT 3;

// show duplicates
SELECT COUNT(*), Code FROM triptake.AGdsHotels where gdsid=22 GROUP BY Code HAVING COUNT(*)>1
