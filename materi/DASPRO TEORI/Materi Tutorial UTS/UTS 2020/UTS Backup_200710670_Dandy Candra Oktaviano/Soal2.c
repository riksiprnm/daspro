#include <stdio.h>
#include <stdlib.h>

/* Nama : Dandy Candra Oktaviano
   NPM : 200710670
   Kelas: B
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
    int i,j;
    int k = 4;
    for(i=1;i<=5;i++){
    	
                for(j=1;j<=k;j++){
                        printf("*");
                    }
                    
            if(i>5/2){
                k=k-1;
            }else{
            	k=k+1;
            }
        printf("\n");
    }
    return 0;
}


