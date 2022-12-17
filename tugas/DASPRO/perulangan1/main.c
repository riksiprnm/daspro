#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef char string[50];

int main(int argc, char *argv[]) {
	float bil, rata2,jml=0, i=0;
	string jawab;
	
	do{
		printf("\nMasukkan angka: "); scanf("%f", &bil);
		jml+=bil;
		i++;
		printf("Ingin memasukkan angka lagi? [ya/tidak] : "); fflush(stdin); gets(jawab);
		
	}while(strcmpi(jawab,"ya")==0);
	
	rata2=jml/i;
	printf("\nRata-rata: %.2f", rata2);
	return 0;
}
