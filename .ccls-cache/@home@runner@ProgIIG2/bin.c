#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opcoes.h"




int main() {
    int matricula;
    int resp;
    struct cad_aluno aluno;
 
 
    
    do {
        printf("Digite a opcao desejada:\n");
        printf("1-Apresentar todo conteudo do arquivo\n");
        printf("2-Apresentar conteudo de um registro\n");
        printf("3-Cadastrar um registro\n");
        printf("4-Estatisticas\n");
        printf("5-Fechar o programa\n");
        printf("Opcao: ");
        scanf("%d",&resp);
        getchar();
        switch (resp) {
            case 1:
                printf("\nTodo conteudo:\n\n");
                apresentaCad();
                break;
                
                
            case 2:
                printf("\nBuscar matricula:\n\n");
                printf("Informe a matricula desejada: ");
                scanf("%d",&matricula);
                getchar();
                buscaMatricula(matricula);
                break;
                
                
            case 3:
                printf("\nCadastro de alunos:\n\n");
                printf("Informe a matricula: ");
                scanf("%d",&aluno.matricula);
                getchar();
                printf("Informe o nome: ");
                fgets(aluno.nome,50,stdin);
                aluno.nome[strlen(aluno.nome)-1] = '\0';
                fflush(stdin);
                printf("Informe a nota: ");
                scanf("%f",&aluno.nota);
                getchar();

                int confirmacao = criaArquivo(aluno);
                if(confirmacao == 1){
                    printf("Cadastro ok.\n");
                }else{
                    printf("Cadastro invalido, insira novos dados.\n");
                }
                break;
                
                
            case 4:
                printf("\nEstatisticas:\n\n");
                estatisticas();
                break;
                
                
            case 5:
                printf("\nPrograma encerrado!\n");
                break;
                
                
            default:
                printf("Comando invalido.\n");
                break;
        }
        
        
        
        
        
        printf("\n");
        printf("\n");
    }while(resp != 5);
}