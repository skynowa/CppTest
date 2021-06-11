/**
 * \file  Having.sql
 * \brief HAVING
 *
 * HAVING clause was added to SQL because the WHERE keyword cannot be used with aggregate functions
 */


SELECT
	column_name(s)
FROM
	table_name
WHERE
	condition
GROUP BY
	column_name(s)
HAVING
	condition
ORDER BY
	column_name(s);
