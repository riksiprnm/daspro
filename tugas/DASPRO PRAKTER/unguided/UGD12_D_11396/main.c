#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#define ESC 27
//bonus 1/2/3/4

typedef char string[50];

typedef struct{
	string kode;
	string petugas;
	int jmlAyam;
	int jmlTelur;
}Petak;

typedef struct{
	string nama;
	Petak petak[8];
}Peternakan;

void init(Peternakan peternakan[]);
void menu();
void subMenu();
void tampilTernak(Peternakan peternakan[], string temp);
void swap(Peternakan peternakan[], int index1, int index2, int indexTernak);
void tampilPetak(Peternakan peternakan[], string temp, int indexTernak);

int checkTernak(Peternakan peternakan[], string temp);
int isFullPetak(Peternakan peternakan[], string temp);
int checkPetak(Peternakan peternakan[], string temp);
int isEmptyPetak(Peternakan peternakan[], string temp);
int takeIndexPetak(Peternakan Peternakan[], int indexTernak, string temp);

int main(int argc, char *argv[]) {
	Peternakan peternakan[2];
	char pil[2];
	bool sudahSetTernak=false;
	int i, indexTernak, indexPetak, indexPetak2;
	string tempTernak, tempPetak, tempPetak2;

	init(peternakan);
	do{
		system("cls");
		menu();
		printf("\n\t>> "); pil[0]=getch();
		switch (pil[0]){
		case '1':
			if(!sudahSetTernak){
				for(i=0;i<2;i++){
					printf("\n\tNama peternakan ke-%d : ",i+1); fflush(stdin); gets(peternakan[i].nama);
				}
				sudahSetTernak=true;
				printf("\n\t\t[~] Berhasil set nama peternakan");
			}else{
				printf("\n\t\t[!] Sudah set nama peternakan");
			}
		break;
		case '2':
			printf("\n\tNama peternakan : "); fflush(stdin); gets(tempTernak);
			if(checkTernak(peternakan,tempTernak)!=-1){
				indexTernak=checkTernak(peternakan,tempTernak);
				subMenu();
				printf("\n\t>> "); pil[1]=getch();
				switch (pil[1]){
				case '1':
					if(isFullPetak(peternakan,tempTernak)==0){
						indexPetak=checkPetak(peternakan,tempTernak);
						printf("\n\tKode petak   : "); fflush(stdin); gets(peternakan[indexTernak].petak[indexPetak].kode);
						printf("\tNama petugas : "); fflush(stdin); gets(peternakan[indexTernak].petak[indexPetak].petugas);
						printf("\tJumlah ayam  : "); scanf("%d", &peternakan[indexTernak].petak[indexPetak].jmlAyam);
						printf("\tJumlah telur : "); scanf("%d", &peternakan[indexTernak].petak[indexPetak].jmlTelur);
						printf("\n\t\t[~] Berhasil mengisi petak");
					}else{
						printf("\n\t\t[!] Semua petak telah terisi");
					}
				break;
				case '2':
					if(isEmptyPetak(peternakan,tempTernak)==1){
						printf("\n\tKode petak : "); fflush(stdin); gets(tempPetak);
						if(takeIndexPetak(peternakan,indexTernak,tempPetak)!=-1){
							indexPetak=takeIndexPetak(peternakan,indexTernak,tempPetak);
							printf("\n\tKode petak baru   : "); fflush(stdin); gets(peternakan[indexTernak].petak[indexPetak].kode);
							printf("\tNama petugas baru : "); fflush(stdin); gets(peternakan[indexTernak].petak[indexPetak].petugas);
							printf("\tJumlah ayam baru  : "); scanf("%d", &peternakan[indexTernak].petak[indexPetak].jmlAyam);
							printf("\tJumlah telur baru : "); scanf("%d", &peternakan[indexTernak].petak[indexPetak].jmlTelur);
							printf("\n\t\t[~] Berhasil mengedit petak");
						}else{
							printf("\n\t\t[!] Kode petak tidak ditemukan");
						}
					}else{
						printf("\n\t\t[!] Semua petak masih kosong");
					}
				break;
				case '3':
					if(isEmptyPetak(peternakan,tempTernak)==1){
						printf("\n\tKode petak 1 : "); fflush(stdin); gets(tempPetak);
						if(takeIndexPetak(peternakan,indexTernak,tempPetak)!=-1){
							printf("\n\tKode petak 2 : "); fflush(stdin); gets(tempPetak2);
							if(takeIndexPetak(peternakan,indexTernak,tempPetak2)!=-1){
									indexPetak=takeIndexPetak(peternakan,indexTernak,tempPetak);
									indexPetak2=takeIndexPetak(peternakan,indexTernak,tempPetak2);
									swap(peternakan,indexPetak,indexPetak2,indexTernak);
								printf("\n\t\t[~] Berhasil swap petak");
							}else{
								printf("\n\t\t[!] Kode petak tidak ditemukan");
							}
						}else{
							printf("\n\t\t[!] Kode petak tidak ditemukan");
						}
						

					}else{
						printf("\n\t\t[!] Semua petak masih kosong");
					}
				break;
				default:
					printf("\n\t\t[!] Menu tidak ditemukan");
				break;
				}
			}else{
				printf("\n\t\t[!] Peternakan tidak ditemukan");
			}
		break;
		case '3':
			printf("\n\tNama peternakan : "); fflush(stdin); gets(tempTernak);
			if(checkTernak(peternakan,tempTernak)!=-1){
				indexTernak=(checkTernak(peternakan,tempTernak));
				if(isEmptyPetak(peternakan,tempTernak)==1){
						tampilTernak(peternakan,tempTernak);
						printf("\n\tKode Petak : "); fflush(stdin); gets(tempPetak);
						if(takeIndexPetak(peternakan,indexTernak,tempPetak)!=-1){
							tampilPetak(peternakan,tempPetak,indexTernak);
						}else{
							printf("\n\t\t[!] Kode petak tidak ditemukan");
						}
					}else{
						printf("\n\t\t[!] Semua petak masih kosong");
					}
			}else{
				printf("\n\t\t[!] Peternakan tidak ditemukan");
			}
		break;
		case 27:
			printf("\n\tMade Riksi Purnama Sadnya Agung /210711396 / D");
		break;

		default:
			printf("\n\t\t[!] Menu tidak ditemukan");
		break;
		}getch();
	}while(pil[0]!=27);
	return 0;
}

