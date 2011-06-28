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

/* Cria um nó da árvore
 * Argumentos:
 * - val: valor do nós
 * - left: sub-árvore esquerda
 * - left: sub-árvore direita
 * Retorno: Ponteiro para a sub-árvore resultante
 */
Tree TreeNodeBuild(TREE_TYPE val, Tree left, Tree right);

/* Cria um árvore a partir de dois percursos dela
 * Argumentos:
 * - inorder: percurso em-ordem da árvore
 * - auxorder: percurso auxiliar [pós ou pré]
 * - auxtype: tipo do percurso auxiliar
 * Retorno: Ponteiro para a árvore resultante
 */
Tree TreeBuild(TREE_TYPE inorder[], TREE_TYPE auxorder[], enum TreeOrders auxtype, int len);

/* Libera o espaço na memória de uma árvore
 * Argumentos:
 * - tree: ponteiro para a árvore
 */
void TreeDestroy(Tree* tree);

/* Verifica se uma árvore é binária de busca
 * Argumentos:
 * - tree: árvore a ser verificada
 * Retorno: zero em caso de falha, não-zero caso contrário
 */
int TreeIsBST(Tree tree);

/* Imprime uma árvore binária
 * Argumentos:
 * - tree: árvore a ser verificada
 */
void TreePrint(Tree tree);

/* Obtem o percurso da árvore binária para um array
 * Argumentos:
 * - tree: árvore a ser percorrida
 * - type: tipo de percurso
 * - buffer: array para armazenar os valores
 * - maxlen: número máximo de valores a serem escritos
 * Retorno: o número de valores escritos no array
 */
int TreeTraversal(Tree tree, enum TreeOrders type, TREE_TYPE buffer[], int maxlen);

#endif