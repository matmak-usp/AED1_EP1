#include "listadeprodutos.c"

int main() {
  PLISTA f = criarLista();
  int id;
  int tipo;
  int quantidade;
  int valor;
  bool res;

  res=inserirNovoProduto(f,2,2,22,23);
  if(res)printf("Insercaoretornoutrue(1)\n");
  else printf("Insercaoretornoufalse(1)\n");

  res=inserirNovoProduto(f,4,2,4,4);
  if(res)printf("Insercaoretornoutrue(3)\n");
  else printf("Insercaoretornoufalse(2)\n");

  res=inserirNovoProduto(f,6,2,8,9);
  if(res)printf("Insercaoretornoutrue(4)\n");
  else printf("Insercaoretornoufalse(3)\n");

  res=inserirNovoProduto(f,3,2,22,23);
  if(res)printf("Insercaoretornoutrue(2)\n");
  else printf("Insercaoretornoufalse(4)\n");

  res=inserirNovoProduto(f,-5,6,7,8);
  if(res)printf("Insercaoretornoutrue(5)\n");
  else printf("Insercaoretornoufalse(5)\n");

  res=inserirNovoProduto(f,5,-6,7,8);
  if(res)printf("Insercaoretornoutrue(6)\n");
  else printf("Insercaoretornoufalse(6)\n");

  res=inserirNovoProduto(f,5,6,-7,8);
  if(res)printf("Insercaoretornoutrue(7)\n");
  else printf("Insercaoretornoufalse(7)\n");

  res=inserirNovoProduto(f,5,6,7,-8);
  if(res)printf("Insercaoretornoutrue(4)\n");
  else printf("Insercaoretornoufalse(8)\n");

  res=inserirNovoProduto(f,3,21,9,9);
  if(res)printf("Insercaoretornoutrue(2)\n");
  else printf("Insercaoretornoufalse(9)\n");

  exibirLog(f);

  res=removerItensDeUmProduto(f,4,1);
  if(res)printf("Remocaoretornoutrue(1)\n");
  else printf("Remocaoretornoufalse(1)\n");

  res=removerItensDeUmProduto(f,6,7);
  if(res)printf("Remocaoretornoutrue(2)\n");
  else printf("Remocaoretornoufalse(2)\n");

  res=removerItensDeUmProduto(f,3,22);
  if(res)printf("Remocaoretornoutrue(3)\n");
  else printf("Remocaoretornoufalse(3)\n");

  res=removerItensDeUmProduto(f,20,1);
  if(res)printf("Remocaoretornoutrue(4)\n");
  else printf("Remocaoretornoufalse(4)\n");

  res=removerItensDeUmProduto(f,5,10);
  if(res)printf("Remocaoretornoutrue(5)\n");
  else printf("Remocaoretornoufalse(5)\n");

  res=removerItensDeUmProduto(f,4,0);
  if(res)printf("Remocaoretornoutrue(6)\n");
  else printf("Remocaoretornoufalse(6)\n");

  exibirLog(f);

  res=atualizarValorDoProduto(f,6,1);
  if(res)printf("Atualizacaoretornoutrue(1)\n");
  else printf("Atualizacaoretornoufalse(1)\n");

  exibirLog(f);

  res=atualizarValorDoProduto(f,6,20);
  if(res)printf("Atualizacaoretornoutrue(2)\n");
  else printf("Atualizacaoretornoufalse(2)\n");

  exibirLog(f);

  res=atualizarValorDoProduto(f,6,600);
  if(res)printf("Atualizacaoretornoutrue(3)\n");
  else printf("Atualizacaoretornoufalse(3)\n");

  exibirLog(f);

  res=atualizarValorDoProduto(f,6,0);
  if(res)printf("Atualizacaoretornoutrue(4)\n");
  else printf("Atualizacaoretornoufalse(4)\n");

  exibirLog(f);

  res=atualizarValorDoProduto(f,6,-100);
  if(res)printf("Atualizacaoretornoutrue(5)\n");
  else printf("Atualizacaoretornoufalse(5)\n");

  res=atualizarValorDoProduto(f,61,600);
  if(res)printf("Atualizacaoretornoutrue(6)\n");
  else printf("Atualizacaoretornoufalse(6)\n");

  res=atualizarValorDoProduto(f,6,3);
  if(res)printf("Atualizacaoretornoutrue(7)\n");
  else printf("Atualizacaoretornoufalse(7)\n");

  res=atualizarValorDoProduto(f,4,200);
  if(res)printf("Atualizacaoretornoutrue(8)\n");
  else printf("Atualizacaoretornoufalse(8)\n");

  res=atualizarValorDoProduto(f,2,20);
  if(res)printf("Atualizacaoretornoutrue(9)\n");
  else printf("Atualizacaoretornoufalse(9)\n");

  exibirLog(f);

  /*printf("################# INSERINDO #######################\n");

  exibirLog(f);
  res = inserirNovoProduto(f, 2, 1, 22, 23);
  if(res) printf("Insercao retornou true (1)\n");
  else printf("Insercao retornou false (1)\n");
  exibirLog(f);
  res = inserirNovoProduto(f, 4, 4, 4, 4);
  if(res) printf("Insercao retornou true (2)\n");
  else printf("Insercao retornou false (2)\n");
  exibirLog(f);
  res = inserirNovoProduto(f, 6, 1, 8, 9);
  if(res) printf("Insercao retornou true (3)\n");
  else printf("Insercao retornou false (3)\n");
  exibirLog(f);
  res = inserirNovoProduto(f, 3, 1, 22, 23);
  if(res) printf("Insercao retornou true (4)\n");
  else printf("Insercao retornou false (4)\n");
  exibirLog(f);

  res = inserirNovoProduto(f, -5, 6, 7, 8);
  if(res) printf("Insercao retornou true (5)\n");
  else printf("Insercao retornou false (5)\n");
  exibirLog(f);

  res = inserirNovoProduto(f, 5, -6, 7, 8);
  if(res) printf("Insercao retornou true (6)\n");
  else printf("Insercao retornou false (6)\n");
  exibirLog(f);

  res = inserirNovoProduto(f, 5, 6, -7, 8);
  if(res) printf("Insercao retornou true (7)\n");
  else printf("Insercao retornou false (7)\n");
  exibirLog(f);

  res = inserirNovoProduto(f, 5, 6, 7, -8);
  if(res) printf("Insercao retornou true (8)\n");
  else printf("Insercao retornou false (8)\n");
  exibirLog(f);
 
  res = inserirNovoProduto(f, 3, 1, 9, 9);
  if(res) printf("Insercao retornou true (9)\n");
  else printf("Insercao retornou false (9)\n");
  exibirLog(f);


  printf("################# REMOVENDO #######################\n");
  res = removerItensDeUmProduto(f, 4, 1);
  if(res) printf("Remocao retornou true (1)\n");
  else printf("Remocao retornou false (1)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 2, 1);
  if(res) printf("Remocao retornou true (2)\n");
  else printf("Remocao retornou false (2)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 3, 1);
  if(res) printf("Remocao retornou true (3)\n");
  else printf("Remocao retornou false (3)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 3, 21);
  if(res) printf("Remocao retornou true (3)\n");
  else printf("Remocao retornou false (3)\n");
  exibirLog(f);


  res = removerItensDeUmProduto(f, 20, 1);
  if(res) printf("Remocao retornou true (4)\n");
  else printf("Remocao retornou false (4)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 5, 10);
  if(res) printf("Remocao retornou true (5)\n");
  else printf("Remocao retornou false (5)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 4, 0);
  if(res) printf("Remocao retornou true (6)\n");
  else printf("Remocao retornou false (6)\n");
  exibirLog(f);

  printf("################# ATUALIZANDO VALOR #######\n");

  res = atualizarValorDoProduto(f, 6, 1);
  if(res) printf("Atualizacao retornou true (1)\n");
  else printf("Atualizacao retornou false (1)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 6, 600);
  if(res) printf("Atualizacao retornou true (2)\n");
  else printf("Atualizacao retornou false (2)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 6, 20);
  if(res) printf("Atualizacao retornou true (3)\n");
  else printf("Atualizacao retornou false (3)\n");
  exibirLog(f);


  res = atualizarValorDoProduto(f, 6, 0);
  if(res) printf("Atualizacao retornou true (4)\n");
  else printf("Atualizacao retornou false (4)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 6, -100);
  if(res) printf("Atualizacao retornou true (5)\n");
  else printf("Atualizacao retornou false (5)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 61, 600);
  if(res) printf("Atualizacao retornou true (6)\n");
  else printf("Atualizacao retornou false (6)\n");
  exibirLog(f);

 

  res = atualizarValorDoProduto(f, 6, 3);
  if(res) printf("Atualizacao retornou true (7)\n");
  else printf("Atualizacao retornou false (7)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 4, 200);
  if(res) printf("Atualizacao retornou true (8)\n");
  else printf("Atualizacao retornou false (8)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 2, 20);
  if(res) printf("Atualizacao retornou true (9)\n");
  else printf("Atualizacao retornou false (9)\n");
  exibirLog(f);*/

  return 0;
}