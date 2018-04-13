#include "arvore.hpp"
using namespace std;
 
tree::tree()
{
  root = NULL;
  current = root;
}
 
tree::~tree()
{
  destroy_tree();
}
 
void tree::insert(std::string frase_entrada,
                  Opcao opcao_entrada,
                  TipoFrase tipo_entrada)
{
  // Se a arvore é inicializada e o no atual nao é folha vazia
  if(current != NULL)
    insert(frase_entrada, opcao_entrada, tipo_entrada,current);

  // Se for uma folha vazia, cria-se um novo node
  else if(current == root) 
  {
    current = new node;
  }

  // Copia a frase de entrada para o Node
  current->frase = frase_entrada;
  current->tipo = tipo_entrada;
  current->ind = '0';
  current->Nao = NULL;
  current->Sim = NULL;

}
 
void tree::insert(std::string frase_entrada, 
                  Opcao opcao_entrada,
                  TipoFrase tipo_entrada,
                  node* current)
{
  if(tipo_entrada == TipoFrase::resposta)
  {
    if(opcao_entrada == Opcao::sim)
    {
      
    }
  }
  else
  {
 
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
 
