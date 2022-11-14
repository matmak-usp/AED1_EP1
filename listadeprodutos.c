/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2021                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP 1 - Lista Ligada de Produtos                               **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <numero USP>          **/
/**                                                                 **/
/*********************************************************************/
#include "listadeprodutos.h"

PLISTA criarLista(){
  PLISTA res = (PLISTA) malloc(sizeof(LISTADEPRODUTOS));
  int x;
  for (x=0;x<NUMTIPOS;x++){
    res->LISTADELISTAS[x]=(PONT) malloc(sizeof(REGISTRO));
    res->LISTADELISTAS[x]->id=-1;
    res->LISTADELISTAS[x]->quantidade=0;
    res->LISTADELISTAS[x]->valorUnitario=0;
    res->LISTADELISTAS[x]->proxProd=NULL;
  }
  return res;
}


int tamanho(PLISTA l){
  int tam = 0;
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual) {
      atual = atual->proxProd;
      tam++;
    }
  }
  return tam;
}

PONT buscarID(PLISTA l, int id){
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual) {
      if (atual->id == id) return atual;
      atual = atual->proxProd;
    }
  }
  return NULL;
}

PONT buscarIDTipo(PLISTA l, int id, int tipo){
  if (tipo<0 || tipo>=NUMTIPOS) return NULL;
  PONT atual = l->LISTADELISTAS[tipo]->proxProd;
  while (atual) {
    if (atual->id == id) return atual;
    atual = atual->proxProd;
  }
  return NULL;
}

void exibirLog(PLISTA f){
  int numElementos = tamanho(f);
  printf("Log lista [elementos: %i]\n", numElementos);
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    printf("  #TIPO: %i -> ", x);
    atual = f->LISTADELISTAS[x]->proxProd;
    while (atual){
      printf(" [%i;%i;%i;$%i]", atual->id, atual->quantidade, atual->valorUnitario, atual->quantidade*atual->valorUnitario);
      atual = atual->proxProd;
    }
    printf("\n");
  }
  printf("\n");
}

int consultarValorUnitario(PLISTA l, int id){
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual) {
      if (atual->id == id) return atual->valorUnitario;
      atual = atual->proxProd;
    }
  }
  return 0;
}

int calcularValorTotal(PONT prod) {
    return prod->quantidade * prod->valorUnitario;
}

PONT consultarProdutoAnteriorLista(PLISTA l, int tipo, PONT produto) 
{ 
    PONT atual = l->LISTADELISTAS[tipo]->proxProd;
    PONT anterior = l->LISTADELISTAS[tipo];
    
    if (atual == NULL)
        return anterior;
    
    int valorTotalProduto = calcularValorTotal(produto);
    while (atual) {
        if (atual == produto)
            return anterior;
        anterior = atual;
        atual = atual->proxProd;
    }
    return NULL;
}

PONT consultarProdutoAnteriorValorTotal(PLISTA l, int tipo, PONT prod) 
{
    int valorTotal = calcularValorTotal(prod);
    PONT atual = l->LISTADELISTAS[tipo]->proxProd;
    PONT anterior = l->LISTADELISTAS[tipo];
    
    if (atual == NULL)
        return anterior;
    
    while (atual) {
        if(calcularValorTotal(atual) >= valorTotal)
            return anterior;
        anterior = atual;
        atual = atual->proxProd;
    }  
}

bool removerProximoProduto(PONT prodAnterior) {
    PONT prodARemover = prodAnterior->proxProd;
    prodAnterior->proxProd = prodARemover->proxProd;
    free(prodARemover);
    return true;
}

int consultarTipoLista(PLISTA l, PONT prod) 
{
    for (int i = 0; i < NUMTIPOS; i++)
    {
        PONT produto = l->LISTADELISTAS[i]->proxProd;
        while (produto) {
            if (produto->id == prod->id) {
                return i;
            }
            produto = produto->proxProd;
        }
    }
}

