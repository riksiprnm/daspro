#include <stdio.h>
#include <stdlib.h>

/* Nama : Dandy Candra Oktaviano
   NPM : 200710670
   Kelas: B
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
   int i,j,z=6;
   for(i = 1; i < 8; i++){
   	
   		for(j = 1; j<=z ; j++){
   			
   			printf("*");
   			
		   }
		   if(i < 4){
		   	 z--;
		   }else{
		   	 z++;
		   }
		   
		   printf("\n");
   	
   }
   
    return 0;
}
