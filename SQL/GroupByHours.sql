/**
 * \file  GroupByHours.sql
 * \brief
 */


SELECT
    DATE_FORMAT(CreateTS, '%Y-%m-%d %H') AS hour,
    COUNT(*) AS count
FROM
    triptake.BookedAvails
WHERE
    LastTS >= sysdate()
GROUP
    BY hour;
