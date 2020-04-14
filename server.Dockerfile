FROM ubuntu:latest



RUN apt update && apt install -y g++ libsfml-dev

COPY ./multiplayer/server /usr/src/fishserver

WORKDIR /usr/src/fishserver

RUN g++ -c *.cpp 
RUN g++ *.o -o sfml-app -l sfml-network -lsfml-system 
CMD ["./sfml-app"]