FROM gcc:latest

#privzeti direktorij
WORKDIR /app

#kopiraj vse v docker
COPY . .

#prevedi
RUN g++ -o app main.cpp

#zazeni
CMD ["./app"]
