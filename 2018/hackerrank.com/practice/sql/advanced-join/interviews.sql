SELECT `Contests`.`contest_id`, `Contests`.`hacker_id`, `Contests`.`name`, `st`.`total_submissions`, `st`.`total_accepted_submissions`, `vt`.`total_views`, `vt`.`total_unique_views` FROM
  `Contests`
  INNER JOIN
    (SELECT `Colleges`.`contest_id` AS `contest_id`, SUM(`total_submissions`) AS `total_submissions`, SUM(`total_accepted_submissions`) AS `total_accepted_submissions` FROM
      `Submission_Stats`
    INNER JOIN
      `Challenges`
    ON `Submission_Stats`.`challenge_id` = `Challenges`.`challenge_id`
    INNER JOIN
      `Colleges`
    ON `Challenges`.`college_id` = `Colleges`.`college_id`
    GROUP BY `Colleges`.`contest_id`) AS `st`
  ON `Contests`.`contest_id` = `st`.`contest_id`
  INNER JOIN
    (SELECT `Colleges`.`contest_id` AS `contest_id`, SUM(`total_views`) AS `total_views`, SUM(`total_unique_views`) AS `total_unique_views` FROM
      `View_Stats`
    INNER JOIN
      `Challenges`
    ON `View_Stats`.`challenge_id` = `Challenges`.`challenge_id`
    INNER JOIN
      `Colleges`
    ON `Challenges`.`college_id` = `Colleges`.`college_id`
    GROUP BY `Colleges`.`contest_id`) AS `vt`
  ON `Contests`.`contest_id` = `vt`.`contest_id`
WHERE `st`.`total_submissions` != 0 OR `st`.`total_accepted_submissions` != 0 OR `vt`.`total_views` != 0 OR `vt`.`total_unique_views` != 0;
