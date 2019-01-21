SELECT COUNT(`lht`.`Start_Date`) INTO @count FROM
  `Projects` AS `lht`
  LEFT JOIN
    `Projects` AS `rht`
  ON `lht`.`Start_Date` = `rht`.`End_Date`
WHERE `rht`.`End_Date` IS NULL;
SELECT `lht`.`Start_Date` AS `Head`, `rht`.`Prev_End` AS `Tail` FROM
  (SELECT @ridl := @ridl + 1 AS `row_id`, `Start_Date`, `Prev_End` FROM
    (SELECT @prev AS `Prev_End`, `Start_Date`, @prev := `End_Date` FROM
      `Projects`, (SELECT @prev := MAX(`End_Date`) FROM `Projects`) AS `prev-init`
    ORDER BY `Start_Date` ASC) AS `promoted`
    , (SELECT @ridl := 0) AS `ridl-init`  
  WHERE `Start_Date` != `Prev_End`) AS `lht`
  LEFT JOIN
    (SELECT @ridr := @ridr + 1 AS `row_id`, `Start_Date`, `Prev_End` FROM
      (SELECT @prev AS `Prev_End`, `Start_Date`, @prev := `End_Date` FROM
        `Projects`, (SELECT @prev := MAX(`End_Date`) FROM `Projects`) AS `prev-init`
      ORDER BY `Start_Date` ASC) AS `promoted`
      , (SELECT @ridr := 0) AS `ridr-init`  
    WHERE `Start_Date` != `Prev_End`) AS `rht`
  ON `lht`.`row_id` % @count + 1 = `rht`.`row_id`
ORDER BY DATEDIFF(`Head`, `Tail`) DESC, `Head` ASC;
