#include "arvore.hpp"
using namespace std;
 
tree::tree()
{
  root = NULL;
  current = NULL;
}
 
tree::~tree()
{
  destroy_tree();
}
 
void tree::insert(std::string frase_entrada,
                  Opcao opcao_entrada,
                  TipoFrase tipo_entrada)
{
  // Se a arvore é inicializada
  if(current != NULL)
    insert(frase_entrada, opcao_entrada, tipo_entrada,current);

  // Se for uma arvore nao criada cria-se um novo root
  else 
  {
    if((current == root))
    {
      current = new node;
    } 
    // Copia a frase de entrada para o Node
    current->frase = frase_entrada;
    current->tipo = tipo_entrada;
    current->ind = "0";
    current->Nao = NULL;
    current->Sim = NULL;
    root = current;
  }
}
 
void tree::insert(std::string frase_entrada, 
                  Opcao opcao_entrada,
                  TipoFrase tipo_entrada,
                  node* current)
{
  // ----------------------------------------------Se a frase de entrada for um tipo resposta
  if(tipo_entrada == TipoFrase::resposta)
  {
    /* Se o objeto inserido é alternativa resposta
      sim da pergunta */
    if(opcao_entrada == Opcao::sim)
    {
      if (current->Sim != NULL)
        delete current->Sim;
      current->Sim = new node;
      node* resposta = current->Sim;
      resposta->frase = frase_entrada;
      resposta->tipo = tipo_entrada;
      resposta->ind = current->ind + '1';
      resposta->Nao = NULL;
      resposta->Sim = NULL;
    }
    /*Caso contrario */
    else
    {
      if (current->Nao != NULL)
        delete current->Nao;
      current->Nao = new node;
      node* resposta = current->Nao;
      resposta->frase = frase_entrada;
      resposta->tipo = tipo_entrada;
      resposta->ind = current->ind + '0';
      resposta->Nao = NULL;
      resposta->Sim = NULL;
    }
  }

  // ----------------------------------------------Se a frase de entrada for uma pergunta
  else
  {
    // Se o erro foi na resposta sim
    if(opcao_entrada == Opcao::sim)
    {
      if (current->Sim != NULL)
        delete current->Sim;

      current->Sim = new node;
      node* pergunta = current->Sim;
      pergunta->frase = frase_entrada;
      pergunta->tipo = tipo_entrada;
      pergunta->ind = current->ind + '1';
      pergunta->Nao = NULL;
      pergunta->Sim = NULL;
    }
    else
    {
      if (current->Nao != NULL)
        delete current->Nao;

      current->Nao = new node;
      node* pergunta = current->Nao;
      pergunta->frase = frase_entrada;
      pergunta->tipo = tipo_entrada;
      pergunta->ind = current->ind + '0';
      pergunta->Nao = NULL;
      pergunta->Sim = NULL;
    }
  }
}
 
void tree::eliminate(Opcao opcao_usuario)
{
  if(opcao_usuario == Opcao::sim)
  {
    destroy_tree(current->Sim);
    current->Sim = NULL;
  }
  else
  {
    destroy_tree(current->Nao);
    current->Nao = NULL;
  }
}

void tree::destroy_tree()
{
  destroy_tree(root);
}
 
void tree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->Nao);
    destroy_tree(leaf->Sim);
    delete leaf;
  }
}

int tree::save_game(char* nome_arquivo) //char* nome arquivo -- 
{
  node* save = root;
  if(save != NULL)
  {
    ofstream myfile;
    myfile.open (nome_arquivo);

    int n_ind = (save->ind).length();
    char* ind = (char*) malloc((n_ind+1)*sizeof(char));
    strcpy(ind, (save->ind).c_str());

    char* tipo_frase;
    if(save->tipo == TipoFrase::resposta)
    {
      tipo_frase = "resposta";
    }

    else
    {
      tipo_frase = "pergunta";
    }

    int n_frase = (save->frase).length();
    char* frase = (char*) malloc((n_frase+1)*sizeof(char));
    strcpy(frase, (save->frase).c_str());

    myfile << ind<< "|";
    myfile << tipo_frase << "|";
    myfile << frase << endl;

    myfile.close();
    save_game(nome_arquivo, save->Nao);
    save_game(nome_arquivo, save->Sim);

    free(ind);
    free(frase);

    return 1;
  }
}

void tree::save_game(char* nome_arquivo, node* save)
{
   if(save != NULL)
  {
    ofstream myfile;
    myfile.open (nome_arquivo, ios::app);


    int n_ind = (save->ind).length();
    char* ind = (char*) malloc((n_ind+1)*sizeof(char));
    strcpy(ind, (save->ind).c_str());

    char* tipo_frase;
    if(save->tipo == TipoFrase::resposta)
    {
      tipo_frase = "resposta";
    }

    else
    {
      tipo_frase = "pergunta";
    }

    int n_frase = (save->frase).length();
    char* frase = (char*) malloc((n_frase+1)*sizeof(char));
    strcpy(frase, (save->frase).c_str());

    myfile << ind << "|";
    myfile << tipo_frase << "|";
    myfile << frase << endl;

    myfile.close();
    free(ind);
    free(frase);

    save_game(nome_arquivo, save->Nao);
    save_game(nome_arquivo, save->Sim);
  }
}

