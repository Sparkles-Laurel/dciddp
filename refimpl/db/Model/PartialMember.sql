--
-- DCIDDP.
-- Prepared SQL queries for 'partial-member' definition.
--


--
-- SELECT template for table `partial-member`
--
SELECT `name`, `pronouns` FROM `partial-member` WHERE 1;

--
-- INSERT template for table `partial-member`
--
INSERT INTO `partial-member`(`name`, `pronouns`) VALUES (?, ?);

--
-- UPDATE template for table `partial-member`
--
UPDATE `partial-member` SET `name` = ?, `pronouns` = ? WHERE 1;

--
-- DELETE template for table `partial-member`
--
DELETE FROM `partial-member` WHERE 0;

