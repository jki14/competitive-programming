SET @first = (SELECT MIN(`submission_date`) FROM `Submissions`);
SELECT `mr`.`date`, IFNULL(`sr`.`num`, 0), `mr`.`hacker_id`, `mr`.`name` FROM
  (SELECT `st`.`date`, COUNT(DISTINCT `st`.`hacker_id`) AS `num` FROM
    (SELECT `lht`.`submission_date` AS `date`, `lht`.`hacker_id` AS `hacker_id`, COUNT(`rht`.`submission_date`) AS `showed` FROM
        (SELECT `submission_date`, `hacker_id` FROM
          `Submissions`
        GROUP BY `submission_date`, `hacker_id`) AS `lht`
      INNER JOIN
        (SELECT `submission_date`, `hacker_id` FROM
          `Submissions`
        GROUP BY `submission_date`, `hacker_id`) AS `rht`
      ON `lht`.`hacker_id` = `rht`.`hacker_id` AND `rht`.`submission_date` <= `lht`.`submission_date`
    GROUP BY `lht`.`submission_date`, `lht`.`hacker_id`) AS `st`
  WHERE `st`.`showed` = DATEDIFF(`st`.`date`, @first) + 1
  GROUP BY `st`.`date`) AS `sr`
  RIGHT JOIN
    (SELECT `tt`.`date` AS `date`, `Hackers`.`hacker_id` AS `hacker_id`, `Hackers`.`name` AS `name` FROM
      (SELECT `tt0-2`.`submission_date` AS `date`, MIN(`hacker_id`) AS `hacker_id` FROM
        (SELECT `submission_date`, `hacker_id`, COUNT(`submission_id`) AS `score` FROM
          `Submissions`
        GROUP BY `submission_date`, `hacker_id`) AS `tt0-2`
        INNER JOIN
          (SELECT `submission_date`, MAX(`score`) AS `bar` FROM
            (SELECT `submission_date`, `hacker_id`, COUNT(`submission_id`) AS `score` FROM
              `Submissions`
            GROUP BY `submission_date`, `hacker_id`) AS `tt0`
            GROUP BY `tt0`.`submission_date`
          ) AS `tt1`
        ON `tt0-2`.`submission_date` = `tt1`.`submission_date` AND `tt0-2`.`score` = `tt1`.`bar`
      GROUP BY `tt0-2`.`submission_date`) AS `tt`
    INNER JOIN
      `Hackers`
    ON `tt`.`hacker_id` = `Hackers`.`hacker_id`) AS `mr`
  ON `mr`.`date` = `sr`.`date`
ORDER BY `mr`.`date` ASC;
