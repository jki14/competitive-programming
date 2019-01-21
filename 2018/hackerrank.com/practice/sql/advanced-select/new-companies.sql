SELECT DISTINCT `Pivot`.`company_code`, `Pivot`.`founder`, `Lmt`.`foo`, `Smt`.`foo`, `Mt`.`foo`, `Et`.`foo` FROM
    `Company` AS `Pivot`
    LEFT JOIN
        (SELECT `company_code`, COUNT(DISTINCT `lead_manager_code`) AS `foo` FROM `Lead_Manager` GROUP BY `company_code`) AS `Lmt`
    ON `Pivot`.`company_code` = `Lmt`.`company_code`
    LEFT JOIN
        (SELECT `company_code`, COUNT(DISTINCT `senior_manager_code`) AS `foo` FROM `Senior_Manager` GROUP BY `company_code`) AS `Smt`
    ON `Pivot`.`company_code` = `Smt`.`company_code`
    LEFT JOIN
        (SELECT `company_code`, COUNT(DISTINCT `manager_code`) AS `foo` FROM `Manager` GROUP BY `company_code`) AS `Mt`
    ON `Pivot`.`company_code` = `Mt`.`company_code`
    LEFT JOIN
        (SELECT `company_code`, COUNT(DISTINCT `employee_code`) AS `foo` FROM `Employee` GROUP BY `company_code`) AS `Et`
    ON `Pivot`.`company_code` = `Et`.`company_code`
ORDER BY `company_code` ASC;