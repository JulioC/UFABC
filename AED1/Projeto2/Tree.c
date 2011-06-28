#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

struct TreeNode {
	TREE_TYPE value;
	struct TreeNode *left;
	struct TreeNode *right;
};

Tree TreeNodeBuild(TREE_TYPE val, Tree left, Tree right) {
	Tree tmp = (Tree)malloc(sizeof(struct TreeNode));
  if(NULL == tmp) return NULL;
  
	tmp->value = val;
	tmp->left = left;
	tmp->right = right;
  
	return tmp;
}

Tree TreeBuild(TREE_TYPE inorder[], TREE_TYPE auxorder[], enum TreeOrders auxtype, int len) {
  // Caso o comprimento seja 0, não temos o que analisar
  if(len < 1) return NULL;
  
  int r;
  TREE_TYPE rootval;
  Tree left, right;
  
  // Na pre-ordem, o valor da raiz é sempre o primeiro da lista
  // Na pós-ordem, esse valor é sempre o último
  if(Tree_preOrder == auxtype) {
    rootval = auxorder[0];
    // Pulando o valor da raiz, será mais fácil obter as sub arvores
    auxorder += 1;
  } else if(Tree_postOrder == auxtype) {
    rootval = auxorder[len - 1];
  } else {
    // O tipo de ordem auxiliar é inválido, então retornar
    return NULL;
  }
  
  // Encontra em que posição da lista em-ordem está a raiz
  for(r = 0; r < len; ++r) {
    if(rootval == inorder[r]) break;
  }
  
  // A raiz fica entre a sub-arvore esquerda e a direita na lista em ordem
  // Na lista auxiliar, os elementos da sub arvore tambem ficam agrupados
  left = TreeBuild(inorder, auxorder, auxtype, r);
  right = TreeBuild((inorder + r + 1), (auxorder + r), auxtype, (len - r - 1));    
  
  return TreeNodeBuild(rootval, left, right);
}

void TreeDestroy(Tree* tree) {
  if(NULL == (*tree)) return;
  
  TreeDestroy(&((*tree)->left));
  TreeDestroy(&((*tree)->right));
  
  free(*tree);
  *tree = NULL;
}

int TreeIsBST(Tree tree) {
  if(NULL != tree->left && tree->left->value > tree->value) return 0;
  if(NULL != tree->right && tree->right->value < tree->value) return 0;
  
  return (NULL == tree->left  || TreeIsBST(tree->left)) && (NULL == tree->right || TreeIsBST(tree->right));
}

void TreePrint_(Tree tree, int depth) {
  if(NULL == tree) return;
  int i;
  
  TreePrint_(tree->right, depth+1);
  
  for(i = 0; i < depth; ++i) {
    printf(" ");
  }
  printf(TREE_PRINTF, tree->value);
  printf("\n");
  
  TreePrint_(tree->left, depth+1);
}

void TreePrint(Tree tree) {
  TreePrint_(tree, 0);
}

int TreeTraversal(Tree tree, enum TreeOrders type, TREE_TYPE buffer[], int maxlen) {
  if(maxlen < 1 || NULL == tree) return 0;

  int written = 0;
  
  if(Tree_preOrder == type) {
    buffer[written++] = tree->value;
  }
  
  written += TreeTraversal(tree->left, type, (buffer+written), (maxlen-written));
  
  if(Tree_inOrder == type) {
    buffer[written++] = tree->value;
  }
  
  written += TreeTraversal(tree->right, type, (buffer+written), (maxlen-written));
  
  if(Tree_postOrder == type) {
    buffer[written++] = tree->value;
  }
  
  return written;
}