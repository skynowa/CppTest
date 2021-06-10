/**
 * \file  LastRecords.sql
 * \brief
 */


SELECT
	*
FROM
	triptake.BookedBookingInfos
ORDER BY
	ID DESC
LIMIT 3;
