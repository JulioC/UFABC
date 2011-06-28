#ifndef CHAMADAS_H_
#define CHAMADAS_H_

typedef struct t_Chamada Chamada;

/* Adiciona uma chamada em espera
 * Argumentos:
 * - ch: Ponteiro para a fila de chamadas
 * - tel: String com o numero do telefone
 * - val: Valor da chamada
 */
void ChEspera(Chamada **ch, const char *tel, float val);

/* Obtem o telefone da próxima chamada em espera e remove-a da fila
 * Argumentos:
 * - ch: Ponteiro para a fila de chamadas atual
 * - buffer: Ponteiro para o buffer para guarda o telefone da chamada
 * Retorno: numero de caracteres escritos em tel, 0 se a lista for vazia
 */
int ChRetoma(Chamada **ch, char *tel);

#endif