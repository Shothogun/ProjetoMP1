#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "arvore.hpp"
using namespace std;
 
TEST_CASE("Criar arvore", "[arvore]")
{
  tree* t = new tree();
  REQUIRE(t->return_root() == NULL);
  REQUIRE(t->return_current() == t->return_root());
  t->insert("É um ser vivo?", Opcao::nao, TipoFrase::pergunta);
  REQUIRE(t->current->frase == "É um ser vivo?");
}

TEST_CASE("Operacoes de insercoes", "[arvore]")
{
	tree* t = new tree();
  t->insert("É um ser vivo?", Opcao::nao, TipoFrase::pergunta);
  REQUIRE(t->current->frase == "É um ser vivo?");
}