void menu(){
	printf("\n\t\t--=== Peternakan Udin ===--\n");
	printf("\n\t[1] Set Nama Peternakan");
	printf("\n\t[2] Set Data");
	printf("\n\t[3] Tampil Data Petak Peternakan");
	printf("\n\t[ESC] Keluar");
}
void subMenu(){
	printf("\n\t[1] Mengisi Petak");
	printf("\n\t[2] Edit Petak");
	printf("\n\t[TUGAS]");
	printf("\n\t[3] Swap Petak");
}
void init(Peternakan peternakan[]){
	int i,j;
	for(i=0;i<2;i++){
		strcpy(peternakan[i].nama,"-");
		for(j=0;j<8;j++){
			strcpy(peternakan[i].petak[j].kode,"-");
			strcpy(peternakan[i].petak[j].petugas,"-");
			peternakan[i].petak[j].jmlAyam=0;
			peternakan[i].petak[j].jmlTelur=0;
		}
	}
}
void tampilTernak(Peternakan peternakan[], string temp){
	int i,j;
	for(i=0;i<2;i++){
		if(strcmpi(temp,peternakan[i].nama)==0){
			printf("\n\t");
			for(j=0;j<8;j++){
				if(j==4){
					printf("\n\t");
				}
				printf("[%s]  ", peternakan[i].petak[j].kode);
			}
		}	
	}
}
void swap(Peternakan peternakan[], int index1, int index2, int indexTernak){
	Petak temp;
	temp=peternakan[indexTernak].petak[index1];
	peternakan[indexTernak].petak[index1]=peternakan[indexTernak].petak[index2];
	peternakan[indexTernak].petak[index2]=temp;
}
void tampilPetak(Peternakan peternakan[], string temp, int indexTernak){
	int j;
	for(j=0;j<8;j++){
		if(strcmpi(temp,peternakan[indexTernak].petak[j].kode)==0){
			printf("\n\t[ Tampil Data Petak ]\n");
			printf("\n\tKode petak   : %s", peternakan[indexTernak].petak[j].kode);
			printf("\n\tNama petugas : %s", peternakan[indexTernak].petak[j].petugas);
			printf("\n\tJumlah ayam  : %d", peternakan[indexTernak].petak[j].jmlAyam);
			printf("\n\tJumlah telur : %d", peternakan[indexTernak].petak[j].jmlTelur);
		}
	}
}
int checkTernak(Peternakan peternakan[], string temp){
	int i;
	for(i=0;i<2;i++){
		if(strcmpi(temp,peternakan[i].nama)==0) return i;
	}
	return -1;
}
int isFullPetak(Peternakan peternakan[], string temp){
	int i,j;
	for(i=0;i<2;i++){
		if(strcmpi(temp,peternakan[i].nama)==0){
			for(j=0;j<8;j++){
				if(strcmp(peternakan[i].petak[j].kode,"-")==0) return 0;
			}
			return 1;
		}
	}
}
int checkPetak(Peternakan peternakan[], string temp){
	int i,j;
	for(i=0;i<2;i++){
		if(strcmpi(temp,peternakan[i].nama)==0){
			for(j=0;j<8;j++){
				if(strcmp(peternakan[i].petak[j].kode,"-")==0) return j;
			}
		}
	}
}
int isEmptyPetak(Peternakan peternakan[], string temp){
	int i,j;
	for(i=0;i<2;i++){
		if(strcmpi(temp,peternakan[i].nama)==0){
			for(j=0;j<8;j++){
				if(strcmp(peternakan[i].petak[j].kode,"-")!=0) return 1;
			}
			return 0;
		}
	}
}
int takeIndexPetak(Peternakan Peternakan[], int indexTernak, string temp){
	int j;
	for(j=0;j<8;j++){
		if(strcmpi(Peternakan[indexTernak].petak[j].kode,temp)==0) return j;
	}
	return -1;
}
