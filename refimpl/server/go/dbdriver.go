import (
	"os"
	"gorm.io/gorm"
	"gorm.io/driver/mysql"
)

type Config struct {
	db_address   string
	db_port      uint16
	db_username  string
	db_password  string
	db_name      string
	db_charset   string
	db_parsetime bool
}

type DBDriver struct {
	dsn string
}

func LoadConfigFromEnv() (cfg Config, err Error)  {
	var result Config
	success := true
	if db_address, exists := os.LookupEnv("DCIDDPD_DB_ADDRESS"); exists {
		result.db_address = db_address

		success = success && exists
	} else {
		err = Error.
	}
	if db_port, exists := os.LookupEnv("DCIDDPD_DB_PORT"); exists {
		result.db_port = db_port

		success = success && exists
	} else {
		success = false
	}
		
	if db_username, exists := os.LookupEnv("DCIDDPD_DB_UNAME"); exists {
		result.db_username = db_username

		success = success && exists
	} else {
		success = false
	}

	if db_password, exists := os.LookupEnv("DCIDDPD_DB_PASSWD"); exists {
		result.db_password = db_password
	} else {
		success = false
	}
		
	if db_address, exists := os.LookupEnv("DCIDDPD_DB_ADDRESS"); exists {
		result.db_address = db_address
	}

	if db_address, exists := os.LookupEnv("DCIDDPD_DB_ADDRESS"); exists {
		result.db_address = db_address
	}
	
	cfg = result
	err = nil

	return
	
}
