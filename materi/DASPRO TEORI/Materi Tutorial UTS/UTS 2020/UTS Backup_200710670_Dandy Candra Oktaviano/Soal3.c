#include <stdio.h>
#include <stdlib.h>

/* Nama : Dandy Candra Oktaviano
   NPM : 200710670
   Kelas: B
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int meter1,cm1,total1;
    int meter2,cm2,total2;
    int totalSeluruhnya,totalMeter,sisaMeter,sisaCm;
    
    																						
    printf("\nMasukkan Nilai Panjang Untuk yang pertama m dan cm  : \n");scanf("%d %d", &meter1,&cm1);
    
    																				
    printf("\nMasukkan Nilai Panjang Untuk yang kedua m dan cm : \n");scanf("%d %d", &meter2,&cm2);
    
    		
    meter1 = meter1*100;
    		
    total1 = meter1+cm1;
    

    meter2 = meter2*100;
    
			
    total2 = meter2+cm2;
    
    totalSeluruhnya = total1+total2;
    

    totalMeter=totalSeluruhnya/100;      

    sisaMeter=totalSeluruhnya%100;
    sisaCm=sisaMeter;
    
    printf("\n Jumlahnya : %dm %dcm ", totalMeter,sisaCm);
    
    return 0;
}
