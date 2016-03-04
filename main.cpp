#include <iostream>
#include "usuario.h"
#include "juego.h"
#include <string>

using std::cout;
using std::cin;
using std::string;
void menu();
void menuAgrEl();
void Log(string&, string&);
void menuMod();

int main(int argc, char const *argv[])
{
	vector<usuario> listaUsuario;
	vector<juego> listaJuego;
	string userna, contr, nuevaContra;
	int opcMenu, opcJuego, posUsuarioLog, opcsubMenuagr, posElim, opcsubMenuMod,opcsubMenuElim, opcsubMenuList;
	bool login, sePuedeAgregar = true;
	int idJu, yearJu;
	string dev, nom, gen;
	do
	{
		menu();
		cin >> opcMenu;
		if (opcMenu == 1)
		{
			menuAgrEl();
			cin >> opcsubMenuagr;
			if (opcsubMenuagr == 1)
			{
				while(sePuedeAgregar)
				{
					cout << "usuario: ";
					cin >> userna;
					cout << "contraseña: ";
					cin >> contr;
					if (listaUsuario.size() != 0)
					{
						for (int i = 0; i < listaUsuario.size(); ++i)
						{
							if ( listaUsuario[i].isValidPassword(userna, contr) != 0 )
							{
								cout << "true\n";
								sePuedeAgregar = true;
							}else if(listaUsuario[i].isValidPassword(userna, contr) == 0)
							{
								cout << "false\n";
								sePuedeAgregar = false;
							}
						}
					}else{
						cout << "false2\n";
						sePuedeAgregar = false;
					}
				}
				usuario a(userna, contr);
				listaUsuario.push_back(a);
				sePuedeAgregar = true;
			}
			else if (opcsubMenuagr == 2)
			{
				while(sePuedeAgregar)
				{
					cout << "id: ";
					cin >> idJu;
					cout << "nombre: ";
					cin >> nom;
					cout << "año: ";
					cin >> yearJu;
					cout << "developer: ";
					cin >> dev;
					cout << "género: ";
					cin >> gen;
					if (listaJuego.size() != 0)
					{
						for (int i = 0; i < listaUsuario.size(); ++i)
						{
							if ( listaJuego[i].getId() == idJu )
							{
								sePuedeAgregar = true;
							}else if(listaJuego[i].getId() != idJu)
							{
								sePuedeAgregar = false;
							}
						}
					}else{
						sePuedeAgregar = false;
					}
				}
				juego b(idJu, nom, yearJu, dev, gen);
				listaJuego.push_back(b);
				sePuedeAgregar = true;				
			}
		}
		else if (opcMenu == 2)
		{
			if(listaUsuario.size() != 0)
			{
				Log(userna, contr);
				for (int i = 0; i < listaUsuario.size(); ++i)
				{
					if (listaUsuario[i].isValidPassword(userna, contr) == 0)
					{
						login = false;
					}else
					{
						login = true;
						posUsuarioLog = i;
					}
				}
				if (login)
				{
					menuMod();
					cin >> opcsubMenuMod;
					if (opcsubMenuMod == 1)
					{
						if(listaJuego.size() != 0 ){
							for (int i = 0; i < listaJuego.size(); ++i)
							{
								cout << i <<"-"<< listaJuego[i].toString()<< "\n";
							}
							cout << "Seleccionar: ";
							cin >> opcJuego;
							listaUsuario[posUsuarioLog].addGame(listaJuego[opcJuego].getId());
						}else
						{
							cout << "No Hay Juegos para seleccionar XD\n";
						}	
					}
					else if(opcsubMenuMod == 2)
					{
						if(listaJuego.size() != 0)
						{
							for (int i = 0; i < listaJuego.size(); ++i)
							{
								cout << i <<"-"<< listaJuego[i].toString()<< "\n";
							}
							cout << "Seleccionar: ";
							cin >> opcJuego;
							listaUsuario[posUsuarioLog].deleteGame(listaJuego[opcJuego].getId());	
						}else
						{
							cout << "No Hay Juegos para seleccionar XD\n";
						}					
					}
					else if (opcsubMenuMod == 3)
					{
						cout << "Modificar contraseña: ";
						cin >> nuevaContra;
						listaUsuario[posUsuarioLog].changePassword(nuevaContra);
					}else{
						throw "-_-";
					}
				}
			}else
			{
				cout <<"No Existen usuarios\n";
			}
		}
		else if (opcMenu == 3)
		{
			menuAgrEl();
			cin >> opcsubMenuElim;
			if (opcsubMenuElim == 1)
			{
				if (listaUsuario.size() != 0 )
				{
					for (int i = 0; i < listaUsuario.size(); ++i)
					{
						cout << i << listaUsuario[i].toString();
					}
					cout << "seleccionar: ";
					cin >> posElim;
					listaUsuario.erase(listaUsuario.begin() + posElim);
				}else
				{
					cout << "No Hay usuarios\n";
				}
			}else if (opcsubMenuElim == 2)
			{
				if (listaJuego.size() != 0 )
				{
					for (int i = 0; i < listaJuego.size(); ++i)
					{
						cout << i << listaJuego[i].toString();
					}
					cout << "seleccionar: ";
					cin >> posElim;
					listaJuego.erase(listaJuego.begin() + posElim);
				}else
				{
					cout << "No Hay usuarios\n";
				}
			}
		}
		else if(opcMenu == 4)
		{
			menuAgrEl();
			cin >> opcsubMenuList;
			if (opcsubMenuList == 1)
			{
				if (listaUsuario.size() == 0)
				{
					cout << "no hay usuarios\n";
				}else{
					for (int i = 0; i < listaUsuario.size(); ++i)
					{
						cout << i << "-" << listaUsuario[i].toString() << "\n";
					}
				}
			}else if (opcsubMenuList == 2)
			{
				if (listaJuego.size() == 0)
				{
					cout << "no hay juegos\n";
				}else{
					for (int i = 0; i < listaJuego.size(); ++i)
					{
						cout << i << "-" << listaJuego[i].toString() << "\n";
					}
				}
			}
		}
	} while (opcMenu != 5);
	return 0;
}

void menu()
{
	cout << "1-Agregar\n2-Modificar\n3-Eliminar\n4-Listar\n5-Salir\n";
}

void menuAgrEl()
{
	cout << "1-Usuario\n2-Juego\n";
}

void Log(string &username, string &password)
{
	//Log in
	cout << "LOG IN";
	cout << "usuario: ";
	cin >> username;
	cout << "contraseña: ";
	cin >> password;
}
void menuMod()
{
	cout << "1- Agregar Juego\n2- Eliminar Amigo\n3- Cambiar contraseña\n";
}