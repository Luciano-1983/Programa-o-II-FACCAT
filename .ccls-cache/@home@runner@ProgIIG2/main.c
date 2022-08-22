#include <stdio.h>
#include <string.h>

int criarCadastro(char nome[50],int idade){
    char idadeString[10];
    char texto[50] = "";
    
    sprintf(idadeString,"%d",idade); 

    
    strcat(texto,nome);
    strcat(texto,", ");
    strcat(texto,idadeString);
    FILE *arquivo;
    arquivo = fopen("./Cadastro.txt", "a+") ;
    
    
    if ( arquivo == NULL ) {
        return 0;
    } else {
        if ( strlen(texto) > 0 ) {
            fputs(texto, arquivo) ;
            fputs("\n", arquivo) ;
        }
        fclose(arquivo) ;
        return 1;
    }

}

void todoConteudo(){
    FILE *arquivo ;
    char textoLido[200];
    arquivo = fopen("Cadastro.txt", "r") ;
    if ( arquivo == NULL ) {
        printf( "Impossivel abrir o arquivo." ) ;
    } else {
        while( fgets(textoLido, 200, arquivo ) != NULL ) {
            printf( "%s" , textoLido ) ;
        }
        fclose(arquivo) ;
    }

}

void umRegistro(int linha){
    
    int contaLinha =0;
    int controlador = 0;
    int controle = 0;
    FILE *arquivo ;
    char textoLido[200];
    char linhaArquivo[50];
    char linhaNome[50];
    char linhaIdade[10];
    
    int j = 0;
    
    arquivo = fopen("Cadastro.txt", "r") ;
    
    
    
    if ( arquivo == NULL ) {
        printf( "Impossivel abrir o arquivo." ) ;
    } else {
        while( fgets(textoLido, 200, arquivo ) != NULL ) {
            contaLinha++;
            if(contaLinha == linha){
                strcpy(linhaArquivo,textoLido);
                controlador = 1;
            }
        }
        fclose(arquivo) ;
    }
    if(controlador == 1){
        for (int i = 0; i < strlen(linhaArquivo); ++i) {
            if(linhaArquivo[i] == ','){
                controle = 1;
            }else{
                if(controle == 0){
                    linhaNome[i] = linhaArquivo[i];
                }else{
                    linhaIdade[j] = linhaArquivo[i];
                    j++;
                }
            }
        }
        
        printf("Nome: %s\n",linhaNome);
        printf("Idade: %s\n",linhaIdade);
       
    }else{
        printf("Linha nao encontrada") ;
    }
}






int main1() {
    int linha;
    int resp;
    char nome[50] = "";
    int idade;
    
    do {
        printf("Digite a opcao desejada:\n");
        printf("1-Apresentar todo conteudo do arquivo\n");
        printf("2-Apresentar conteudo de um registro\n");
        printf("3-Cadastrar um registro\n");
        printf("4-Fechar o programa\n");
        printf("Opçao: ");
        scanf("%d",&resp);
        getchar();
        switch (resp) {
            
            
            case 1:
                printf("\nTodo conteudo:\n");
                todoConteudo();
                break;
            
            
            case 2:
                printf("\nUm registro:\n");
                printf("Informe a linha a ser exibida: ");
                scanf("%d",&linha);
                getchar();
                umRegistro(linha);
                break;
            
            
            case 3:
                printf("\nCadastrar novo registro:\n");

                printf("Nome: ");
                fgets(nome,50,stdin);
                nome[strlen(nome)-1] = '\0';

                printf("Idade: ");
                scanf("%d",&idade);
                getchar();

                int confirmacao = criarCadastro(nome,idade);
                if(confirmacao == 1){
                    printf("Cadastro ok!\n");
                }else{
                    printf("Cadastro invalido, insira novos dados\n");
                }
                break;
            
            
            case 4:
                printf("\n\nFechar programa!\n");
                break;
            
            
            default:
                printf("Comando invalido.\n");
                break;
        }
        printf("\n");
        printf("\n");
    }while(resp != 4);
}