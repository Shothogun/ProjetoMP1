#ifndef ARVORE_H
#define ARVORE_H
 
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
 
 
/*! \class Opcao
    Entidade que indica se a resposta referente ou 
    a resposta de uma pergunta, ou a resposta apre-
    sentada pelo programa; é sim ou nao.
*/
enum class Opcao{nao, sim};
 
/*!  \class TipoFrase
    Entidade que indica se o Node envolvido
    expressa uma frase interrogativa ou afirmativa.
*/
enum class TipoFrase{pergunta,resposta};
 
/*! \struct child
    Entidade equivalente ao Node 
    \sa node 
*/
typedef struct node *child;

/*! \struct node_ponteiro
    Entidade equivalente ao Node 
    \sa node 
*/
typedef struct node *node_ponteiro;
 
/*! Entidade tipo node(Nó)
    
    Entidade que representa a frase que compora
    o jogo. Ele é responsável tanto por armazenar
    o que o usuario insere quanto interagir com ele
    conforme ele joga e preenche a arvore.
 
    Segue-se a seguinte estrutura:
    um node filho a esquerda(um nao) é
    expresso por meio do indice do pai mais o caracter '0'; enquanto
    a direita, por meio do indice do pai mais o caracter '1'. A raiz
    é sempre representato pelo '0'. Ou seja, o filho a esquerda da raiz
    sera "00", que por sua vez, seu filho a direita sera "001".
*/ 
typedef struct node
{
  /*! Indice do node
 
      Segue-se a seguinte estrutura:
      um node filho a esquerda(um nao) é
      expresso por meio do indice do pai mais o caracter '0'; enquanto
      a direita, por meio do indice do pai mais o caracter '1'.
    \sa node
  */
  std::string ind;
 
  /*! Tipo de frase contida no node
 
      Classifica-se a frase quanto a sua natureza:
      Interrogativa ou afirmarmativa, no caso, o objeto resposta da arvore.
  */
  TipoFrase tipo;
 
  /*!  Frase
      
      Expressa a frase que ela ira expressar ao usuario, ou 
      recebera dele.
  */
  std::string frase;
  
  /*!  Node filho tipo nao
 
      Presente na arvore como o filho a esquerda.
  */    
  child Nao;
  /*!  Node filho tipo sim
 
      Presente na arvore como o filho a direita.
  */
  child Sim;
} node;
 
/*! Entidade da arvore que compora o jogo
 
    Dotado de atributos relativo: aos dados interessantes
    ao funcionamento e interface do jogo; e aos dados que 
    possibilitarao sua implementacao
*/

class tree
{
  public:
    /*! Constructor
 
        Inicializa a arvore com a raiz no NULL e o node current como a raiz.
      \sa tree::current
    */
    tree();
    /*! Destructor 
 
        Elimina a arvore desde a raiz ate 
        todas as suas sub-arvores subjacentes.
    */
    ~tree();  
    /*! Insert

        Função responsável por receber tanto a resposta quanto pergunta inserida pelo usuário.
        Sua operação depende do tipo de conteúdo que ele irá colocar assim como aonde ele quer inserir,
        informações solicitadas durante o jogo.

    */
    void insert(std::string frase_entrada, 
          Opcao opcao_entrada,
          TipoFrase tipo_entrada); 
 
    /*!  Funcao destruir a arvore inteira
 
        Invocada ao ser encerrado o jogo. Chama
        a funcao destroy_tree private com a raiz como parametro.
    */
    void destroy_tree();
 
    /*! Funcao Eliminar a pergunta
 
        Executado quando o usuario solicitar o retiro
        de uma pergunta que a ele nao faz sentido. No caso,
        ele chama a funcao destroy_tree private com o filho do current como parametro.
        Se a pergunta eliminada é à direita, a sub-árvore filho sim é eliminada;
        caso contrário, a sub-árvore nao.
    */
    void eliminate(Opcao opcao_usuario);

    /*! Funcao salvar jogo
        
        Ao ser chamado, ele grava todas as informações referentes ao jogo em um
        arquivo txt, que pode ser recuperado depois. Recebe como parametro o nome do
        jogo que foi salvo.
    */
    int save_game(char* nome_arquivo);

    /*! Funcao ler arquivo
        
        Ele é uma funcao que lê o arquivo .txt e decodifica suas informações
        para formar a árvore. Dentro dele, ele chama a função decodifica_nodes.
        \sa decodifica_nodes()
    */
    int ler_arquivo(char* nome_arquivo);

    /*! Funcao decodifica nodes

        Essa função lê os dados do arquivo e interpreta, formando 
        a árvore que será usada no jogo.

    */
    int decodifica_nodes(std::string ind_entrada,
                         std::string tipo_entrada,
                         std::string frase_entrada);

    /*!  Funcao resetar current
      
          O node current é posto novamente na raiz da arvore no final do jogo
    */
    void reset_current();
 
    // ----------------------- Test functions-------------------------------// 
 
    /*! Funcao que retorna o node raiz
    */
    node* return_root();

    /*! Funcao que retorna o node current
    */
    node* return_current();

    /*! Retorna a frase do root
    */
    std::string return_root_frase();

    /*! Funcao usada para o processo de teste

        Ele coloca o current no seu filho à direita
    */
    void set_current(int i);

    /*! Funcao usada para o processo de teste

        Ele printa a árvore na forma transversal pre-order
    */
    void pre_order_printing();

    /*! Node current(atual)
 
        Indica em qual parte da arvore o jogador
        estara durante o jogo
    */
    node_ponteiro current;

 
  private:
    void insert(std::string frase_entrada, 
                Opcao opcao_entrada,
                TipoFrase tipo_entrada,
                node *leaf);
    void destroy_tree(node *leaf);
    void pre_order_printing(node* show_node);
    void save_game(char* nome_arquivo, node* save);
    
    /*! Node raiz
        Indica a primeira pergunta do jogo.
    */
    node_ponteiro root;  
 
 
};
 
#endif

