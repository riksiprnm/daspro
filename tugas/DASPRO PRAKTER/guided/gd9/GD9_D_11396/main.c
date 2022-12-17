#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#define phi 3.14

typedef char string[50];

float volumeTabung(float jari, float tinggi);;
float luasPermukaanTabung(float jari, float tinggi);
float bilKuadrat(float bil);

int main(int argc, char *argv[]) {
	int menu;
	float jari, tinggi;
	string ans;
	
	printf("\n\n\n\t\tAPAKAH KAMU MANUSIA [Y/N] ?"); fflush(stdin); gets(ans);
	
	if(strcmpi(ans,"Y")==0){
		system("color 20");
		printf("\n\n\n\t\t\tYEAY ANDA MANUSIA :)\n\n");
		printf("\n\n\t\tTekan apapun untuk melanjutkan guided :D CEMANGATS");
		getch();
		do{
			system("color 60");
			system("cls");
			printf("\n\t--=== GUIDED FUNGSI ===--\n");
			printf("\t[1] Input Data Tabung\n");
			printf("\t[2] Hitung Volume Tabung\n");
			printf("\t[3] Hitung Luas Permukaan Tabung\n");
			printf("\t[0] EXIT\n");
			printf("\t>>> "); scanf("%d", &menu);
			switch (menu){
			case 1:
				printf("\n\ntInput Data Tabung");
				printf("\n\n\tMasukkan Jari-jari	: "); scanf("%f", &jari);
				printf("\tMasukkan Tinggi		: "); scanf("%f", &tinggi);
				printf("\n\tInput Data berhasil");
			break;
			
			case 2:
				printf("\n\n\tMenghitung Volume Tabung");
				printf("\n\t==========================================");
				printf("\n\tVolume Tabung adalah  %.2f", volumeTabung(jari,tinggi));
			break;

			case 3:
				printf("\n\n\tMenghitung Luas Permukaan Tabung");
				printf("\n\t========================================");
				printf("\n\tLuas Permukaan Tabung adalah : %.2f", luasPermukaanTabung(jari,tinggi));
			break;

			}
			printf("\n\n\n\t\tTEKAN TERSERAH ANDA UNTUK MELANJUTKAN :) !\n\n");
			getch();
		}while(menu!=0);
	}else if(strcmpi(ans,"N")==0){
		system("color 40");
		printf("\n\n\n\t\tOH TIDAK, SYSTEM OUT!! :(\n\n");
		printf("\t\tKAMI TIDAK MENERIMA ALIEN >:(");
	}
	printf("\n\n\n\t\tSAMPAI JUMPA DI UGD :D, ASIK BANGET !\n\n"); 
	return 0;
}
float volumeTabung(float jari, float tinggi){
	return phi*bilKuadrat(jari)*tinggi;
} 
float luasPermukaanTabung(float jari, float tinggi){
	return (2*phi*bilKuadrat(jari))+(2*phi*jari*tinggi);
} 
float bilKuadrat(float bil){
	return bil*bil;
} 
