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
  // Se a arvore possuir raiz
  if(current != NULL)
    insert(frase_entrada, opcao_entrada, tipo_entrada,current);
  else 
  {
    current = new node;
    // Copia a frase de entrada para o Node
    root->frase = frase_entrada;
    root->tipo = tipo_entrada;
    root->ind = "0";
    root->Nao = NULL;
    root->Sim = NULL;
  }
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
 
