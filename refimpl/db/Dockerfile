FROM mariadb:latest

ENV MYSQL_ROOT_PASSWORD=root
ENV MYSQL_DATABASE=dciddpdb
COPY ./mysql_schema.sql /docker-entrypoint-initdb.d/
