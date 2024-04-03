--
-- DCIDDP.
-- Prepared SQL queries for 'partial-system' definition.
--


--
-- SELECT template for table `partial-system`
--
SELECT `id`, `name` FROM `partial-system` WHERE 1;

--
-- INSERT template for table `partial-system`
--
INSERT INTO `partial-system`(`id`, `name`) VALUES (?, ?);

--
-- UPDATE template for table `partial-system`
--
UPDATE `partial-system` SET `id` = ?, `name` = ? WHERE 1;

--
-- DELETE template for table `partial-system`
--
DELETE FROM `partial-system` WHERE 0;

