estim: usuario.o main.o juego.o
	g++ usuario.o main.o juego.o -o estim
main.o: main.cpp usuario.h juego.o
	g++ -c main.cpp
usuario.o: usuario.cpp usuario.h
	g++ -c usuario.cpp
juego.o: juego.cpp juego.h
	g++ -c juego.cpp
