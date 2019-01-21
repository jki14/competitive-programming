SELECT
    CASE WHEN `A` + `B` + `C` - GREATEST(`A`, `B`, `C`) <= GREATEST(`A`, `B`, `C`) THEN 
        'Not A Triangle' 
    WHEN `A` = `B` AND `B` = `C` THEN
        'Equilateral'
    WHEN `A` + `B` + `C` - GREATEST(`A`, `B`, `C`) - LEAST(`A`, `B`, `C`) = LEAST(`A`, `B`, `C`) THEN
        'Isosceles'
    ELSE
        'Scalene'
    END
FROM `TRIANGLES`;

SELECT CONCAT(`Name`, '(', LEFT(`Occupation`, 1), ')') FROM `OCCUPATIONS` ORDER BY `Name`;
SELECT CONCAT('There are a total of ', COUNT(`Name`), ' ', LOWER(`Occupation`), 's.') FROM `OCCUPATIONS` GROUP BY `Occupation` ORDER BY COUNT(`Name`) ASC, LOWER(`Occupation`) ASC;
