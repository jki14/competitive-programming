SELECT `lht`.`X`, `lht`.`Y` FROM
  `Functions` AS `lht`
  INNER JOIN
    (SELECT `X`, `Y`, COUNT(*) AS `count` FROM
      `Functions` 
    WHERE `X` >= `Y`
    GROUP BY `X`, `Y`
    )AS `rht`
  ON (`rht`.`X` != `rht`.`Y` OR `rht`.`count` > 1) AND `lht`.`X` = `rht`.`Y` AND `lht`.`Y` = `rht`.`X`
WHERE `lht`.`X` <= `lht`.`Y`
GROUP BY `lht`.`X`, `lht`.`Y`
ORDER BY `lht`.`X` ASC, `lht`.`Y` ASC;
