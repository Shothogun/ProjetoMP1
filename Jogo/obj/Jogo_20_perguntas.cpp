#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
	ofstream myfile;
	char Comando[50];

	// Selecao de comandos 
	cout << "Deseja iniciar um novo jogo(N) ou um salvo(L)?" << endl;
	cout << "Digite:";
	cin >> Comando;

	// Novo jogo
	if(strcmp(Comando, "N") == 0)
	{
		cout << "Novo Jogo" << endl;
	}

	// Jogo anterior
	else if(strcmp(Comando, "L") == 0)
	{
		cout << "Recarregado" << endl;
	}

	// Erro de usuario
	else
	{
		cout << "Comando nao identificavel" << endl;
	}



	return 0;
}