#ifndef _OPERACOES_
#define _OPERACOES_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct est_med EST_MED;

struct est_med {
  char nome[50];
  int codigo;
  float valor;
};

int criaArquivo(EST_MED med) {

  FILE *arquivo;
  arquivo = fopen("EstoqueMed.bin", "ab+");
  if (arquivo == NULL) {
    return 0;
  } else {
    fwrite(&med, sizeof(EST_MED), 1, arquivo);
    fclose(arquivo);
    return 1;
  }
}

void buscaMed(int busca) {
  FILE *arquivo;
  struct est_med cadastro;
  int teste;
  int controle = 0;
  arquivo = fopen("EstoqueMed.bin", "rb");
  if (arquivo == NULL) {
    printf("Nao foi possivel abrir arquivo.");
  } else {
    while (!feof(arquivo)) {
      teste = fread(&cadastro, sizeof(EST_MED), 1, arquivo);
      if (teste != 0) {
        if (busca == cadastro.codigo) {
          printf("\nCódigo: %d\n", cadastro.codigo);
          printf("Medicamento: %s\n", cadastro.nome);
          printf("Valor: R$ %0.2f\n", cadastro.valor);
          controle = 1;
        }
      }
    }
    fclose(arquivo);
  }
  if (controle != 1) {
    printf("Produto não localizado");
  }
}

void estoque() {
  FILE *arquivo;
  struct est_med cadastro;
  int controle;
  arquivo = fopen("EstoqueMed.bin", "rb");
  if (arquivo == NULL) {
    printf("Acesso negado.");
  } else {
    while (!feof(arquivo)) {
      controle = fread(&cadastro, sizeof(EST_MED), 1, arquivo);
      if (controle != 0) {
        printf("\nCódigo: %d\n", cadastro.codigo);
        printf("Medicamento: %s\n", cadastro.nome);
        printf("Valor: R$ %0.2f\n", cadastro.valor);
        printf("\n");
      }
    }
  }
  fclose(arquivo);
}

void estatisticas() {
  FILE *arquivo;
  struct est_med cadastro;
  int teste;
  int quantidade = 0;
  float media = 0;
  char maiorValor[50];
  char menorValor[50];
  float maRS, meRS;

  arquivo = fopen("EstoqueMed.bin", "rb");
  if (arquivo == NULL) {
    printf("Nao foi possivel abrir arquivo.");
  } else {
    while (!feof(arquivo)) {
      teste = fread(&cadastro, sizeof(EST_MED), 1, arquivo);
      if (teste != 0) {
        quantidade++;
        media += cadastro.valor;
        if (quantidade == 1) {
          strcpy(maiorValor, cadastro.nome);
          strcpy(menorValor, cadastro.nome);
          maRS = cadastro.valor;
          meRS = cadastro.valor;
        } else {
          if (cadastro.valor > maRS) {
            strcpy(maiorValor, cadastro.nome);
            maRS = cadastro.valor;
          }
          if (cadastro.valor < meRS) {
            strcpy(menorValor, cadastro.nome);
            meRS = cadastro.valor;
          }
        }
      }
    }
  }

  media /= (float)quantidade;
  printf("Quantidade de medicamentos em estoque: %d\n", quantidade);
  printf("Media de preço dos medicamentos: %0.2f\n", media);
  printf("Medicamento de maior valor: %s\n", maiorValor);
  printf("Medicamento de menor valor: %s\n", menorValor);
  fclose(arquivo);
}

void apagaMed(int codigo) {

  FILE *arquivo;
  arquivo = fopen("EstoqueMed.bin", "rb");
  FILE *novoArquivo = fopen("NovoEstoqueMed.bin", "ab+");
  struct est_med cadastro;

  while (!feof(arquivo)) {
    fread(&cadastro, sizeof(EST_MED), 1, arquivo);
    if (codigo != cadastro.codigo) {
      fwrite(&cadastro, sizeof(EST_MED), 1, novoArquivo);
    }
  }
  printf("\nMedicamento excluido com sucesso.");
  fclose(novoArquivo);
  fclose(arquivo);
  remove("EstoqueMed.bin");
  rename("NovoEstoqueMed.bin", "EstoqueMed.bin");
}

#endif //_OPERACOES_
