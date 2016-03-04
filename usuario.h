#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

class usuario
{
	string username;
	string password;
	vector<int> juego;
	vector<string> amigos;	
public:
	usuario(string, string);
	bool addGame(int id);
	void addFriend(string username);
	void deleteGame(int id);
	void deleteFriend(string username);	
	void changePassword(string password);
	string getUsername();
	bool isValidPassword(string username, string password);
	string toString()const;
};