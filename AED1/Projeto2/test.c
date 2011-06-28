/*
 * test.c
 * 
 * Teste das funcionalidades pedidas para o projeto.
 * Cria uma árvore a partir dos percursos:
 * ZVCDJNGHI (em ordem)
 * ZCJDVHIGN (pós ordem)
 * A partir da árvore, obtem uma lista e ordena ela com insertion sort
 */

#include <stdio.h>
#include <string.h>
#include "Tree.h"

void insertionSort(char arr[], int len);

int main(void) {
  char inorder[32] = "ZVCDJNGHI";
  char postorder[32] = "ZCJDVHIGN";
  char preorder[32] = {0};
  int written;
  Tree tree = TreeBuild(inorder, postorder, Tree_postOrder, strlen(inorder));
  
  printf("Arvore Resultante\n");
  TreePrint(tree);
  
  printf("\n");

  printf("ABB: %d\n", TreeIsBST(tree));
  
  printf("\n");
  
  written = TreeTraversal(tree, Tree_preOrder, preorder, 32);
  printf("Pre-ordem: %s\n", preorder);
  insertionSort(preorder, written);
  printf("Ordenado com insertionSort: %s\n", preorder);
  
  printf("\n");
  
  return 0;
}

void insertionSort(char arr[], int len) {
  int i, j, cur;
  for(i = 1; i < len; ++i) {
    cur = arr[i];
    for(j = i-1; j >= 0 && arr[j] > cur; --j) {
      arr[j+1] = arr[j];
    }
    arr[j+1] = cur;
  }
}