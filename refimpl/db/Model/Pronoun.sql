--
-- DCIDDP.
-- Prepared SQL queries for 'pronoun' definition.
--


--
-- SELECT template for table `pronoun`
--
SELECT `subject`, `object`, `possessive`, `possessive_determiner`, `reflexive` FROM `pronoun` WHERE 1;

--
-- INSERT template for table `pronoun`
--
INSERT INTO `pronoun`(`subject`, `object`, `possessive`, `possessive_determiner`, `reflexive`) VALUES (?, ?, ?, ?, ?);

--
-- UPDATE template for table `pronoun`
--
UPDATE `pronoun` SET `subject` = ?, `object` = ?, `possessive` = ?, `possessive_determiner` = ?, `reflexive` = ? WHERE 1;

--
-- DELETE template for table `pronoun`
--
DELETE FROM `pronoun` WHERE 0;

