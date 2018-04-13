#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "arvore.hpp"
using namespace std;

TEST_CASE("Criar arvore", "[Criar]")
{
	tree* t = new tree();
	REQUIRE(t->return_root() == NULL);
	REQUIRE(t->return_current() == t->return_root());
}

