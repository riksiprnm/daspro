#include <stdio.h>
#include <stdlib.h>

/* Nama : Dandy Candra Oktaviano
   NPM : 200710670
   Kelas: B
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
    int jam,tarif;
    int gajiKotor,gajiReguler,upahLembur,totalLembur;
    
    printf("\n Jam Kerja : ");scanf("%d", &jam); 
    printf("\n Tarif : ");scanf("%d", &tarif); 
    
    if(jam<=40){
        gajiReguler = jam*tarif;
        upahLembur = 0;
        gajiKotor = gajiReguler+upahLembur;
    }else{
        totalLembur = jam-40;
        gajiReguler = 40*tarif;
        upahLembur = totalLembur*tarif*50;
        gajiKotor = gajiReguler+upahLembur;
    }
    
    printf("\n Gaji Reguler : Rp.%d,00 ",gajiReguler );
    printf("\n Upah Lembur : Rp.%d,00 ",upahLembur);
    printf("\n Gaji Kotor : Rp.%d,00 ",gajiKotor );
    
    return 0;
}
