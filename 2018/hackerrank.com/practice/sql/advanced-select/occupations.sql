SELECT `C1`.`Name`, `C2`.`Name`, `C3`.`Name`, `C4`.`Name` FROM
    (SELECT @rid1a := @rid1a + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid1a := 0) init WHERE `Occupation` = 'Doctor' ORDER BY `NAME` ASC) `C1` 
    LEFT JOIN
        (SELECT @rid2a := @rid2a + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid2a := 0) init WHERE `Occupation` = 'Professor' ORDER BY `NAME` ASC) `C2`
    ON `C1`.`RowId` = `C2`.`RowId`
    LEFT JOIN
        (SELECT @rid3a := @rid3a + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid3a := 0) init WHERE `Occupation` = 'Singer' ORDER BY `NAME` ASC) `C3`
    ON `C1`.`RowId` = `C3`.`RowId`
    LEFT JOIN
        (SELECT @rid4a := @rid4a + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid4a := 0) init WHERE `Occupation` = 'Actor' ORDER BY `NAME` ASC) `C4`
    ON `C1`.`RowId` = `C4`.`RowId`
UNION
SELECT `C1`.`Name`, `C2`.`Name`, `C3`.`Name`, `C4`.`Name` FROM
    (SELECT @rid1b := @rid1b + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid1b := 0) init WHERE `Occupation` = 'Doctor' ORDER BY `NAME` ASC) `C1` 
    RIGHT JOIN
        (SELECT @rid2b := @rid2b + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid2b := 0) init WHERE `Occupation` = 'Professor' ORDER BY `NAME` ASC) `C2`
    ON `C1`.`RowId` = `C2`.`RowId`
    LEFT JOIN
        (SELECT @rid3b := @rid3b + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid3b := 0) init WHERE `Occupation` = 'Singer' ORDER BY `NAME` ASC) `C3`
    ON `C2`.`RowId` = `C3`.`RowId`
    LEFT JOIN
        (SELECT @rid4b := @rid4b + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid4b := 0) init WHERE `Occupation` = 'Actor' ORDER BY `NAME` ASC) `C4`
    ON `C2`.`RowId` = `C4`.`RowId`
UNION
SELECT `C1`.`Name`, `C2`.`Name`, `C3`.`Name`, `C4`.`Name` FROM
    (SELECT @rid1c := @rid1c + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid1c := 0) init WHERE `Occupation` = 'Doctor' ORDER BY `NAME` ASC) `C1` 
    RIGHT JOIN
        (SELECT @rid2c := @rid2c + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid2c := 0) init WHERE `Occupation` = 'Professor' ORDER BY `NAME` ASC) `C2`
    ON `C1`.`RowId` = `C2`.`RowId`
    RIGHT JOIN
        (SELECT @rid3c := @rid3c + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid3c := 0) init WHERE `Occupation` = 'Singer' ORDER BY `NAME` ASC) `C3`
    ON `C2`.`RowId` = `C3`.`RowId`
    LEFT JOIN
        (SELECT @rid4c := @rid4c + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid4c := 0) init WHERE `Occupation` = 'Actor' ORDER BY `NAME` ASC) `C4`
    ON `C3`.`RowId` = `C4`.`RowId`
UNION
SELECT `C1`.`Name`, `C2`.`Name`, `C3`.`Name`, `C4`.`Name` FROM
    (SELECT @rid1d := @rid1d + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid1d := 0) init WHERE `Occupation` = 'Doctor' ORDER BY `NAME` ASC) `C1` 
    RIGHT JOIN
        (SELECT @rid2d := @rid2d + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid2d := 0) init WHERE `Occupation` = 'Professor' ORDER BY `NAME` ASC) `C2`
    ON `C1`.`RowId` = `C2`.`RowId`
    RIGHT JOIN
        (SELECT @rid3d := @rid3d + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid3d := 0) init WHERE `Occupation` = 'Singer' ORDER BY `NAME` ASC) `C3`
    ON `C2`.`RowId` = `C3`.`RowId`
    RIGHT JOIN
        (SELECT @rid4d := @rid4d + 1 AS `RowId`, `Name` FROM `OCCUPATIONS`, (SELECT @rid4d := 0) init WHERE `Occupation` = 'Actor' ORDER BY `NAME` ASC) `C4`
    ON `C3`.`RowId` = `C4`.`RowId`;