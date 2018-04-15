#include "arvore.hpp"
using namespace std;

int main()
{
  ofstream myfile;
  std::string Comando;
 
  // Selecao de comandos 
  cout << "Regras.............................";
  cout << "Deseja iniciar um novo jogo(N) ou um salvo(L)? Se for um salvo, o jogo será modificado após seu termino." << endl;
  cout << "Digite:";
  cin >> Comando;
 
  // Novo jogo
  if(strcmp(Comando, "N") == 0)
  {
    // Dados que serão armazenados no arquivo
    cout << "Novo Jogo" << endl;
    cout << "Insira o nome do jogo(Não é permitido espaços no nome nem o caracter |. Para substituí-las, coloque _ ou -):" << endl;

    // Converte o nome do jogo inserido em char* para ser aceito nas operações de File
    std::string arquivo_jogo;
    cin >> arquivo_jogo;
    int n = arquivo_jogo.length();
    arquivo_jogo += ".txt";
    char* texto = (char*) malloc((n+1)*sizeof(char));
    strcpy(texto, arquivo_jogo.c_str());




    free (texto);
  }
 
  // Jogo anterior
  else if(strcmp(Comando, "L") == 0)
  {
    // Dados que serão armazenados no arquivo
    cout << "Carregar jogo:" << endl;
    cout << "Insira o nome do jogo salvo(Não é permitido espaços no nome. Para substituí-las, coloque _ ou -):" << endl;
    std::string arquivo_jogo;
    cin >> arquivo_jogo;
    int n = arquivo_jogo.length();
    arquivo_jogo += ".txt";
    char* texto = (char*) malloc((n+1)*sizeof(char));
    strcpy(texto, arquivo_jogo.c_str());






    cout << "Recarregado" << endl;

    free(texto);
  }
 
  // Erro de usuario
  else
  {
    cout << "Comando nao identificavel" << endl;
  }
 
 
 
  return 0;
}

