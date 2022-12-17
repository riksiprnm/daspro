#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ESC 27
typedef char string[50];

void menu(string nama);
void hitungJml(int a, int b, int c, int *total);
void tampil(int a, int b, int c, int total);

int main(int argc, char *argv[]) {
	int angka1, angka2, angka3;
	int cekData=0;
	int total=0;
	string nama;
	char pil;
	bool sudahInput=false;
	do{
		system("color 27");
		system("cls");
		printf("\n\t\t--=== SELAMAT DATANG ===--\n");
		printf("\n\tKamu siapa? "); fflush(stdin); gets(nama);
		if(strlen(nama)==0){
			printf("\n\t\t[!] Masak gapunya nama wkwkwk");
			getch();
		}else if(strcmp(nama,"-")==0){
			printf("\n\t\t[!] Anjir masak namanya strip wkwk");
			getch();
		}else if(strncmp(nama," ",1)==0){
			printf("\n\t\t[!] Wkwkwk masak awalan namanya itu spasi");
			getch();
		}
		
	}while(strlen(nama)==0 || strcmp(nama,"-")==0 || strncmp(nama," ",1)==0);
	
	do{
		system("cls");
		menu(nama);
		printf("\n\t>>> "); pil=getch();
		switch(pil){
			case '1':
				printf("\n\t\t--=== Input Data ===--\n");
				do{
					printf("\n\tMasukkan angka pertama: "); scanf("%d", &angka1);
					if(angka1<0) printf("\n\t\t[!] Angka tidak boleh kurang dari 0");
				}while(angka1<0);
				do{
					printf("\n\tMasukkan angka kedua: "); scanf("%d", &angka2);
					if(angka2<0) printf("\n\t\t[!] Angka tidak boleh kurang dari 0");
				}while(angka2<0);
				do{
					printf("\n\tMasukkan angka ketiga: "); scanf("%d", &angka3);
					if(angka3<0) printf("\n\t\t[!] Angka tidak boleh kurang dari 0");
				}while(angka3<0);
				sudahInput=true;
				printf("\n\t\t[~] Input data berhasil...");

			break;

			case '2':
				if(sudahInput){
					hitungJml(angka1,angka2,angka3,&total);
					tampil(angka1,angka2,angka3,total);
				}else{
					printf("\n\t\t[!] Kamu belum input data");
				}
			break;

			case 27:
				printf("\n\t\t[*] Keluar dari program...");
			break;

			default:
				printf("\n\t\t[!] Pilihan menu tidak ada");
			break;
		}getch();
	}while(pil!=27);

	return 0;
}

void menu(string nama){
	printf("\n\tNama: %s", nama);
	printf("\n\n\t[1] Input Data");
	printf("\n\t[2] Tampil Data");
	printf("\n\t[ESC] Exit");
}

void hitungJml(int a, int b, int c, int *total){
	*total=a+b+c;
}

void tampil(int a, int b, int c, int total){
	printf("\n\n\t\t--=== Tampil Data ===--\n");
	printf("\n\tAngka pertama\t: %d", a);
	printf("\n\tAngka kedua\t: %d",b);
	printf("\n\tAngka ketiga\t: %d",c);
	printf("\n\n\tTotal\t\t: %d",total);
}
