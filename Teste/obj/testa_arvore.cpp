#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "arvore.hpp"
using namespace std;
 
TEST_CASE("Inicializar arvore", "[arvore]")
{
  tree* t = new tree();
  REQUIRE(t->return_current() == t->return_root());
  t->insert("É um ser vivo?", Opcao::nao, TipoFrase::pergunta);
  REQUIRE(t->current->frase == "É um ser vivo?");
  REQUIRE(t->current->tipo == TipoFrase::pergunta);
  REQUIRE(t->current->ind == "0");
  REQUIRE(t->return_current() == t->return_root());

	delete t;	
}


TEST_CASE("Operacoes de inserçoes no inicio", "[arvore]")
{
	tree* t = new tree();
  t->insert("É um ser vivo?", Opcao::sim, TipoFrase::pergunta);
  t->insert("cobra", Opcao::sim, TipoFrase::resposta);
  t->insert("martelo", Opcao::nao, TipoFrase::resposta);
  REQUIRE(t->return_root_frase() == "É um ser vivo?");
  REQUIRE(t->current->Sim->frase == "cobra");
  REQUIRE(t->current->Nao->frase == "martelo");


  REQUIRE(t->current->frase == "É um ser vivo?");
  REQUIRE(t->current->tipo == TipoFrase::pergunta);
  REQUIRE(t->current->ind == "0");

  SECTION( "O jogo erra a resposta no inicio")
  {
  	SECTION("Erra no sim")
  	{
  		SECTION("A resposta correta é no sim")
  		{
  			std::string resposta_errada = t->current->Sim->frase;
  			Opcao escolha_usuario = Opcao::sim;
  			std::string resposta_usuario = "humano";
  			
 		 		t->insert("É um animal?", Opcao::sim, TipoFrase::pergunta);
 		 		REQUIRE(t->current->Sim->frase == "É um animal?");
 		 		REQUIRE(t->current->Sim->tipo == TipoFrase::pergunta);
 		 		REQUIRE(t->current->Sim->ind == "01");
 		 		
 		 		t->current = t->current->Sim;

 		 		REQUIRE(t->current->frase == "É um animal?");
 		 		REQUIRE(t->current->tipo == TipoFrase::pergunta);
 		 		REQUIRE(t->current->ind == "01");

 		 		t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
 		 		t->insert(resposta_errada, Opcao::nao,TipoFrase::resposta);

 		 		node* correto = t->current->Sim;
 		 		node* errado = t->current->Nao;
				
 		 		REQUIRE((correto->frase) == "humano");
 		 		REQUIRE((correto->tipo) == TipoFrase::resposta);
 		 		REQUIRE((correto->ind) == "011");

 		 		REQUIRE((errado->frase) == "cobra");
 		 		REQUIRE((errado->tipo) == TipoFrase::resposta);
 		 		REQUIRE((errado->ind) == "010");
 		 		
 		 		delete t;
  		}

  		SECTION("A reposta correta é no nao")
  		{
  			std::string resposta_errada = t->current->Sim->frase;
  			Opcao escolha_usuario = Opcao::nao;
  			std::string resposta_usuario = "humano";

  			t->insert("É um réptil?", Opcao::sim, TipoFrase::pergunta);
  			REQUIRE(t->current->Sim->frase == "É um réptil?");
  			REQUIRE(t->current->Sim->tipo == TipoFrase::pergunta);
  			REQUIRE(t->current->Sim->ind == "01");

  			t->current = t->current->Sim;

  			REQUIRE(t->current->frase == "É um réptil?");
  			REQUIRE(t->current->tipo == TipoFrase::pergunta);
  			REQUIRE(t->current->ind == "01");

  			t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
  			t->insert(resposta_errada, Opcao::sim, TipoFrase::resposta);

  			node* correto = t->current->Nao;
  			node* errado = t->current->Sim;

  			REQUIRE((correto->frase == "humano"));
  			REQUIRE((correto->tipo == TipoFrase::resposta));
  			REQUIRE((correto->ind == "010"));

  			REQUIRE((errado->frase == "cobra"));
  			REQUIRE((errado->tipo == TipoFrase::resposta));
  			REQUIRE((errado->ind == "011"));

  			delete t;
  		}
  	}
  	SECTION("Erra no nao")
  	{
  		SECTION("A resposta correta é no sim")
  		{
  			std::string resposta_errada = t->current->Nao->frase;
  			Opcao escolha_usuario = Opcao::sim;
  			std::string resposta_usuario = "copo";

  			t->insert("É usado para comer no cotidiano?", Opcao::nao, TipoFrase::pergunta);
  			REQUIRE(t->current->Nao->frase == "É usado para comer no cotidiano?");
  			REQUIRE(t->current->Nao->tipo == TipoFrase::pergunta);
  			REQUIRE(t->current->Nao->ind == "00");

  			t->current = t->current->Nao;

  			REQUIRE(t->current->frase == "É usado para comer no cotidiano?");
  			REQUIRE(t->current->tipo == TipoFrase::pergunta);
  			REQUIRE(t->current->ind == "00");

  			t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
  			t->insert(resposta_errada, Opcao::nao, TipoFrase::resposta);

  			node* correto = t->current->Sim;
  			node* errado = t->current->Nao;

  			REQUIRE((correto->frase) == "copo");
  			REQUIRE((correto->tipo) == TipoFrase::resposta);
  			REQUIRE((correto->ind) == "001");

  			REQUIRE((errado->frase) == "martelo");
  			REQUIRE((errado->tipo) == TipoFrase::resposta);
  			REQUIRE((errado->ind) == "000");
  			delete t;
  		}
  	}
  }
}
