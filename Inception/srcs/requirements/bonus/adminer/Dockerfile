FROM debian:bullseye

RUN apt update && apt install -y \
    apache2 \
    php \
    php-pdo \
    php-mysqli \
    php-mbstring \
    php-xml \
    php-mysql \
    curl \
    && rm -rf /var/lib/apt/lists/*

RUN a2enmod rewrite
RUN rm -f /var/www/html/index.html

RUN echo "DirectoryIndex adminer.php" >> /etc/apache2/apache2.conf
RUN echo "ServerName localhost" >> /etc/apache2/apache2.conf

RUN chown -R www-data:www-data /var/www/html

WORKDIR /var/www/html
RUN curl -o adminer.php https://www.adminer.org/static/download/5.3.0/adminer-5.3.0.php

CMD ["apachectl","-D","FOREGROUND"]
