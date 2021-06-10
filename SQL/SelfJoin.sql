/**
 * \file  SelfJoin.sql
 * \brief Self Join
 *
 * A self join is a regular join, but the table is joined with itself.
 */


SELECT
	column_name(s)
FROM
	table1 T1,
	table1 T2
WHERE
	condition;