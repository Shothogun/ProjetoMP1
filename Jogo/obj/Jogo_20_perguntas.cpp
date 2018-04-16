#include "arvore.hpp"
using namespace std;

int main()
{
  ofstream myfile;
  char Comando;
 
  // Selecao de comandos 
  cout << "Bem vindo!" << endl;
  cout << "( ´ ▽ ` )ﾉ" << endl;
  cout << "Regras............................."<< endl;
  cout << "Deseja iniciar um novo jogo(N) ou um salvo(L)? Se for um salvo, o jogo será modificado após seu termino." << endl;
  cout << "Digite:";
  cin >> Comando;
 
  // Novo jogo
  if (Comando == 'N')
  {
    // Dados que serão armazenados no arquivo
    cout << "Novo Jogo" << endl;
    cout << "Insira o nome do jogo(Não é permitido espaços no nome nem o caracter |. Para substituí-las, coloque _ ou -):" << endl;
    cout << "(；￣Д￣）" << endl;

    // Converte o nome do jogo inserido em char* para ser aceito nas operações de File
    std::string arquivo_jogo;
    cin >> arquivo_jogo;
    int n = arquivo_jogo.length();
    // Add terminacao .txt
    arquivo_jogo += ".txt";
    // Nome do jogo em char
    char* nome = (char*) malloc((n+1)*sizeof(char));
    strcpy(nome, arquivo_jogo.c_str());


    // Arvore do jogo
    tree* Jogo = new tree();


    // Última escolha do jogador
    Opcao opcao_jogador;
    char resposta;

    Jogo->insert("É um ser vivo?", Opcao::sim, TipoFrase::pergunta);
    Jogo->insert("cobra", Opcao::sim, TipoFrase::resposta);
    Jogo->insert("martelo", Opcao::nao, TipoFrase::resposta);

    // Node que o jogo printará
    Jogo->reset_current();
    node* prox = Jogo->current;

    while(prox->tipo != TipoFrase::resposta)
    {
      // Confimação da deleção
      char confirmacao;
      cout << prox->frase << endl;
      cin >> resposta;
      if(resposta == 'S')
      {
        Jogo->current = prox;
        prox = Jogo->current->Sim;
        opcao_jogador = Opcao::sim;
      }

      else if (resposta == 'N')
      {
        Jogo->current = prox;
        prox = Jogo->current->Nao;
        opcao_jogador = Opcao::nao;
      }

      else if( resposta == 'D')
      {
        if(prox == Jogo->return_root())
        {
          cout << "Comando invalido. Nao se pode tirar a primeira pergunta" << endl;
          cout << "(҂⌣̀_⌣́)";
        }

        else
        {
          cout << "Tem certeza? Uma vez apagado, todas as perguntas ou respostas associadas a ela serão apagadas" << endl;
          cout << "（；¬＿¬)" << endl;

          cin >> confirmacao;

          if(resposta == 'S')
          {
            std::string resposta_alternativa;
            cout << "coloque uma resposta à pergunta anterior" << endl;
            cout << prox->frase << endl;
            Jogo->eliminate(opcao_jogador);
            if(opcao_jogador == Opcao::sim)
            {
              cout << "que responde sim" << endl;
              getchar();
            }
            else
            {
              cout << "que responde não" << endl;
              getchar();
            }

            getline (cin,resposta_alternativa);
            Jogo->insert(resposta_alternativa, opcao_jogador, TipoFrase::resposta);
            cout << " ╭( ･ㅂ･)و Obrigado jogar! Foi bom jogar com voce!(♥ω♥ ) ~♪" << endl;
            Jogo->save_game(nome);

            return 0;
          }

          else if (resposta == 'N')
          {
            continue;
          }

          else
          {
            while(confirmacao != 'S' && confirmacao != 'N')
            {
              cout << "Comando não valido. Digite S ou N" << endl;
              cout << "┌П┐(►˛◄’!)" << endl;
              cin >> confirmacao;
            }

            if(confirmacao == 'S')
            {
              
              std::string resposta_alternativa;
              cout << "coloque uma resposta à pergunta anterior" << endl;
              cout << prox->frase << endl;
              Jogo->eliminate(opcao_jogador);
              if(opcao_jogador == Opcao::sim)
              {
                cout << "que responde sim" << endl;
                getchar();
              }
              else
              {
                cout << "que responde não" << endl;
                getchar();
              }

              getline (cin,resposta_alternativa);
              Jogo->insert(resposta_alternativa, opcao_jogador, TipoFrase::resposta);
              cout << " ╭( ･ㅂ･)و Obrigado jogar! Foi bom jogar com voce!(♥ω♥ ) ~♪" << endl;
              Jogo->save_game(nome);

              return 0;

            }

            else if (confirmacao == 'N')
            {
              continue;
            }
          }
        }
      } 
    
      else
      {
        while(resposta != 'S' && resposta != 'N')
        {
          cout << "Comando não valido. Digite S ou N" << endl;
          cout << "┌П┐(►˛◄’!)" << endl;
          cin >> resposta;
        }

        if(resposta == 'S')
        {
          Jogo->current = prox;
          prox = Jogo->current->Sim;
          opcao_jogador = Opcao::sim;
        }

        else if (resposta == 'N')
        {
          Jogo->current = prox;
          prox = Jogo->current->Nao;
          opcao_jogador = Opcao::nao;
        }
      }
    }
  
    // Fim de jogo

    cout << "A resposta é (ﾉ･ｪ･)ﾉ:" << prox->frase << endl;

    cout << "Acertei?(・_・ヾ" << endl;

    cin >> resposta;

    if(resposta == 'S')
    {
      cout << " ╭( ･ㅂ･)و Obrigado jogar! Foi bom jogar com voce!(♥ω♥ ) ~♪" << endl;
    }

    else if(resposta == 'N')
    {
      std::string pergunta;
      std::string correto;
      char opcao_char;
      cout << "('o') Nossa, que pena... （─。─）" << endl;
      cout << "Me ensine! o(^▽^)o Insira o que voce pensou:" << endl; 
      getchar();
      getline (cin,correto);
      cout << "Insira uma pergunta que diferencie minha resposta da sua (＃⌒∇⌒＃)ゞ: " << endl;
      getline (cin,pergunta);
      cout << "A sua resposta que você inseriu responderia sim ou não à pergunta?〈(゜。゜)" << endl;
      cin >> opcao_char;

      if (opcao_char != 'S' || opcao_char != 'N')
      {
        while(opcao_char != 'S' && opcao_char != 'N')
        {
          cout << "Comando não valido ┌П┐(►˛◄’!). Digite S ou N" << endl;
          cin >> opcao_char;
        }
      }

      std::string errado = prox->frase;

      if(opcao_char == 'S')
      {
        Jogo->insert(pergunta, opcao_jogador, TipoFrase::pergunta);

        if(opcao_jogador == Opcao::sim)
        {
          Jogo->current = Jogo->current->Sim;
        }

        else
        {
          Jogo->current = Jogo->current->Nao;
        }

        Jogo->insert(correto, Opcao::sim, TipoFrase::resposta);
        Jogo->insert(errado, Opcao::nao, TipoFrase::resposta);
      }

      else
      {
        if(opcao_jogador == Opcao::sim)
        {
          Jogo->current = Jogo->current->Sim;
        }

        else
        {
          Jogo->current = Jogo->current->Nao;
        }

        Jogo->insert(correto, Opcao::nao, TipoFrase::resposta);
        Jogo->insert(errado, Opcao::sim, TipoFrase::resposta);
      }
      cout << " ╭( ･ㅂ･)و Obrigado jogar! Foi bom jogar com voce! (♥ω♥ ) ~♪" << endl;
    }

    Jogo->save_game(nome);
    Jogo->reset_current();

    delete Jogo;
    free (nome);
  }
 
  // Jogo anterior
  else if(Comando == 'L')
  {
    // Dados que serão armazenados no arquivo
    cout << "Carregar jogo:" << endl;
    cout << "Insira o nome do jogo salvo(Não é permitido espaços no nome. Para substituí-las, coloque _ ou -):" << endl;
    std::string arquivo_jogo;
    cin >> arquivo_jogo;
    int n = arquivo_jogo.length();
    arquivo_jogo += ".txt";
    char* nome = (char*) malloc((n+1)*sizeof(char));
    strcpy(nome, arquivo_jogo.c_str());

    int report = 1;
    tree* Jogo = new tree();
    report = Jogo->ler_arquivo(nome);
    Opcao opcao_jogador;
    char resposta;

    if(report == 0)
    {
      cout << "ERRO NO ARQUIVO (⌣_⌣”)" << endl;
      return 0;
    } 

    Jogo->reset_current();
    node* prox = Jogo->current;
    cout << "Recarregado" << endl;

    while(prox->tipo != TipoFrase::resposta)
    {
      char confirmacao;
      cout << prox->frase << endl;
      cin >> resposta;
      if(resposta == 'S')
      {
        Jogo->current = prox;
        prox = Jogo->current->Sim;
        opcao_jogador = Opcao::sim;
      }

      else if (resposta == 'N')
      {
        Jogo->current = prox;
        prox = Jogo->current->Nao;
        opcao_jogador = Opcao::nao;
      }

      else if( resposta == 'D')
      {
        if(prox == Jogo->return_root())
        {
          cout << "Comando invalido. Nao se pode tirar a primeira pergunta (҂⌣̀_⌣́)" << endl;
        }

        else
        {
          cout << "Tem certeza? Uma vez apagado, todas as perguntas ou respostas associadas a ela serão apagadas                                   （；¬＿¬)" << endl;
          cin >> confirmacao;

          if(resposta == 'S')
          {
            std::string resposta_alternativa;
            cout << "coloque uma resposta à pergunta anterior" << endl;
            cout << prox->frase << endl;
            Jogo->eliminate(opcao_jogador);
            if(opcao_jogador == Opcao::sim)
            {
              cout << "que responde sim" << endl;
              getchar();
            }
            else
            {
              cout << "que responde não" << endl;
              getchar();
            }

            getline (cin,resposta_alternativa);
            Jogo->insert(resposta_alternativa, opcao_jogador, TipoFrase::resposta);
            cout << " ╭( ･ㅂ･)و Obrigado jogar! Foi bom jogar com voce!(♥ω♥ ) ~♪" << endl;
            Jogo->save_game(nome);

            return 0;
          }

          else if (resposta == 'N')
          {
            continue;
          }

          else
          {
            while(confirmacao != 'S' && confirmacao != 'N')
            {
              cout << "Comando não valido ┌П┐(►˛◄’!). Digite S ou N" << endl;
              cin >> confirmacao;
            }

            if(confirmacao == 'S')
            {
              
              std::string resposta_alternativa;
              cout << "coloque uma resposta à pergunta anterior" << endl;
              cout << prox->frase << endl;
              Jogo->eliminate(opcao_jogador);
              if(opcao_jogador == Opcao::sim)
              {
                cout << "que responde sim" << endl;
                getchar();
              }
              else
              {
                cout << "que responde não" << endl;
                getchar();
              }

              getline (cin,resposta_alternativa);
              Jogo->insert(resposta_alternativa, opcao_jogador, TipoFrase::resposta);
              cout << " ╭( ･ㅂ･)و Obrigado jogar! Foi bom jogar com voce!(♥ω♥ ) ~♪" << endl;
              Jogo->save_game(nome);
              
              return 0;

            }

            else if (confirmacao == 'N')
            {
              continue;
            }
          }
        }
      } 
    
      else
      {
        while(resposta != 'S' && resposta != 'N')
        {
          cout << "Comando não valido ┌П┐(►˛◄’!). Digite S ou N" << endl;
          cin >> resposta;
        }

        if(resposta == 'S')
        {
          Jogo->current = prox;
          prox = Jogo->current->Sim;
          opcao_jogador = Opcao::sim;
        }

        else if (resposta == 'N')
        {
          Jogo->current = prox;
          prox = Jogo->current->Nao;
          opcao_jogador = Opcao::nao;
        }
      }
    }

    // Fim de jogo
    cout << "A resposta é (ﾉ･ｪ･)ﾉ:" << prox->frase << endl;

    cout << "Acertei? (・_・ヾ" << endl;

    cin >> resposta;

    if(resposta == 'S')
    {
      cout << " ╭( ･ㅂ･)و Obrigado jogar! Foi bom jogar com voce! (♥ω♥ ) ~♪" << endl;
    }

    else if(resposta == 'N')
    {
      std::string pergunta;
      std::string correto;
      char opcao_char;
      cout << "('o') Nossa, que pena... （─。─）" << endl;
      cout << "Me ensine! o(^▽^)o Insira o que voce pensou:" << endl; 
      getchar();
      getline (cin,correto);
      cout << "Insira uma pergunta que diferencie minha resposta da sua (＃⌒∇⌒＃)ゞ: " << endl;
      getline (cin,pergunta);
      cout << "A sua resposta que você inseriu responderia sim ou não à pergunta?〈(゜。゜)" << endl;
      cin >> opcao_char;

      if (opcao_char != 'S' || opcao_char != 'N')
      {
        while(opcao_char != 'S' && opcao_char != 'N')
        {
          cout << "Comando não valido ┌П┐(►˛◄’!). Digite S ou N" << endl;
          cin >> opcao_char;
        }
      }

      std::string errado = prox->frase;

      if(opcao_char == 'S')
      {
        Jogo->insert(pergunta, opcao_jogador, TipoFrase::pergunta);

        if(opcao_jogador == Opcao::sim)
        {
          Jogo->current = Jogo->current->Sim;
        }

        else
        {
          Jogo->current = Jogo->current->Nao;
        }

        Jogo->insert(correto, Opcao::sim, TipoFrase::resposta);
        Jogo->insert(errado, Opcao::nao, TipoFrase::resposta);
      }

      else
      {
        if(opcao_jogador == Opcao::sim)
        {
          Jogo->current = Jogo->current->Sim;
        }

        else
        {
          Jogo->current = Jogo->current->Nao;
        }

        Jogo->insert(correto, Opcao::nao, TipoFrase::resposta);
        Jogo->insert(errado, Opcao::sim, TipoFrase::resposta);
      }
      cout << " ╭( ･ㅂ･)و Obrigado jogar! Foi bom jogar com voce!(♥ω♥ ) ~♪" << endl;
    }

    Jogo->save_game(nome);
    Jogo->reset_current();
    delete Jogo;
    free(nome);
  }
 
  // Erro de usuario
  else
  {
    cout << "Comando nao identificavel〈(゜。゜)" << endl;
  }
 
 
  return 0;
}

