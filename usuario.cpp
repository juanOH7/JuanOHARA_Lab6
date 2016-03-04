#include "usuario.h"
#include <string>
#include <sstream>
#include <vector>

using std::vector;
using std::string;
using std::stringstream;

usuario::usuario(string username, string password):
	username(username), password(password){
		vector<int> juego();
		vector<string> amigos();
	}

bool usuario::addGame(int id)
{
	for (int i = 0; i < juego.size(); ++i)
		{
			if (id != juego[i])
			{
				juego.push_back(id);
			}else{
				throw "Ya Tienes Este Juego!!!";
			}
		}
		return true;
}

void usuario::addFriend(string username)
{
	for (int i = 0; i < amigos.size(); ++i)
	{
		if ( username.compare(amigos[i]) !=0 )
		{
			amigos.push_back(username);
		}else
		{
			throw "Ya Existe Este Usuario!!!";
		}
	}
}

void usuario::deleteGame(int id)
{
	int ubi;
	for (int i = 0; i < juego.size(); ++i)
	{
		if (id == juego[i])
		{
			ubi = i;
		}else
		{
			throw "No Tienes Este Juego -_-";
		}
	}
	this ->	juego.erase(juego.begin()+ubi);
}

void usuario::deleteFriend(string username)
{
	int ub;
	for (int i = 0; i < amigos.size(); ++i)
	{
		if (username.compare(amigos[i]) )
		{
			ub = i;
		}else
		{
			throw "No Tienes Este Amigo -_-";
		}
	}
	this -> amigos.erase(amigos.begin()+ub);
}
void usuario::changePassword(string password)
{
	this -> password = password;
}

string usuario::getUsername()
{
	return username;
}
bool usuario::isValidPassword(string usname, string pass)
{
	if ( (username.compare(usname)) && (password.compare(pass)) )
	{
		return true;
	}else{
		return false;
	}
}

string usuario::toString()const
{
	stringstream ss;
	ss << username << "," << password << "i";
	return ss.str();
}
