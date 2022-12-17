#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define tampungBuku 2
#define tampungRak 3

typedef char string[50];

typedef struct{
	string judulBuku;
	string kodeBuku;
}Buku;

typedef struct{
	string jenisRak;
	int noRak;
	Buku B[tampungBuku];
}Rak;

void initRak(Rak Rk[]);
Buku isiDataBuku(string judulBuku, string kodeBuku);
Rak isiDataRak(string jenisRak, int noRak, Buku temp[]);
int cekEmpty(Rak Rk[]);
int cekIsi(Rak Rk[]);
int searchRak(Rak Rk[], int noRak);
void tampilData(Rak Rk[]);

int main(int argc, char *argv[]) {
	Buku temp[tampungBuku];
	Rak Rk[tampungRak];
	string jenisRak, judulBuku, kodeBuku;
	int pil, i, noRak;
	bool menu =true;

	initRak(Rk);
	while(menu){
		system("cls");
		printf("\n === MENU RAK ===");
		printf("\n[1] Isi Data Rak");
		printf("\n[2] Tampil Data Rak");
		printf("\n[3] Delete Data Rak");
		printf("\n[0] Exit");
		printf("\n>> "); scanf("%d", &pil);
		
		switch(pil){
			case 1:
				if(cekEmpty(Rk)!=-1){
					printf("\nIsi Data Rak");
					printf("\nNo Rak  : "); scanf("%d", &noRak);
					printf("Jenis Rak : "); fflush(stdin); gets(jenisRak);

					printf("\n\tIsi Data Buku");
					for(i=0;i<tampungBuku;i++){
						printf("\n\tData Buku ke - %d", i+1);
						printf("\n\tJudul Buku : "); fflush(stdin); gets(judulBuku);
						printf("\tKode Buku : "); fflush(stdin); gets(kodeBuku);
						temp[i]= isiDataBuku(judulBuku,kodeBuku);
					}
					Rk[cekEmpty(Rk)]= isiDataRak(jenisRak,noRak,temp);
					printf("\n\tBerhasil tambah data");
				}else printf("\n\t[!] Data Full");
			break;
			case 2:
				if(cekIsi(Rk)!=-1){
					tampilData(Rk);
				}else printf("\n[!] Semua rak masih kosong");
			break;
			case 3:
				if(cekIsi(Rk)!=-1){
					printf("\nNoRak yang ingin dihapus : "); scanf("%d", &noRak);
					if(searchRak(Rk, noRak)!=-1){
						for(i=0;i<tampungBuku;i++){
							strcpy(temp[i].judulBuku,"-");
							strcpy(temp[i].kodeBuku,"-");
						}
						Rk[searchRak(Rk,noRak)] = isiDataRak("-",0,temp);

						printf("\n[!] Berhasil Delete Data");
					}else printf("\n[!] Data tidak ditemukan");
				}else printf("\n[!] Semua rak masih kosong");
			break;
			case 0:
				printf("\n CIAO !!!");
				printf("\n Made Riksi Purnama Sadnya Agung / 210711396 / D");
				menu=false;
			break;

			default:
			break;
		}
		getch();
	}



	return 0;
}

void initRak(Rak Rk[]){
	int i,j;

	for(i=0;i<tampungRak;i++){
		strcpy(Rk[i].jenisRak,"-");
		Rk[i].noRak = 0;

		for(j=0;j<tampungBuku;j++){
			strcpy(Rk[i].B[j].judulBuku,"-");
			strcpy(Rk[i].B[j].kodeBuku,"-");
		}
	}
}
Buku isiDataBuku(string judulBuku, string kodeBuku){
	Buku B;
	strcpy(B.judulBuku,judulBuku);
	strcpy(B.kodeBuku,kodeBuku);
	return B;
}
Rak isiDataRak(string jenisRak, int noRak, Buku temp[]){
	Rak Rk;
	int i;
	
	Rk.noRak = noRak;
	strcpy(Rk.jenisRak,jenisRak);
	for(i=0;i<tampungBuku;i++){
		Rk.B[i] = temp[i];

	}
	return Rk;
}
int cekEmpty(Rak Rk[]){
	int i;
	for(i=0;i<tampungRak;i++){
		if(strcmp(Rk[i].jenisRak,"-")==0){
			return i;
		}
	}
	return -1;
}
int cekIsi(Rak Rk[]){
	int i;
	for(i=0;i<tampungRak;i++){
		if(strcmp(Rk[i].jenisRak,"-")!=0){
			return i;
		}
	}
	return -1;
}
void tampilData(Rak Rk[]){
	int i,j;

	printf("\n[DATA RAK]");
	for(i=0;i<tampungRak;i++){
		if(strcmp(Rk[i].jenisRak,"-")!=0){
			printf("\nNo Rak    : %d",Rk[i].noRak);
			printf("\nJenis Rak : %s\n",Rk[i].jenisRak);

			printf("\n\n\t[DATA BUKU]");
			for(j=0;j<tampungBuku;j++){
				printf("\n\n\tData Buku Ke - %d", j+1);
				printf("\n\tJudul Buku : %s", Rk[i].B[j].judulBuku);
				printf("\n\tKode Buku  : %s\n\n", Rk[i].B[j].kodeBuku);
			}
		}
	}
}
int searchRak(Rak Rk[], int noRak){
	int i;
	for(i=0;i<tampungRak;i++){
		if(Rk[i].noRak == noRak){
			return i;
		}
	}
	return -1;
}
