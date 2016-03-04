#include "juego.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

juego::juego(int id, string nom, int year, string dev, string gen):
	id(id), nom(nom), year(year), dev(dev), gen(gen){}

int juego::getId()
{
	return id;
}
string juego::toString()const
{
	stringstream ss;
	ss << id << "," << nom << "-";
	return ss.str();
}