/**
 * \file  Exists.sql
 * \brief EXISTS
 *
 * The EXISTS operator is used to test for the existence of any record in a *subquery*.
 *
 * The EXISTS operator returns TRUE if the subquery returns one or more records.
 */


SELECT
	column_name(s)
FROM
	table_name
WHERE
	EXISTS
	(SELECT column_name FROM table_name WHERE condition);