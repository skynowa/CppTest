/**
 * \file  Count.sql
 * \brief COUNT - returns the number of records returned by a select query
 *
 * \note  NULL values are not counted
 */


SELECT
    count(*), 
    count(-1),
    count(0), 
    count(1), 
    count(2), 
    count(NULL)
FROM
    triptake.Languages;

# count(*), count(-1), count(0), count(1), count(2), count(NULL)
# 42,       42,        42,       42,       42,       0
