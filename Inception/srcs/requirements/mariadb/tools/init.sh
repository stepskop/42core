#!/bin/bash

# Create MySQL data directory if it doesn't exist
if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

# Start MySQL in safe mode in background for initialization
mysqld_safe --user=mysql --datadir=/var/lib/mysql &

# Wait for MySQL to start
until mysqladmin ping >/dev/null 2>&1; do
    echo "Waiting for MariaDB to start..."
    sleep 2
done

# Create database and users
mysql -e "CREATE DATABASE IF NOT EXISTS $DB_NAME;"
mysql -e "CREATE USER IF NOT EXISTS '$DB_ADMIN'@'%' IDENTIFIED BY '$DB_ADMIN_PWD';"
mysql -e "CREATE USER IF NOT EXISTS '$DB_WPUSER'@'%' IDENTIFIED BY '$DB_WPPASSWORD';"
mysql -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_ADMIN'@'%';"
mysql -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_WPUSER'@'%';"
mysql -e "FLUSH PRIVILEGES;"

# Stop the background MySQL process
mysqladmin shutdown

# Start MySQL in foreground
exec mysqld --user=mysql --datadir=/var/lib/mysql
