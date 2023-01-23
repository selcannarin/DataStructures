all: build run


build:
	g++ -I ./include/ -o ./lib/Exception.o -c ./src/Exception.cpp
	g++ -I ./include/ -o ./lib/ReadAndInsert.o -c ./src/ReadAndInsert.cpp
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./lib/NodeforYonetici.o -c ./src/NodeforYonetici.cpp

	g++ -I ./include/ -o ./bin/main ./lib/Exception.o ./lib/ReadAndInsert.o ./lib/SatirListesi.o ./lib/Node.o ./lib/YoneticiListesi.o  ./lib/NodeforYonetici.o   ./src/main.cpp

run:
	./bin/main