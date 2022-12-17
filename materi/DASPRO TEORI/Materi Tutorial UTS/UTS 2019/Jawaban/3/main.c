#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float nilai,rataBagus=0,rataJelek=0,rataTotal;
	int b=0,j=0,a=0,t;
	while(a<5){
		printf("\n Masukkan Nilai : "); scanf("%f",&nilai);
		if(nilai>=0 && nilai<=100){
			if(nilai>=50){
				printf("\n %f", nilai);
				rataBagus = rataBagus + nilai;
				b=b+1;
				a = a+1;
			}else{
				printf("\n perlu perbaikan ");
				rataJelek = rataJelek + nilai;
				j=j+1;
				a = a+1;
			}
		}else{
			printf("\n Nilai lebih dari skala!");
		}
		
	}
	
	if(rataBagus == 0){
		printf("\n\n Semua Nilai Perlu Perbaikan!");
	}else{
		t = b+j;
		rataTotal = (rataBagus+rataJelek)/t;
		rataBagus = rataBagus/b;
		
		printf("\n\n rata rata nilai quiz : %.2f",rataTotal);
		printf("\n rata rata nilai quiz diatas 50 : %.2f",rataBagus);
	}
	return 0;
}
