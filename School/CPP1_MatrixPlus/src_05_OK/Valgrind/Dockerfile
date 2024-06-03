FROM ubuntu:22.04

RUN apt-get -y update; apt-get -y install valgrind; apt-get -y install check; apt-get -y install gcc; apt-get -y install make; mkdir -p /usr/src/; apt-get -y install g++; apt-get install -y g++ libgtest-dev

WORKDIR /usr/src/

COPY ./src /usr/src/

USER root

ENTRYPOINT ["/bin/bash", "Valgrind/start.sh"]

