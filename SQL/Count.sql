/**
 * \file  Count.sql
 * \brief COUNT - returns the number of records returned by a select query
 *
 * \note  NULL values are not counted
 */


#--------------------------------------------------------------------------------------------------
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
#--------------------------------------------------------------------------------------------------
SELECT
    count(IF(status = 'Cancelled', 1, NULL)) AS 'Cancelled',
    count(IF(status = 'OnHold',    1, NULL)) AS 'OnHold',
    count(IF(status = 'Disputed',  1, NULL)) AS 'Disputed'
FROM
    orders;

# 'Cancelled', 'OnHold', 'Disputed'
# 6,           4,        3
#--------------------------------------------------------------------------------------------------
