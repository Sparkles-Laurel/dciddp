--
-- DCIDDP.
-- Prepared SQL queries for 'member' definition.
--


--
-- SELECT template for table `member`
--
SELECT `name`, `pronouns`, `id` FROM `member` WHERE 1;

--
-- INSERT template for table `member`
--
INSERT INTO `member`(`name`, `pronouns`, `id`) VALUES (?, ?, ?);

--
-- UPDATE template for table `member`
--
UPDATE `member` SET `name` = ?, `pronouns` = ?, `id` = ? WHERE 1;

--
-- DELETE template for table `member`
--
DELETE FROM `member` WHERE 0;

