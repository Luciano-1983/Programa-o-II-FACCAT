#include <stdio.h>

int main() {
    int numero, idade;
    char nome[256], sobrenome[256];
    printf("Digite seu nome: ");
    scanf("%s", nome);
    getchar();
    printf("Digite seu sobrenome: ");
    scanf("%s", sobrenome);
    getchar();
    printf("Digite o ano de seu nascimento: ");
    scanf("%d", &numero);
    idade = 2022-numero;
    printf("Seu nome completo é %s %s e sua idade é %d", nome,sobrenome,idade);
    return 0;
}