int tree::ler_arquivo(char* nome_arquivo)
{
  ifstream myfile(nome_arquivo);
  int report = 1;
  std::string line;

  // Decodificador de arquivo
  if(myfile.is_open())
  {
    while( getline (myfile,line) )
    { 
      std::string ind;
      std::string tipo;
      std::string frase;

      int i = 0;
      while(line[i] != '|')
      {
        ind += line[i];
        i++;
      }
      ind += '-';
      i++;
      while(line[i] != '|')
      {
        tipo += line[i];
        i++;
      }
      i++;

      while(line[i] != '\0')
      {
        frase += line[i];
        i++;
      }
      
      report = decodifica_nodes(ind,tipo,frase);

      // Houve erro
      if(report == 0)
      {
        cout << "arvore.cpp:266 Erro na funcao decodifica_nodes" << endl;
        return 0;
      }
    }
    myfile.close();
    return 1;
  }

  else
  {
    cout << "Unable to open file"<< endl; 

    // Houve erro
    return 0;
  }

  // Reseta o current modificado no decodifica nodes
  current = root;
}

int tree::decodifica_nodes(std::string ind_entrada,
                            std::string tipo_entrada,
                             std::string frase_entrada)
{
    current = root;
    node* prox;
    int i = 2;
    Opcao opcao_entrada;
    TipoFrase tipo_convertido;

    // Determinar tipo no insert
    if(tipo_entrada == "resposta")
    {
      tipo_convertido = TipoFrase::resposta;
    }

    else if(tipo_entrada == "pergunta")
    {
      tipo_convertido = TipoFrase::pergunta;
    }

    else
    {

      // Houve erro
      cout << "arvore.cpp:311 tipo convertido não é nem resposta nem pergunta: "<< endl;
      cout << tipo_entrada << endl;
      cout << ind_entrada<< endl;
      return 0;
    }

  // Se a arvore é inicializada
  if(current != NULL && ind_entrada != "0-")
  {
    // Para se determinar o proximo do current no início

    if(ind_entrada[1] == '0')
    {
      prox = current->Nao;
    }

    else if(ind_entrada[1] == '1')
    {
      prox = current->Sim;
    }

    // Processo de determinacao do current pelo qual sera inserido o node
    while(ind_entrada[i] != '-')
    {
      if(ind_entrada[i] == '0')
      {
        current = prox;
        prox = current->Nao;
      }
      else if(ind_entrada[i] == '1')
      {
        current = prox;
        prox = current->Sim;
      }
      else if(ind_entrada[i] != '0'|| ind_entrada[i] != '1'|| ind_entrada[i] != '-')
      {
        cout << "arvore.cpp:344  Leu um não 0 ou 1 ou /0" << endl;
        return 0;
      }
      i++;
    }

    // Determinar opcao no insert
    if(ind_entrada[i-1] == '0')
    {
      opcao_entrada = Opcao::nao;
    }

    else if(ind_entrada[i-1] == '1')
    {
      opcao_entrada = Opcao::sim;
    }

    else
    {
      // Houve erro
      cout << "arvore.cpp:364  Leu um não 0 ou 1" << endl;
      return 0;
    }


    insert(frase_entrada, opcao_entrada, tipo_convertido, current);

    return 1;
  }

  else if(ind_entrada == "-")
  {
    cout << "arvore.cpp:376  Leu um arquivo corrompido"<< endl;
    return 0;  
  }

  // Se for uma arvore nao criada cria-se um novo root
  else 
  {
    if((current == root))
    {
      current = new node;
    } 

    else
    {
      // Houve erro
      cout << "arvore.cpp:391  a raiz não é 0" << endl;
      return 0;
    }
    
    // Copia a frase de entrada para o Node
    current->frase = frase_entrada;
    current->tipo = tipo_convertido;
    current->ind = '0';
    current->Nao = NULL;
    current->Sim = NULL;
    root = current;

    return 1;
  } 
}

void tree::reset_current()
{
  current = root;
}
 
// Test functions
 
node* tree::return_root()
{
  return root;  
}
 
node* tree::return_current()
{
  return current;  
}
 
std::string tree::return_root_frase()
{
  return root->frase;
}

void tree::set_current(int i)
{
  if (i == 0)
    current = root->Sim;
}

void tree::pre_order_printing()
{
  node* show_node = root;
  if(show_node != NULL)
  {
    cout << show_node->frase << endl;
    pre_order_printing(show_node->Nao);
    pre_order_printing(show_node->Sim);
  }
}

void tree::pre_order_printing(node* show_node)
{
  if(show_node != NULL)
  {
    cout << show_node->frase << endl;
    pre_order_printing(show_node->Nao);
    pre_order_printing(show_node->Sim);
  } 
}
