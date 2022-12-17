#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float berat;
	float tinggi,ideal,ideal1;
	
	printf("\n Masukan Tinggi Badan : ");scanf("%f", &tinggi);
	printf("\n Masukan Berat Badan : ");scanf("%f", &berat);
	
	
	
	ideal = tinggi - 100;
	ideal1 = ideal - ideal/10;
	printf("\n Tinggi badan  :%.2f ", tinggi);
	printf("\n Berat badan  :%.2f ", berat);
	
	if(ideal1-berat==2 || ideal1-berat==-2){
		printf("\n IDEAL");
	}else{
		printf("\n TIDAK");
	}
	
	return 0;
}
