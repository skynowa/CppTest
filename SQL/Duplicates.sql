/**
 * \file  Duplicates.sql
 * \brief
 */


SELECT
	count(*),
	Code
FROM
	triptake.AGdsHotels
WHERE
	GdsId = 22
GROUP BY
	Code
HAVING
	count(*) > 1
