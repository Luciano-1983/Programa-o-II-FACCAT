#include "opcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int codigo;
  int resp;
  struct est_med med;

  printf("\nBEM VINDO AO SISTEMA DE ESTOQUE DE MEDICAMENTOS\n");

  do {
    printf("\n______________________________________________________\n\n");
    printf("Digite a opção desejada:\n\n");
    printf("1-Cadastrar medicamento\n");
    printf("2-Apresentar lista dos medicamentos\n");
    printf("3-Localizar medicamento\n");
    printf("4-Excluir medicamento\n");
    printf("5-Informações adicionais\n");
    printf("6-Fechar o programa\n");
    printf("Opcao: ");
    scanf("%d", &resp);
    getchar();

    switch (resp) {

    case 1:
      printf("\nCadastro de Medicamentos:\n\n");
      printf("Informe o código do medicamento: ");
      scanf("%d", &med.codigo);
      getchar();
      printf("Informe o nome do medicamento: ");
      fgets(med.nome, 50, stdin);
      med.nome[strlen(med.nome) - 1] = '\0';
      fflush(stdin);
      printf("Informe a valor do medicamento: ");
      scanf("%f", &med.valor);
      getchar();

      int confirmacao = criaArquivo(med);
      if (confirmacao == 1) {
        printf("Cadastro ok.\n");
      } else {
        printf("Cadastro invalido, insira novos dados.\n");
      }
      break;

    case 2:
      printf("\nLista do estoque de medicamentos:\n\n");
      estoque();
      break;

    case 3:
      printf("\nLocalizar medicamentos:\n\n");
      printf("Informe o código desejado: ");
      scanf("%d", &codigo);
      getchar();
      buscaMed(codigo);
      break;

    case 4:
      printf("\nExcluir medicamento:\n\n");
      printf("Informe o código do medicamento a ser excluído: ");
      scanf("%d", &codigo);
      getchar();
      apagaMed(codigo);
      break;

    case 5:
      printf("\nInformações adicionais:\n\n");
      estatisticas();
      break;

    case 6:
      printf("\nPrograma encerrado!\n");
      break;

    default:
      printf("Comando inválido.\n");
      break;
    }

    printf("\n");
    printf("\n");

  } while (resp != 6);
}