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
/*
void tree::insert(char* pergunta)
{
	insert(pergunta,current);
}
*/
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
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}
