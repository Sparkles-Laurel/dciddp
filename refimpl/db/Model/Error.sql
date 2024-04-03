--
-- DCIDDP.
-- Prepared SQL queries for 'error' definition.
--


--
-- SELECT template for table `error`
--
SELECT `code`, `error` FROM `error` WHERE 1;

--
-- INSERT template for table `error`
--
INSERT INTO `error`(`code`, `error`) VALUES (?, ?);

--
-- UPDATE template for table `error`
--
UPDATE `error` SET `code` = ?, `error` = ? WHERE 1;

--
-- DELETE template for table `error`
--
DELETE FROM `error` WHERE 0;

