#!/bin/bash

KEY=/etc/ssl/private/selfsigned.key
CERT=/etc/ssl/private/selfsigned.crt

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout $KEY -out $CERT -subj "/C=MO/L=KH/O=1337/OU=student/CN=$DOMAIN_NAME"

cat > /etc/nginx/nginx.conf << EOF
events {
    worker_connections 1024;
}

http {
    include /etc/nginx/mime.types;
    default_type application/octet-stream;

    server {
        listen 443 ssl;
        listen [::]:443 ssl;

        ssl_certificate $CERT;
        ssl_certificate_key $KEY;
        ssl_protocols TLSv1.3;

        #server_name $DOMAIN_NAME;

        index index.php;
        root /var/www/html;

        location / {
            try_files \$uri \$uri/ /index.php?\$args;
        }

        location ~ \.php$ {
            try_files \$uri =404;
            fastcgi_pass wordpress:9000;
            include fastcgi_params;
            fastcgi_param SCRIPT_FILENAME \$document_root\$fastcgi_script_name;
            fastcgi_param PATH_INFO \$fastcgi_path_info;
        }

        location /portfolio/ {
            proxy_pass http://site:80/;
            proxy_set_header Host \$host;
            proxy_set_header X-Real-IP \$remote_addr;
            proxy_set_header X-Forwarded-For \$proxy_add_x_forwarded_for;
            proxy_set_header X-Forwarded-Proto \$scheme;
        }

        location /adminer/ {
            proxy_pass http://adminer:80/;
            proxy_set_header Host \$host;
            proxy_set_header X-Real-IP \$remote_addr;
            proxy_set_header X-Forwarded-For \$proxy_add_x_forwarded_for;
            proxy_set_header X-Forwarded-Proto \$scheme;
        }

        location /portainer/ {
            proxy_pass http://portainer:9000/;
            proxy_set_header Host \$host;
            proxy_set_header X-Real-IP \$remote_addr;
            proxy_set_header X-Forwarded-For \$proxy_add_x_forwarded_for;
            proxy_set_header X-Forwarded-Proto \$scheme;
        }
    }
}
EOF


nginx -g "daemon off;"
