FROM debian:bullseye

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y curl tar

WORKDIR /opt
RUN curl -L -o portainer.tar.gz https://github.com/portainer/portainer/releases/download/2.19.4/portainer-2.19.4-linux-amd64.tar.gz
RUN tar -xzf portainer.tar.gz && rm portainer.tar.gz

WORKDIR /opt/portainer

CMD ["./portainer"]
