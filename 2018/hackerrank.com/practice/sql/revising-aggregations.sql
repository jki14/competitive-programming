SELECT COUNT(*) FROM `CITY` WHERE `POPULATION` > 100000;

SELECT SUM(`POPULATION`) FROM `CITY` WHERE `DISTRICT` = 'California';

SELECT AVG(`POPULATION`) FROM `CITY` WHERE `DISTRICT` = 'California';

SELECT FLOOR(AVG(`POPULATION`)) FROM `CITY`;

SELECT SUM(`POPULATION`) FROM `CITY` WHERE `COUNTRYCODE` = 'JPN';

SELECT MAX(`POPULATION`) - MIN(`POPULATION`) FROM `CITY`;

SELECT CEIL(AVG(`Salary`) - AVG(CONVERT(REPLACE(`Salary`, '0', ''), UNSIGNED INTEGER))) FROM `EMPLOYEES`;

SELECT `months` * `salary` AS `earned`, COUNT(`employee_id`) FROM
  `Employee` AS `lht`
  INNER JOIN
    (SELECT MAX(`months` * `salary`) AS `bar` FROM `Employee`) AS `rht`
  ON `lht`.`months` * `lht`.`salary` = `rht`.`bar`
GROUP BY `earned`;

SELECT ROUND(SUM(`LAT_N`), 2), ROUND(SUM(`LONG_W`), 2) FROM `STATION`;

SELECT TRUNCATE(SUM(`LAT_N`), 4) FROM `STATION` WHERE `LAT_N` > 38.7880 AND `LAT_N` < 137.2345;

SELECT TRUNCATE(MAX(`LAT_N`), 4) FROM `STATION` WHERE `LAT_N` < 137.2345;

SELECT ROUND(`lht`.`LONG_W`, 4) FROM
    `STATION` AS `lht`
    INNER JOIN
        (SELECT `ID` FROM
            `STATION` AS `tt0`
            INNER JOIN
                (SELECT MAX(`LAT_N`) AS `bar` FROM `STATION` WHERE `LAT_N` < 137.2345) AS `tt1`
            ON `tt0`.`LAT_N` = `tt1`.`bar`
        ) AS `rht`
    ON `lht`.`ID` = `rht`.`ID`;

SELECT ROUND(MIN(`LAT_N`), 4) FROM `STATION` WHERE `LAT_N` > 38.7780;

SELECT ROUND(`lht`.`LONG_W`, 4) FROM
  `STATION` AS `lht`
  INNER JOIN
    (SELECT `ID` FROM
      `STATION` AS `tt0`
      INNER JOIN
        (SELECT MIN(`LAT_N`) AS `bar` FROM `STATION` WHERE `LAT_N` > 38.7780) AS `tt1`
      ON `tt0`.`LAT_N` = `tt1`.`bar`
    ) AS `rht`
  ON `lht`.`ID` = `rht`.`ID`;

SELECT ROUND(MAX(`LAT_N`) - MIN(`LAT_N`) + MAX(`LONG_W`) - MIN(`LONG_W`), 4) FROM `STATION`;

SELECT ROUND(SQRT(POW(MAX(`LAT_N`) - MIN(`LAT_N`), 2) + POW(MAX(`LONG_W`) - MIN(`LONG_W`), 2)), 4) FROM `STATION`;

SELECT CEIL(COUNT(*) / 2) - 1 INTO @offset FROM `STATION`;
PREPARE `stmt1` FROM 'SELECT ROUND(`LAT_N`, 4) FROM `STATION` ORDER BY `LAT_N` LIMIT ?, 1';
EXECUTE `stmt1` USING @offset;
