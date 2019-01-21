SELECT SUM(`CITY`.`POPULATION`) FROM
  `CITY`
  INNER JOIN
    `COUNTRY`
  ON `CITY`.`COUNTRYCODE` = `COUNTRY`.`CODE`
WHERE `CONTINENT` = 'Asia';

SELECT `CITY`.`NAME` FROM
  `CITY`
  INNER JOIN
    `COUNTRY`
  ON `CITY`.`COUNTRYCODE` = `COUNTRY`.`CODE`
WHERE `CONTINENT` = 'Africa';

SELECT `CONTINENT`, FLOOR(AVG(`CITY`.`POPULATION`)) FROM
  `CITY`
  INNER JOIN
    `COUNTRY`
  ON `CITY`.`COUNTRYCODE` = `COUNTRY`.`CODE`
GROUP BY `CONTINENT`;

SELECT IF(`Grade` >= 8, `Name`, NULL), `Grade`, `Marks` FROM
  `Students`
  INNER JOIN
    `Grades`
  ON `MIN_Mark` <= `Marks` AND `Marks` <= `MAX_Mark`
ORDER BY `Grade` DESC, `Name` ASC;

SELECT `Hackers`.`hacker_id`, `Hackers`.`name` FROM
  `Hackers`
  INNER JOIN
    (SELECT `Submissions`.`hacker_id` AS `hacker_id`, COUNT(DISTINCT `Submissions`.`challenge_Id`) AS `passed` FROM
      `Submissions`
      INNER JOIN
        `Challenges`
      ON `Submissions`.`challenge_id` = `Challenges`.`challenge_id`
      INNER JOIN
        `Difficulty`
      ON `Challenges`.`difficulty_level` = `Difficulty`.`difficulty_level`
    WHERE `Submissions`.`score` = `Difficulty`.`score`
    GROUP BY `Submissions`.`hacker_id`) AS `T`
  ON `Hackers`.`hacker_id` = `T`.`hacker_id`
WHERE `passed` > 1
ORDER BY `passed` DESC, `Hackers`.`hacker_id` ASC;

SELECT `id`, `Wands_Property`.`age`, `Wands`.`coins_needed`, `Wands`.`power` FROM
  `Wands`
  INNER JOIN
    `Wands_Property`
  ON `Wands`.`code` = `Wands_Property`.`code`
  INNER JOIN
    (SELECT `age`, MIN(`coins_needed`) AS `bar`, `power` FROM
      `Wands`
      INNER JOIN
        `Wands_Property`
      ON `Wands`.`code` = `Wands_Property`.`code`
    WHERE `is_evil` = 0
    GROUP BY `power`, `age`) AS `rht`
  ON `Wands`.`power` = `rht`.`power` AND `Wands_Property`.`age` = `rht`.`age` AND `Wands`.`coins_needed` = `rht`.`bar`
  WHERE `is_evil` = 0
ORDER BY `power` DESC, `age` DESC;
