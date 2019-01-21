SELECT `Hackers`.`hacker_id`, `Hackers`.`name`, `scores` FROM
  `Hackers`
  INNER JOIN
    (SELECT `hacker_id`, SUM(`score`) AS `scores` FROM
        (SELECT `hacker_id`, MAX(`score`) AS `score` FROM
           `Submissions`
        GROUP BY `hacker_id`, `challenge_id`) AS `rht-inner`
     GROUP BY `hacker_id`) AS `rht`
  ON `Hackers`.`hacker_id` = `rht`.`hacker_id`
WHERE `rht`.`scores` > 0
ORDER BY `scores` DESC, `Hackers`.`hacker_id` ASC;
