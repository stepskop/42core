FROM debian:buster

RUN apt -y update && apt install -y nginx && apt install openssl -y

COPY ./tools/init.sh /usr/local/bin/init.sh

RUN chmod +x /usr/local/bin/init.sh

CMD [ "/usr/local/bin/init.sh" ]
