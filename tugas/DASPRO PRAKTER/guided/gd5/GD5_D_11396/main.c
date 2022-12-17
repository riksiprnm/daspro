#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef char string[50];

int main(int argc, char *argv[]) {
	int menu,bil,umur,temp=0,random=0;
	string nama;
	srand(time(NULL));
	char huruf;

	do{
		system("cls");
		printf("============== MENU GUIDED ==============");
		printf("\n[1] Menu menjumlahkan bilangan");
		printf("\n[2] Menu menampilkan huruf A-Z");
		printf("\n[3] Menu input data diri");
		printf("\n[4] Menu cari angka random (20-80)");
		printf("\n-----------------------------------------");
		printf("\nMasukkan pilihan menu		: "); scanf("%d", &menu);

		switch(menu){
			case 1:
				printf("\nMasukkan bilangan		: "); scanf("%d", &bil);
				while (bil>0)
				{
					temp = temp + bil;
					printf("\nTemp = %d", temp);
					bil--;
				}
				printf("\n\nJumlah bilangannya	: %d", temp);
			break;
			
			case 2:
				printf("\nAlphabet	: ");
				for(huruf='A';huruf<='Z';huruf++){
					printf("%c", huruf);
				}
			break;

			case 3:
				do{
					printf("\nNama	: "); fflush(stdin); gets(nama);
				}while(strlen(nama)<1);

				do{
					printf("\nUmur	: "); scanf("%d", &umur);
				}while(umur<=0);

				printf("\nNama		: %s", nama);
				printf("\nUmur		: %d", umur);
			break;

			case 4:
				printf("\nBerhentikan perulangan di saat angka menunjukkan (20-80) : "); scanf("%d", &bil);

				do{
					//random = (rand() % (angkaMax [+/-] angkaMin +1)) [-/+]angkaMin
					random = (rand()%(9)+1;
					printf("\n Random %d", random);
				}while(random !=bil);
			break;

			case 0: printf("\nTerima kasih :) "); break;
			default:
			printf("\n[!] Menu hanya ada 1-4");
			break;
		}getch();
	}while(menu!=0);
	return 0;
}
