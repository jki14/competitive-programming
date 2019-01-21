SELECT `Students`.`Name` FROM
  `Friends`
  INNER JOIN
    `Packages` AS `lht`
  ON `Friends`.`ID` = `lht`.`ID`
  INNER JOIN
    `Packages` AS `rht`
  ON `Friends`.`Friend_ID` = `rht`.`ID`
  INNER JOIN
    `Students`
  ON `Friends`.`ID` = `Students`.`ID`
WHERE `lht`.`Salary` < `rht`.`Salary`
ORDER BY `rht`.`Salary` ASC;
