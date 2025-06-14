#!/bin/bash

if [ ! -f "/var/www/html/.wp_installed" ]; then
  echo "Installing WordPress…"

  mkdir -p /var/www/html
  cd /var/www/html

  wp core download --allow-root

  # Create wp-config.php from template with database connection info
  cp /conf/wp-config.php /var/www/html/wp-config.php
  sed -i -r "s/DATABASE_NAME/$DB_NAME/1"   wp-config.php
  sed -i -r "s/DATABASE_USER/$DB_WPUSER/1"  wp-config.php
  sed -i -r "s/DATABASE_PASSWORD/$DB_WPPASSWORD/1"    wp-config.php

  # Wait for database to be ready
  until php -r "
    \$connection = new mysqli('maria_db', '$DB_WPUSER', '$DB_WPPASSWORD', '$DB_NAME');
    if (\$connection->connect_error) {
      exit(1);
    }
    echo 'Database connection successful';
    exit(0);
  "; do
    echo "Waiting for MariaDB to be ready..."
    sleep 2
  done

  wp core install --url=$DOMAIN_NAME/ --title="$WP_TITLE" --admin_user=$WP_ADMIN_USR --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root

  wp theme install astra --activate --allow-root

  wp plugin install redis-cache --activate --allow-root

  wp plugin update --all --allow-root

  touch /var/www/html/.wp_installed
fi

mkdir -p /run/php

# Enable Redis cache if WordPress is already configured
if [ -e "/var/www/html/wp-config.php" ]; then
  cd /var/www/html
  wp redis enable --allow-root 2>/dev/null || echo "Redis cache setup skipped"
fi

/usr/sbin/php-fpm7.4 -F
