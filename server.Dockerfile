FROM ubuntu:latest

COPY . /usr/src/fishserver

WORKDIR /usr/src/fishserver

RUN sudo apt-get install libsfml-dev

RUN sh build.sh
