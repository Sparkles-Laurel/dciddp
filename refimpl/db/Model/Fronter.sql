--
-- DCIDDP.
-- Prepared SQL queries for 'fronter' definition.
--


--
-- SELECT template for table `fronter`
--
SELECT `id`, `name`, `pronouns` FROM `fronter` WHERE 1;

--
-- INSERT template for table `fronter`
--
INSERT INTO `fronter`(`id`, `name`, `pronouns`) VALUES (?, ?, ?);

--
-- UPDATE template for table `fronter`
--
UPDATE `fronter` SET `id` = ?, `name` = ?, `pronouns` = ? WHERE 1;

--
-- DELETE template for table `fronter`
--
DELETE FROM `fronter` WHERE 0;

