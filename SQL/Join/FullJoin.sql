/**
 * \file  FullJoin.sql
 * \brief FULL OUTER JOIN
 *
 * The FULL OUTER JOIN keyword returns all records when there is a match in left (table1) or
 * right (table2) table records.
 *
 * Tip: FULL OUTER JOIN and FULL JOIN are the same.
 */


SELECT
	column_name(s)
FROM
	table1
FULL OUTER JOIN
	table2
	ON table1.column_name = table2.column_name
WHERE
	condition;
