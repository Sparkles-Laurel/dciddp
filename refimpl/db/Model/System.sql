--
-- DCIDDP.
-- Prepared SQL queries for 'system' definition.
--


--
-- SELECT template for table `system`
--
SELECT `id`, `name`, `pronouns`, `fronters`, `members` FROM `system` WHERE 1;

--
-- INSERT template for table `system`
--
INSERT INTO `system`(`id`, `name`, `pronouns`, `fronters`, `members`) VALUES (?, ?, ?, ?, ?);

--
-- UPDATE template for table `system`
--
UPDATE `system` SET `id` = ?, `name` = ?, `pronouns` = ?, `fronters` = ?, `members` = ? WHERE 1;

--
-- DELETE template for table `system`
--
DELETE FROM `system` WHERE 0;

