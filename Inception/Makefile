all : up

up :
	mkdir -p ./data/wordpress
	mkdir -p ./data/mariadb
	mkdir -p ./data/portainer
	@docker-compose -f ./srcs/docker-compose.yaml up

up-d :
	mkdir -p ./data/wordpress
	mkdir -p ./data/mariadb
	mkdir -p ./data/portainer
	@docker-compose -f ./srcs/docker-compose.yaml up -d

down :
	@docker-compose -f ./srcs/docker-compose.yaml down

stop :
	@docker-compose -f ./srcs/docker-compose.yaml stop

start :
	@docker-compose -f ./srcs/docker-compose.yaml start

build :
	@docker-compose -f ./srcs/docker-compose.yaml build

hard-restart : down clean up

hard-rebuild : down clean build

clean :
	rm -rf ./data

status :
	@docker ps
