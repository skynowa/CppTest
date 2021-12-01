/**
 * \file  MultipleColumns.sql
 * \brief DISTINCT multiple columns
 *
 * Let's say I have columns a, b c, d in a table in a MySQL database.
 * What I'm trying to do is to select the distinct values of ALL of these 4 columns in my table
 * (only the distinct values).
 *
 * \see https://stackoverflow.com/questions/12188027/mysql-select-distinct-multiple-columns
 */


-- Sample 1
SELECT
	a, b
FROM
	mytable
GROUP BY
	a, b;

-- Sample 2
SELECT
	(SELECT group_concat(DISTINCT a) FROM my_table) as a,
	(SELECT group_concat(DISTINCT b) FROM my_table) as b;

-- Sample 3
SELECT DISTINCT a FROM my_table
	UNION
SELECT DISTINCT b FROM my_table

-- Sample 4
SELECT
	DISTINCT(CONCAT(a,b)) AS cc
FROM
	my_table
GROUP BY
	cc;
