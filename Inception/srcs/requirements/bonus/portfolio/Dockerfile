FROM alpine:3.22

RUN apk add --no-cache busybox-extras

COPY . /var/www/html

WORKDIR /var/www/html

CMD ["httpd", "-f", "-v", "-p", "80", "-h", "/var/www/html"]
