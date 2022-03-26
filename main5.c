#include <stdio.h>
#include <math.h>

int main() {
  
    int limite, i;
    float j;
    limite = 1000;
    
  for (i = 1; i <= limite; i++) {
    j = sqrt(i);
    if(j==(int)j) 
      if(i%2!=0)
      printf("%d\n", i);    
  }        
            
    return 0;
}
