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
  			
 		 		t->insert("É um mamífero?", Opcao::sim, TipoFrase::pergunta);
 		 		REQUIRE(t->current->Sim->frase == "É um mamífero?");
 		 		REQUIRE(t->current->Sim->tipo == TipoFrase::pergunta);
 		 		REQUIRE(t->current->Sim->ind == "01");
 		 		

 		 		t->current = t->current->Sim;

 		 		REQUIRE(t->current->frase == "É um mamífero?");
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

 		 		SECTION("O jogo erra no decorrer")
  			{
  				SECTION("Erra no sim")
  				{
	  				SECTION("A resposta correta é no sim")
	  				{
	  					std::string resposta_errada = t->current->Sim->frase;
	  					Opcao escolha_usuario = Opcao::sim;
	  					std::string resposta_usuario = "zebra";
	  			
	 		 				t->insert("Ele é quadrúpede?", Opcao::sim, TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Sim->frase == "Ele é quadrúpede?");
	 		 				REQUIRE(t->current->Sim->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Sim->ind == "011");
	 		 		
	 		 				t->current = t->current->Sim;

	 		 				REQUIRE(t->current->frase == "Ele é quadrúpede?");
	 		 				REQUIRE(t->current->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->ind == "011");

	 		 				t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
	 		 				t->insert(resposta_errada, Opcao::nao,TipoFrase::resposta);

	 		 				node* correto = t->current->Sim;
	 		 				node* errado = t->current->Nao;
					
	 		 				REQUIRE((correto->frase) == "zebra");
	 		 				REQUIRE((correto->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((correto->ind) == "0111");

	 		 				REQUIRE((errado->frase) == "humano");
	 		 				REQUIRE((errado->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((errado->ind) == "0110");
	  				}

	  				SECTION("A resposta correta é no nao")
	  				{
	  					std::string resposta_errada = t->current->Sim->frase;
	  					Opcao escolha_usuario = Opcao::nao;
	  					std::string resposta_usuario = "zebra";
	  			
	 		 				t->insert("Ele é bípede?", Opcao::sim, TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Sim->frase == "Ele é bípede?");
	 		 				REQUIRE(t->current->Sim->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Sim->ind == "011");
	 		 		
	 		 				t->current = t->current->Sim;

	 		 				REQUIRE(t->current->frase == "Ele é bípede?");
	 		 				REQUIRE(t->current->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->ind == "011");

	 		 				t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
	 		 				t->insert(resposta_errada, Opcao::sim,TipoFrase::resposta);

	 		 				node* correto = t->current->Nao;
	 		 				node* errado = t->current->Sim;
					
	 		 				REQUIRE((correto->frase) == "zebra");
	 		 				REQUIRE((correto->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((correto->ind) == "0110");

	 		 				REQUIRE((errado->frase) == "humano");
	 		 				REQUIRE((errado->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((errado->ind) == "0111");
	  				}
	  			}		
	  			
	  			SECTION("Erra no nao")
	  			{
	  				SECTION("A resposta correta é no sim")
	  				{
	  					std::string resposta_errada = t->current->Nao->frase;
	  					Opcao escolha_usuario = Opcao::sim;
	  					std::string resposta_usuario = "sapo";
	  			
	 		 				t->insert("É um anfíbio?", Opcao::nao, TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Nao->frase == "É um anfíbio?");
	 		 				REQUIRE(t->current->Nao->ind == "010");
	 		 		
	 		 				t->current = t->current->Nao;

	 		 				REQUIRE(t->current->frase == "É um anfíbio?");
	 		 				REQUIRE(t->current->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->ind == "010");

	 		 				t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
	 		 				t->insert(resposta_errada, Opcao::nao,TipoFrase::resposta);

	 		 				node* correto = t->current->Sim;
	 		 				node* errado = t->current->Nao;
					
	 		 				REQUIRE((correto->frase) == "sapo");
	 		 				REQUIRE((correto->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((correto->ind) == "0101");

	 		 				REQUIRE((errado->frase) == "cobra");
	 		 				REQUIRE((errado->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((errado->ind) == "0100");
	  				}

	  				SECTION("A resposta correta é no nao")
	  				{
	  					std::string resposta_errada = t->current->Nao->frase;
	  					Opcao escolha_usuario = Opcao::nao;
	  					std::string resposta_usuario = "sapo";
	  			
	 		 				t->insert("É um réptil?", Opcao::nao, TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Nao->frase == "É um réptil?");
	 		 				REQUIRE(t->current->Nao->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Nao->ind == "010");
	 		 		
	 		 				t->current = t->current->Nao;

	 		 				REQUIRE(t->current->frase == "É um réptil?");
	 		 				REQUIRE(t->current->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->ind == "010");

	 		 				t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
	 		 				t->insert(resposta_errada, Opcao::sim,TipoFrase::resposta);

	 		 				node* correto = t->current->Nao;
	 		 				node* errado = t->current->Sim;
					
	 		 				REQUIRE((correto->frase) == "sapo");
	 		 				REQUIRE((correto->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((correto->ind) == "0100");

	 		 				REQUIRE((errado->frase) == "cobra");
	 		 				REQUIRE((errado->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((errado->ind) == "0101");
	  				}
	  			}
  			}
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

  			
  			SECTION("O jogo erra no decorrer")
  			{
  				SECTION("Erra no sim")
  				{
	  				SECTION("A resposta correta é no sim")
	  				{
	  					std::string resposta_errada = t->current->Sim->frase;
	  					Opcao escolha_usuario = Opcao::sim;
	  					std::string resposta_usuario = "camaleão";
	  			
	 		 				t->insert("Ele se camufla?", Opcao::sim, TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Sim->frase == "Ele se camufla?");
	 		 				REQUIRE(t->current->Sim->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Sim->ind == "011");
	 		 		
	 		 				t->current = t->current->Sim;

	 		 				REQUIRE(t->current->frase == "Ele se camufla?");
	 		 				REQUIRE(t->current->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->ind == "011");

	 		 				t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
	 		 				t->insert(resposta_errada, Opcao::nao,TipoFrase::resposta);

	 		 				node* correto = t->current->Sim;
	 		 				node* errado = t->current->Nao;
					
	 		 				REQUIRE((correto->frase) == "camaleão");
	 		 				REQUIRE((correto->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((correto->ind) == "0111");

	 		 				REQUIRE((errado->frase) == "cobra");
	 		 				REQUIRE((errado->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((errado->ind) == "0110");	

	  				}

	  				SECTION("A resposta correta é no nao")
	  				{
	  					std::string resposta_errada = t->current->Sim->frase;
	  					Opcao escolha_usuario = Opcao::nao;
	  					std::string resposta_usuario = "camaleão";
	  			
	 		 				t->insert("Ele rasteja?", Opcao::sim, TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Sim->frase == "Ele rasteja?");
	 		 				REQUIRE(t->current->Sim->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Sim->ind == "011");
	 		 		
	 		 				t->current = t->current->Sim;

	 		 				REQUIRE(t->current->frase == "Ele rasteja?");
	 		 				REQUIRE(t->current->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->ind == "011");

	 		 				t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
	 		 				t->insert(resposta_errada, Opcao::sim,TipoFrase::resposta);

	 		 				node* correto = t->current->Nao;
	 		 				node* errado = t->current->Sim;
					
	 		 				REQUIRE((correto->frase) == "camaleão");
	 		 				REQUIRE((correto->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((correto->ind) == "0110");

	 		 				REQUIRE((errado->frase) == "cobra");
	 		 				REQUIRE((errado->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((errado->ind) == "0111");
	  				}
	  			}

	  			SECTION("Erra no nao")
	  			{
	  				SECTION("A resposta correta é no sim")
	  				{
	  					std::string resposta_errada = t->current->Nao->frase;
			  			Opcao escolha_usuario = Opcao::sim;
			  			std::string resposta_usuario = "ovelha";

			  			t->insert("Produz lã?", Opcao::nao, TipoFrase::pergunta);
			  			REQUIRE(t->current->Nao->frase == "Produz lã?");
			  			REQUIRE(t->current->Nao->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->Nao->ind == "010");

			  			t->current = t->current->Nao;

			  			REQUIRE(t->current->frase == "Produz lã?");
			  			REQUIRE(t->current->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->ind == "010");

			  			t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
			  			t->insert(resposta_errada, Opcao::nao, TipoFrase::resposta);

			  			node* correto = t->current->Sim;
			  			node* errado = t->current->Nao;

			  			REQUIRE((correto->frase) == "ovelha");
			  			REQUIRE((correto->tipo) == TipoFrase::resposta);
			  			REQUIRE((correto->ind) == "0101");

			  			REQUIRE((errado->frase) == "humano");
			  			REQUIRE((errado->tipo) == TipoFrase::resposta);
			  			REQUIRE((errado->ind) == "0100");
	  				}

	  				SECTION("A resposta correta é no nao")
	  				{
	  					std::string resposta_errada = t->current->Nao->frase;
			  			Opcao escolha_usuario = Opcao::nao;
			  			std::string resposta_usuario = "ovelha";

			  			t->insert("Esse animal fala?", Opcao::nao, TipoFrase::pergunta);
			  			REQUIRE(t->current->Nao->frase == "Esse animal fala?");
			  			REQUIRE(t->current->Nao->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->Nao->ind == "010");

			  			t->current = t->current->Nao;

			  			REQUIRE(t->current->frase == "Esse animal fala?");
			  			REQUIRE(t->current->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->ind == "010");

			  			t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
			  			t->insert(resposta_errada, Opcao::sim, TipoFrase::resposta);

			  			node* correto = t->current->Nao;
			  			node* errado = t->current->Sim;

			  			REQUIRE((correto->frase) == "ovelha");
			  			REQUIRE((correto->tipo) == TipoFrase::resposta);
			  			REQUIRE((correto->ind) == "0100");

			  			REQUIRE((errado->frase) == "humano");
			  			REQUIRE((errado->tipo) == TipoFrase::resposta);
			  			REQUIRE((errado->ind) == "0101");
	  				}
	  			}
  			}
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
  			
  			SECTION("O jogo erra no decorrer")
  			{	
  				SECTION("Erra no sim")
  				{
	  				SECTION("A resposta correta é no sim")
	  				{
	  					std::string resposta_errada = t->current->Sim->frase;
			  			Opcao escolha_usuario = Opcao::sim;
			  			std::string resposta_usuario = "garfo";

			  			t->insert("Pode ter ponta?", Opcao::sim, TipoFrase::pergunta);
			  			REQUIRE(t->current->Sim->frase == "Pode ter ponta?");
			  			REQUIRE(t->current->Sim->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->Sim->ind == "001");

			  			t->current = t->current->Sim;

			  			REQUIRE(t->current->frase == "Pode ter ponta?");
			  			REQUIRE(t->current->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->ind == "001");

			  			t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
			  			t->insert(resposta_errada, Opcao::nao, TipoFrase::resposta);

			  			node* correto = t->current->Sim;
			  			node* errado = t->current->Nao;

			  			REQUIRE((correto->frase) == "garfo");
			  			REQUIRE((correto->tipo) == TipoFrase::resposta);
			  			REQUIRE((correto->ind) == "0011");

			  			REQUIRE((errado->frase) == "copo");
			  			REQUIRE((errado->tipo) == TipoFrase::resposta);
			  			REQUIRE((errado->ind) == "0010");		
		  			}

	  				SECTION("A resposta correta é no nao")
	  				{
	  					std::string resposta_errada = t->current->Sim->frase;
	  					Opcao escolha_usuario = Opcao::nao;
	  					std::string resposta_usuario = "garfo";
	  			
	 		 				t->insert("Ele carrega comida líquida?", Opcao::sim, TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Sim->frase == "Ele carrega comida líquida?");
	 		 				REQUIRE(t->current->Sim->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Sim->ind == "001");
	 		 		
	 		 				t->current = t->current->Sim;

	 		 				REQUIRE(t->current->frase == "Ele carrega comida líquida?");
	 		 				REQUIRE(t->current->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->ind == "001");

	 		 				t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
	 		 				t->insert(resposta_errada, Opcao::sim,TipoFrase::resposta);

	 		 				node* correto = t->current->Nao;
	 		 				node* errado = t->current->Sim;
					
	 		 				REQUIRE((correto->frase) == "garfo");
	 		 				REQUIRE((correto->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((correto->ind) == "0010");

	 		 				REQUIRE((errado->frase) == "copo");
	 		 				REQUIRE((errado->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((errado->ind) == "0011");
	  				}
  				}

  				SECTION("Erra no nao")
  				{
	  				SECTION("A resposta correta é no sim")
	  				{
	  					std::string resposta_errada = t->current->Nao->frase;
			  			Opcao escolha_usuario = Opcao::sim;
			  			std::string resposta_usuario = "serra";

			  			t->insert("Ele corta?", Opcao::nao, TipoFrase::pergunta);
			  			REQUIRE(t->current->Nao->frase == "Ele corta?");
			  			REQUIRE(t->current->Nao->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->Nao->ind == "000");

			  			t->current = t->current->Nao;

			  			REQUIRE(t->current->frase == "Ele corta?");
			  			REQUIRE(t->current->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->ind == "000");

			  			t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
			  			t->insert(resposta_errada, Opcao::nao, TipoFrase::resposta);

			  			node* correto = t->current->Sim;
			  			node* errado = t->current->Nao;

			  			REQUIRE((correto->frase) == "serra");
			  			REQUIRE((correto->tipo) == TipoFrase::resposta);
			  			REQUIRE((correto->ind) == "0001");

			  			REQUIRE((errado->frase) == "martelo");
			  			REQUIRE((errado->tipo) == TipoFrase::resposta);
			  			REQUIRE((errado->ind) == "0000");
		  			}

	  				SECTION("A resposta correta é no nao")
	  				{
	  					std::string resposta_errada = t->current->Nao->frase;
			  			Opcao escolha_usuario = Opcao::nao;
			  			std::string resposta_usuario = "serra";

			  			t->insert("Ele serve para pregar?", Opcao::nao, TipoFrase::pergunta);
			  			REQUIRE(t->current->Nao->frase == "Ele serve para pregar?");
			  			REQUIRE(t->current->Nao->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->Nao->ind == "000");

			  			t->current = t->current->Nao;

			  			REQUIRE(t->current->frase == "Ele serve para pregar?");
			  			REQUIRE(t->current->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->ind == "000");

			  			t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
			  			t->insert(resposta_errada, Opcao::sim, TipoFrase::resposta);

			  			node* correto = t->current->Nao;
			  			node* errado = t->current->Sim;

			  			REQUIRE((correto->frase) == "serra");
			  			REQUIRE((correto->tipo) == TipoFrase::resposta);
			  			REQUIRE((correto->ind) == "0000");

			  			REQUIRE((errado->frase) == "martelo");
			  			REQUIRE((errado->tipo) == TipoFrase::resposta);
			  			REQUIRE((errado->ind) == "0001");
	  				}
	  			}
  			}
  		}

  		SECTION("A resposta correta é no nao")
  		{
				std::string resposta_errada = t->current->Nao->frase;
  			Opcao escolha_usuario = Opcao::nao;
  			std::string resposta_usuario = "copo";

  			t->insert("É uma ferramenta de trabalho?", Opcao::nao, TipoFrase::pergunta);
  			REQUIRE(t->current->Nao->frase == "É uma ferramenta de trabalho?");
  			REQUIRE(t->current->Nao->tipo == TipoFrase::pergunta);
  			REQUIRE(t->current->Nao->ind == "00");

  			t->current = t->current->Nao;

  			REQUIRE(t->current->frase == "É uma ferramenta de trabalho?");
  			REQUIRE(t->current->tipo == TipoFrase::pergunta);
  			REQUIRE(t->current->ind == "00");

  			t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
  			t->insert(resposta_errada, Opcao::sim, TipoFrase::resposta);

  			node* correto = t->current->Nao;
  			node* errado = t->current->Sim;

  			REQUIRE((correto->frase) == "copo");
  			REQUIRE((correto->tipo) == TipoFrase::resposta);
  			REQUIRE((correto->ind) == "000");

  			REQUIRE((errado->frase) == "martelo");
  			REQUIRE((errado->tipo) == TipoFrase::resposta);
  			REQUIRE((errado->ind) == "001");
  			
	  		SECTION("O jogo erra no decorrer")
	  		{
	  			SECTION("Erra no sim")
	  			{
		  			SECTION("A resposta correta é no sim")
		  			{
		  				std::string resposta_errada = t->current->Sim->frase;
			  			Opcao escolha_usuario = Opcao::sim;
			  			std::string resposta_usuario = "prego";

			  			t->insert("Ele é martelado?", Opcao::sim, TipoFrase::pergunta);
			  			REQUIRE(t->current->Sim->frase == "Ele é martelado?");
			  			REQUIRE(t->current->Sim->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->Sim->ind == "001");

			  			t->current = t->current->Sim;

			  			REQUIRE(t->current->frase == "Ele é martelado?");
			  			REQUIRE(t->current->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->ind == "001");

			  			t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
			  			t->insert(resposta_errada, Opcao::nao, TipoFrase::resposta);

			  			node* correto = t->current->Sim;
			  			node* errado = t->current->Nao;

			  			REQUIRE((correto->frase) == "prego");
			  			REQUIRE((correto->tipo) == TipoFrase::resposta);
			  			REQUIRE((correto->ind) == "0011");

			  			REQUIRE((errado->frase) == "martelo");
			  			REQUIRE((errado->tipo) == TipoFrase::resposta);
			  			REQUIRE((errado->ind) == "0010");		
		  			}
		  		
		  			SECTION("A resposta correta é no nao")
		  			{
		  				std::string resposta_errada = t->current->Sim->frase;
	  					Opcao escolha_usuario = Opcao::nao;
	  					std::string resposta_usuario = "prego";
	  			
	 		 				t->insert("Ele martela?", Opcao::sim, TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Sim->frase == "Ele martela?");
	 		 				REQUIRE(t->current->Sim->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->Sim->ind == "001");
	 		 		
	 		 				t->current = t->current->Sim;

	 		 				REQUIRE(t->current->frase == "Ele martela?");
	 		 				REQUIRE(t->current->tipo == TipoFrase::pergunta);
	 		 				REQUIRE(t->current->ind == "001");

	 		 				t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
	 		 				t->insert(resposta_errada, Opcao::sim,TipoFrase::resposta);

	 		 				node* correto = t->current->Nao;
	 		 				node* errado = t->current->Sim;
					
	 		 				REQUIRE((correto->frase) == "prego");
	 		 				REQUIRE((correto->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((correto->ind) == "0010");

	 		 				REQUIRE((errado->frase) == "martelo");
	 		 				REQUIRE((errado->tipo) == TipoFrase::resposta);
	 		 				REQUIRE((errado->ind) == "0011");
		  			}
		  		}
		  		
		  		SECTION("Erra no nao")
	  			{
		  			SECTION("A resposta correta é no sim")
		  			{
	  					std::string resposta_errada = t->current->Nao->frase;
			  			Opcao escolha_usuario = Opcao::sim;
			  			std::string resposta_usuario = "colher";

			  			t->insert("Ele se usa em sopa?", Opcao::nao, TipoFrase::pergunta);
			  			REQUIRE(t->current->Nao->frase == "Ele se usa em sopa?");
			  			REQUIRE(t->current->Nao->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->Nao->ind == "000");

			  			t->current = t->current->Nao;

			  			REQUIRE(t->current->frase == "Ele se usa em sopa?");
			  			REQUIRE(t->current->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->ind == "000");

			  			t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
			  			t->insert(resposta_errada, Opcao::nao, TipoFrase::resposta);

			  			node* correto = t->current->Sim;
			  			node* errado = t->current->Nao;

			  			REQUIRE((correto->frase) == "colher");
			  			REQUIRE((correto->tipo) == TipoFrase::resposta);
			  			REQUIRE((correto->ind) == "0001");

			  			REQUIRE((errado->frase) == "copo");
			  			REQUIRE((errado->tipo) == TipoFrase::resposta);
			  			REQUIRE((errado->ind) == "0000");
		  			}
		  		
		  			SECTION("A resposta correta é no nao")
		  			{
	  					std::string resposta_errada = t->current->Nao->frase;
			  			Opcao escolha_usuario = Opcao::nao;
			  			std::string resposta_usuario = "colher";

			  			t->insert("Ele é um recipiente?", Opcao::nao, TipoFrase::pergunta);
			  			REQUIRE(t->current->Nao->frase == "Ele é um recipiente?");
			  			REQUIRE(t->current->Nao->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->Nao->ind == "000");

			  			t->current = t->current->Nao;

			  			REQUIRE(t->current->frase == "Ele é um recipiente?");
			  			REQUIRE(t->current->tipo == TipoFrase::pergunta);
			  			REQUIRE(t->current->ind == "000");

			  			t->insert(resposta_usuario, escolha_usuario, TipoFrase::resposta);
			  			t->insert(resposta_errada, Opcao::sim, TipoFrase::resposta);

			  			node* correto = t->current->Nao;
			  			node* errado = t->current->Sim;

			  			REQUIRE((correto->frase) == "colher");
			  			REQUIRE((correto->tipo) == TipoFrase::resposta);
			  			REQUIRE((correto->ind) == "0000");

			  			REQUIRE((errado->frase) == "copo");
			  			REQUIRE((errado->tipo) == TipoFrase::resposta);
			  			REQUIRE((errado->ind) == "0001");
		  			}
		  		}
	  		}	
  		}
  	}
  }
  delete t;
}
