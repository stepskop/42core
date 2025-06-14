FROM debian:bullseye

RUN apt -y update && apt install redis-server -y

COPY ./conf/redis.conf /etc/redis/redis.conf

CMD ["redis-server", "/etc/redis/redis.conf", "--protected-mode", "no"]
