#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define ESC 27
typedef char string[50];

void menu(string nama);
void tampil(int a1, int a2, int a3);
void tampilCek(string nama);

int hitungJml(int a1, int a2, int a3);
int cekNama(string nama);
int cekAngka(string angka);

int main(int argc, char *argv[]) {
	string angka1, angka2, angka3;
	int a1,a2,a3;
	int cekData=0;
	string nama;
	char pil;
	bool sudahInput=false;
	do{
		system("color 27");
		system("cls");
		printf("\n\t\t--=== SELAMAT DATANG ===--\n");
		printf("\n\tKamu siapa? "); fflush(stdin); gets(nama);
		tampilCek(nama);
	}while(strlen(nama)==0 || strcmp(nama,"-")==0 || strncmp(nama," ",1)==0);
	
	do{
		system("cls");
		menu(nama);
		printf("\n\t>>> "); pil=getch();
		switch(pil){
			case '1':
				printf("\n\t\t--=== Input Data ===--\n");
				do{
					printf("\n\tMasukkan angka pertama: "); fflush(stdin); gets(angka1);
					if(cekAngka(angka1)==0){
						printf("\n\t\t[!] Angka tidak boleh kosong");
					}else if(cekAngka(angka1)==-2){
						printf("\n\t\t[!] Angka tidak boleh kurang dari 0");
					}else if(cekAngka(angka1)==-1){
						printf("\n\t\t[!] Inputan hanya boleh angka");
					}
				}while(cekAngka(angka1)==0 || cekAngka(angka1)==-1 || cekAngka(angka1)==-2);
				do{
					printf("\n\tMasukkan angka kedua: "); fflush(stdin); gets(angka2);
					if(cekAngka(angka2)==0){
						printf("\n\t\t[!] Angka tidak boleh kosong");
					}else if(cekAngka(angka2)==-2){
						printf("\n\t\t[!] Angka tidak boleh kurang dari 0");
					}else if(cekAngka(angka2)==-1){
						printf("\n\t\t[!] Inputan hanya boleh angka");
					}
				}while(cekAngka(angka2)==0 || cekAngka(angka2)==-1 || cekAngka(angka2)==-2);
				do{
					printf("\n\tMasukkan angka ketiga: "); fflush(stdin); gets(angka3);
					if(cekAngka(angka3)==0){
						printf("\n\t\t[!] Angka tidak boleh kosong");
					}else if(cekAngka(angka3)==-2){
						printf("\n\t\t[!] Angka tidak boleh kurang dari 0");
					}else if(cekAngka(angka3)==-1){
						printf("\n\t\t[!] Inputan hanya boleh angka");
					}
				}while(cekAngka(angka3)==0 || cekAngka(angka3)==-1 || cekAngka(angka3)==-2);

				a1=atoi(angka1);
				a2=atoi(angka2);
				a3=atoi(angka3);
				sudahInput=true;
				printf("\n\t\t[~] Input data berhasil...");

			break;

			case '2':
				if(sudahInput){
					tampil(a1,a2,a3);
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
int cekNama(string nama){
	if(strlen(nama)==0){
			return 0;
		}else if(strcmp(nama,"-")==0){
			return -1;
		}else if(strncmp(nama," ",1)==0){
			return -2;
		}
}
void tampilCek(string nama){
		if(cekNama(nama)==0){
			printf("\n\t\t[!] Nama tidak boleh kosong");
			getch();
		}else if(cekNama(nama)==-1){
			printf("\n\t\t[!] Nama tidak boleh hanya '-'");
			getch();
		}else if(cekNama(nama)==-2){
			printf("\n\t\t[!] Awalan nama tidak boleh spasi");
			getch();
		}
}

void menu(string nama){
	printf("\n\tNama: %s", nama);
	printf("\n\n\t[1] Input Data");
	printf("\n\t[2] Tampil Data");
	printf("\n\t[ESC] Exit");
}

int hitungJml(int a1, int a2, int a3){
	return a1+a2+a3;
}
void tampil(int a1, int a2, int a3){
	printf("\n\n\t\t--=== Tampil Data ===--\n");
	printf("\n\tAngka pertama\t: %d", a1);
	printf("\n\tAngka kedua\t: %d",a2);
	printf("\n\tAngka ketiga\t: %d",a3);
	printf("\n\n\tTotal\t\t: %d", hitungJml(a1,a2,a3));
}

int cekAngka(string angka){
	int i=0;
	int panjang = strlen(angka);

	if(strlen(angka)==0)return 0;

	while(isspace(angka[i])) i++;
	if(panjang==i) return 0;

	if(angka[i]=='-'){
		i++;
		if(!isdigit(angka[i])) return -1;
		return -2;
	}

	while(i<panjang && !isspace(angka[i])){
		if(!isdigit(angka[i])) return -1;
		i++;
	}

	return 1;
}
