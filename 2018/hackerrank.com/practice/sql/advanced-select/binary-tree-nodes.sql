SELECT `id`, IF(`nullroot` IS NULL, 'Root', IF(`childnum` = 0, 'Leaf', 'Inner')) FROM
  (SELECT `LHS`.`N` AS `id`, `LHS`.`P` AS `nullroot`, IFNULL(`RHS`.`C`, 0) AS `childnum` FROM
    `BST` AS `LHS`
      LEFT JOIN
          (SELECT `P`, COUNT(`N`) AS `C` FROM `BST` GROUP BY `P`) AS `RHS`
      ON `LHS`.`N` = `RHS`.`P`) AS `T`
ORDER BY `id`;