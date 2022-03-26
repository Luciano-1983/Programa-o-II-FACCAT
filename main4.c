#include <stdio.h>

int main() {
    
    char letra;
  
  printf("Digite uma letra do alfabeto: ");
    scanf("%c", &letra);
    
  switch( letra ) { 
      case 'a': 
      printf("Essa letra é uma vogal!"); 
      break; 
      case 'e': 
      printf("Essa letra é uma vogal!"); 
      break; 
      case 'i': 
      printf("Essa letra é uma vogal!"); 
      break;
      case 'o': 
      printf("Essa letra é uma vogal!"); 
      break;
      case 'u': 
      printf("Essa letra é uma vogal!"); 
      break;
    default:
      printf("Essa letra é uma consoante!");
  }

    return 0;
}

