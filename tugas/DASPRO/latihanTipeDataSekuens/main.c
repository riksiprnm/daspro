#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a,b,c,d,e;
	int rata2, jumlah;
	printf("\n Masukkan angka pertama : "); scanf("%d", &a);
	printf("\n Masukkan angka kedua   : "); scanf("%d", &b);
	printf("\n Masukkan angka ketiga  : "); scanf("%d", &c);
	printf("\n Masukkan angka keempat : "); scanf("%d", &d);
	printf("\n Masukkan angka kelima  : "); scanf("%d", &e);

	rata2=(a+b+c+d+e)/5;
	jumlah=a+b+c+d+e;
	printf("\n\n rata-rata  : %d",rata2);	
	printf("\n jumlah angka : %d",jumlah);
	return 0;
}