bool inserirNovoProduto(PLISTA l, int id, int tipo, int quantidade, int valor)
{
    if (id < 1 || quantidade < 1 || valor < 1 || (tipo < 0 || tipo >= NUMTIPOS))
        return false;
    if (buscarID(l, id) != NULL)
        return false;
    
    REGISTRO* novoRegistro = (REGISTRO*) malloc(sizeof(REGISTRO));
    novoRegistro->id = id;
    novoRegistro->quantidade = quantidade;
    novoRegistro->valorUnitario = valor;

    PONT produtoLista = l->LISTADELISTAS[tipo]->proxProd;
    PONT antProd = antProd = l->LISTADELISTAS[tipo];    
    while (produtoLista) {
        if (calcularValorTotal(produtoLista) >= calcularValorTotal(novoRegistro))
            break;
        antProd = produtoLista;
        produtoLista = produtoLista->proxProd;
    }
    
    novoRegistro->proxProd = antProd->proxProd;
    antProd->proxProd = novoRegistro;

    return true;
}

bool removerItensDeUmProduto(PLISTA l, int id, int quantidade)
{
    if (id < 1 || quantidade < 1)
        return false;
    
    PONT produtoAlterado = buscarID(l, id);
    if (produtoAlterado == NULL || produtoAlterado->quantidade < quantidade)
        return false;
    
    int qtdAnterior = produtoAlterado->quantidade;
    produtoAlterado->quantidade -= quantidade;

    int tipo = consultarTipoLista(l, produtoAlterado);

    PONT produtoAnteriorAoAlterado = consultarProdutoAnteriorLista(l, tipo, produtoAlterado);

    if (produtoAlterado->quantidade == 0) 
        return removerProximoProduto(produtoAnteriorAoAlterado);

    if (calcularValorTotal(produtoAlterado) <= calcularValorTotal(produtoAnteriorAoAlterado)) {
        produtoAnteriorAoAlterado->proxProd = produtoAlterado->proxProd;

        PONT novoAnterior = consultarProdutoAnteriorValorTotal(l, tipo, produtoAlterado);
        produtoAlterado->proxProd = novoAnterior->proxProd;
        novoAnterior->proxProd = produtoAlterado;
    }    

    return true;
}


bool atualizarValorDoProduto(PLISTA l, int id, int valor)
{
    if (id < 0 || valor < 1)
        return false;
    
    PONT produtoAlterado = buscarID(l, id);
    if (produtoAlterado == NULL)
        return false;
    
    produtoAlterado->valorUnitario = valor;

    int tipo = consultarTipoLista(l, produtoAlterado);
    PONT produtoAnteriorAlterado = consultarProdutoAnteriorLista(l, tipo, produtoAlterado);

    if (calcularValorTotal(produtoAlterado) <= calcularValorTotal(produtoAnteriorAlterado)) {
        produtoAnteriorAlterado->proxProd = produtoAlterado->proxProd;

        PONT novoAnterior = consultarProdutoAnteriorValorTotal(l, tipo, produtoAlterado);
        produtoAlterado->proxProd = novoAnterior->proxProd;
        novoAnterior->proxProd = produtoAlterado;
    }
    else if (produtoAlterado->proxProd != NULL && calcularValorTotal(produtoAlterado) > calcularValorTotal(produtoAlterado->proxProd)) {
        PONT produtoMenorValor = produtoAlterado->proxProd;
        produtoAnteriorAlterado->proxProd = produtoMenorValor;

        if(produtoMenorValor->proxProd == NULL) {
            produtoMenorValor->proxProd = produtoAlterado;
            produtoAlterado->proxProd = NULL;
            return true;
        }

        while (produtoMenorValor)
        {
            if (produtoMenorValor->proxProd == NULL) {
                produtoAlterado->proxProd = NULL;
                produtoMenorValor->proxProd = produtoAlterado;
                break;
            }
            if (calcularValorTotal(produtoAlterado) <= calcularValorTotal(produtoMenorValor->proxProd)) {
                produtoAlterado->proxProd = produtoMenorValor->proxProd->proxProd;
                produtoMenorValor->proxProd = produtoAlterado;
                break;
            }
            produtoMenorValor = produtoMenorValor->proxProd;
        }
    }

    return true;
}