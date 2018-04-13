#ifndef ARVORE_H
#define ARVORE_H
 
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
 
 
/*! \class Opcao
    Entidade que indica se a resposta referente ou 
    a resposta de uma pergunta, ou a resposta apre-
    sentada pelo programa; eh sim ou nao.
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
 
/*! Entidade tipo node(Nó)
    
    Entidade que representa a frase que compora
    o jogo. Ele eh responsavel tanto por armazenar
    o que o usuario insere quanto interagir com ele
    conforme ele joga e preenche a arvore.
 
    Segue-se a seguinte estrutura:
    um node filho a esquerda(um nao) eh
    expresso por meio do indice do pai mais o caracter '0'; enquanto
    a direita, por meio do indice do pai mais o caracter '1'. A raiz
    eh sempre representato pelo '0'. Ou seja, o filho a esquerda da raiz
    sera "00", que por sua vez, seu filho a direita sera "001".
*/ 
typedef struct node
{
  /*! Indice do node
 
      Segue-se a seguinte estrutura:
      um node filho a esquerda(um nao) eh
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
        ele chama a funcao destroy_tree private com o current como parametro.
    */
    void eliminate();
 
    // ----------------------- Test functions-------------------------------// 
 
    node* return_root();
    node* return_current();
 
    /*! Node current(atual)
 
        Indica em qual parte da arvore o jogador
        estara durante o jogo
    */
    node* current;
    /*! Node raiz
 
        Indica a primeira pergunta do jogo.
    */
    node* root;  
 
  private:
    void insert(std::string frase_entrada, 
                Opcao opcao_entrada,
                TipoFrase tipo_entrada,
                node *leaf);
    void destroy_tree(node *leaf);
 
};
 
#endif

