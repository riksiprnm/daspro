#include <stdio.h>
#include <stdlib.h>

/* Nama : Dandy Candra Oktaviano
   NPM : 200710670
   Kelas: B
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int andy=0,budi=1000,waktu=0;
    int jam,menit,sisaMenit,sisaJam,total;
    
    do{
        andy = andy + 75;
        budi = budi - 50;
       
        waktu = waktu + 1;
       
    }while(andy!=budi);
    
    waktu = waktu*3600;
    
    total = 3600*8+waktu;
    jam = total*1/3600;
    sisaJam = total%3600;
    menit = sisaJam*1/60;
    sisaMenit = sisaJam%60;
    
    printf("\n Mereka Akan Bertemu Pada Pukul : %d:%d:%d",jam,menit,sisaMenit);
    return 0;
}
