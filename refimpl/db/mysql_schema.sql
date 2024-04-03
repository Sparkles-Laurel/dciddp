/* SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO"; */
/* SET AUTOCOMMIT = 0; */
/* START TRANSACTION; */
/* SET time_zone = "+00:00"; */

-- --------------------------------------------------------

--
-- Table structure for table `error` generated from model 'error'
--

CREATE TABLE IF NOT EXISTS `error` (
  `code` INT DEFAULT NULL COMMENT 'The error code',
  `error` TEXT DEFAULT NULL COMMENT 'The error message'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `fronter` generated from model 'fronter'
--

CREATE TABLE IF NOT EXISTS `fronter` (
  `id` TEXT DEFAULT NULL COMMENT 'The ID of the fronter',
  `name` TEXT DEFAULT NULL COMMENT 'The name of the fronter',
  `pronouns` JSON DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `member` generated from model 'member'
--

CREATE TABLE IF NOT EXISTS `member` (
  `name` TEXT DEFAULT NULL COMMENT 'The name of the member',
  `pronouns` JSON DEFAULT NULL,
  `id` TEXT DEFAULT NULL COMMENT 'The ID of the member'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `partial-member` generated from model 'partialMinusmember'
--

CREATE TABLE IF NOT EXISTS `partial-member` (
  `name` TEXT DEFAULT NULL COMMENT 'The name of the member',
  `pronouns` JSON DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `partial-system` generated from model 'partialMinussystem'
--

CREATE TABLE IF NOT EXISTS `partial-system` (
  `id` TEXT DEFAULT NULL COMMENT 'The ID of the system',
  `name` TEXT DEFAULT NULL COMMENT 'The name of the system'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `pronoun` generated from model 'pronoun'
--

CREATE TABLE IF NOT EXISTS `pronoun` (
  `subject` TEXT DEFAULT NULL COMMENT 'The subject pronoun',
  `object` TEXT DEFAULT NULL COMMENT 'The object pronoun',
  `possessive` TEXT DEFAULT NULL COMMENT 'The possessive pronoun',
  `possessive_determiner` TEXT DEFAULT NULL COMMENT 'The possessive determiner',
  `reflexive` TEXT DEFAULT NULL COMMENT 'The reflexive pronoun'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `system` generated from model 'system'
--

CREATE TABLE IF NOT EXISTS `system` (
  `id` TEXT DEFAULT NULL COMMENT 'The ID of the system',
  `name` TEXT DEFAULT NULL COMMENT 'The name of the system',
  `pronouns` TEXT DEFAULT NULL COMMENT 'The pronouns of the system',
  `fronters` JSON DEFAULT NULL COMMENT 'The current fronter of the system',
  `members` JSON DEFAULT NULL COMMENT 'The members of the system'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


