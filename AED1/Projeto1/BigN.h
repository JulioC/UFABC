/*
 * BigN.h 
 *
 * Cabecalho contendo os protótipos dos métodos e do tipo BigN
 *
 */

#ifndef BIGN_H_
#define BIGN_H_

typedef char byte;

struct BNAlg;

typedef struct BNAlg *BigN;

/* Cria um BigN a partir de uma variavel de tipo int
 * Argumentos:
 * - val: inteiro a ser convertido
 * Retorno: BigN resultante, NULL em caso de erro
 */
BigN BNFromInt(long long int val);

/* Cria um BigN a partir de algarismos em uma array
 * Argumentos:
 * - algs: array de algarismos
 * - len: quantidade de algarismos
 * Retorno: BigN resultante, NULL em caso de erro
 */
BigN BNFromArr(int* arr, int len);

/* Cria um BigN a partir de algarismos representados em uma string
 * Argumentos:
 * - str: string com os algarismos
 * Retorno: BigN resultante, NULL em caso de erro
 */
BigN BNFromStr(char* str);

/* Realiza a soma de dois BigN
 * Argumentos:
 * - n1, n2: elementos a serem somados
 * Retorno: BigN resultante, NULL em caso de erro
 */
BigN BNSum(BigN n1, BigN n2);

/* Soma uma array de BigN
 * Argumentos:
 * - arr: ponteiro para o primeiro elemento da array
 * - len: comprimento da array
 * Retorno: BigN resultante, NULL em caso de erro
 */
BigN BNSumArray(BigN *arr, int len);

/* Realiza a multiplicação de dois BigN
 * Argumentos:
 * - n1, n2: elementos a serem multiplicados
 * Retorno: BigN resultante, NULL em caso de erro
 */
BigN BNMult(BigN n1, BigN n2);

/* Obtem o numero de algarismos em um BigN 
 * Argumentos:
 * - num: BigN desejado
 * Retorno: comprimento do BigN
 */
 int BNLength(BigN num);
 
/* Verifica se n1 e n2 são iguais
 * Argumentos:
 * - n1, n2: elementos BigN a serem comparados
 * Retorno: 0: false, 1: true
 */ 
int BNEquals(BigN n1, BigN n2);

/* Obtem uma string com o valor de BigN
 * Argumentos: 
 * - num: BigN para converter
 * - str: ponteiro para o primeiro elemento da string
 * - maxlen: tamanho máximo da string
 */
void BNToStr(BigN num, char *str, int maxlen);

/* Imprime o valor de um BigN na tela
 * Argumentos:
 * - num: estrutura BigN a imprimir
 */
void BNPrint(BigN num);

/* Libera o espaço alocado para um BigN
 * Argumentos:
 * - num: BigN a ser destruido
 */
 void BNDestroy(BigN num);
 
#endif