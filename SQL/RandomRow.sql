/**
 * \file  RandomRow.sql
 * \brief Select random row
 */


-- MySQL

SELECT [column] FROM [table[
ORDER BY rand()
LIMIT 1

-- SQLite

SELECT [column] FROM [table]
ORDER BY random()
LIMIT 1