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
 
void tree::eliminate()
{
  destroy_tree(current);
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
