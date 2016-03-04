#pragma once
#include <string>

using std::string;

class juego
{
	int id;
	string nom;
	int year;
	string dev;
	string gen;
public:
	juego(int id, string nom, int year, string dev, string gen);
	int getId();
	string toString()const;
};