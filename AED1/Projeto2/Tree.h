#ifndef TREE_H_
#define TREE_H_

#define TREE_TYPE char
#define TREE_PRINTF "%c"

enum TreeOrders {
  Tree_preOrder,
  Tree_inOrder,
  Tree_postOrder  
};

struct TreeNode;

typedef struct TreeNode *Tree;

/* Cria um n� da �rvore
 * Argumentos:
 * - val: valor do n�s
 * - left: sub-�rvore esquerda
 * - left: sub-�rvore direita
 * Retorno: Ponteiro para a sub-�rvore resultante
 */
Tree TreeNodeBuild(TREE_TYPE val, Tree left, Tree right);

/* Cria um �rvore a partir de dois percursos dela
 * Argumentos:
 * - inorder: percurso em-ordem da �rvore
 * - auxorder: percurso auxiliar [p�s ou pr�]
 * - auxtype: tipo do percurso auxiliar
 * Retorno: Ponteiro para a �rvore resultante
 */
Tree TreeBuild(TREE_TYPE inorder[], TREE_TYPE auxorder[], enum TreeOrders auxtype, int len);

/* Libera o espa�o na mem�ria de uma �rvore
 * Argumentos:
 * - tree: ponteiro para a �rvore
 */
void TreeDestroy(Tree* tree);

/* Verifica se uma �rvore � bin�ria de busca
 * Argumentos:
 * - tree: �rvore a ser verificada
 * Retorno: zero em caso de falha, n�o-zero caso contr�rio
 */
int TreeIsBST(Tree tree);

/* Imprime uma �rvore bin�ria
 * Argumentos:
 * - tree: �rvore a ser verificada
 */
void TreePrint(Tree tree);

/* Obtem o percurso da �rvore bin�ria para um array
 * Argumentos:
 * - tree: �rvore a ser percorrida
 * - type: tipo de percurso
 * - buffer: array para armazenar os valores
 * - maxlen: n�mero m�ximo de valores a serem escritos
 * Retorno: o n�mero de valores escritos no array
 */
int TreeTraversal(Tree tree, enum TreeOrders type, TREE_TYPE buffer[], int maxlen);

#endif