SELECT `lht`.`hacker_id`, `Hackers`.`name`, `lht`.`created` FROM 
  (SELECT `hacker_id`, COUNT(DISTINCT `challenge_id`) AS `created` FROM
    `Challenges`
  GROUP BY `hacker_id`) AS `lht`
  INNER JOIN
    (SELECT MAX(`created`) AS `bar` FROM
      (SELECT `hacker_id`, COUNT(DISTINCT `challenge_id`) AS `created` FROM
        `Challenges`
      GROUP BY `hacker_id`) AS `rht-inner`
     ) AS `rht`
  ON `lht`.`created` = `rht`.`bar`
  INNER JOIN
    `Hackers`
  ON `lht`.`hacker_id` = `Hackers`.`hacker_id`
ORDER BY `lht`.`created` DESC, `lht`.`hacker_id` ASC;
--
SELECT `Hackers`.`hacker_id`, `Hackers`.`name`, `tt`.`created` FROM
  `Hackers`
  INNER JOIN
    (SELECT MIN(`lht`.`hacker_id`) AS `hacker_id`, `lht`.`created` AS `created`, COUNT(`lht`.`hacker_id`) AS `cnt` FROM 
      (SELECT `hacker_id`, COUNT(DISTINCT `challenge_id`) AS `created` FROM
        `Challenges`
      GROUP BY `hacker_id`) AS `lht`
      LEFT JOIN
        (SELECT MAX(`created`) AS `bar` FROM
          (SELECT `hacker_id`, COUNT(DISTINCT `challenge_id`) AS `created` FROM
            `Challenges`
          GROUP BY `hacker_id`) AS `rht-inner`
         ) AS `rht`
      ON `lht`.`created` = `rht`.`bar`
      INNER JOIN
        `Hackers`
      ON `lht`.`hacker_id` = `Hackers`.`hacker_id`
      WHERE `rht`.`bar` IS NULL
    GROUP BY `lht`.`created`
    ORDER BY `lht`.`created` DESC) AS `tt`
  ON `Hackers`.`hacker_id` = `tt`.`hacker_id`
  WHERE `tt`.`cnt` = 1
ORDER BY `tt`.`created` DESC;
