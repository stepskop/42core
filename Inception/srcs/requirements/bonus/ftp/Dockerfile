FROM debian:bullseye

RUN apt update -y && apt upgrade -y
RUN apt install -y vsftpd

RUN mkdir -p /var/run/vsftpd/empty

COPY ./tools/init.sh /usr/local/bin/init.sh
RUN chmod +x /usr/local/bin/init.sh

CMD ["/usr/local/bin/init.sh"]
