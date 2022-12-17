#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#define ESC 27
typedef char string[50];

typedef struct{
	string nama;
	string gender;
}AnakAnjing;

typedef struct{
	string nama;
	string jenis;
	int umur;
	string gender;
	AnakAnjing anak[2];
}Anjing;

typedef struct{
	Anjing anjing[2];
}Kandang;


void init(Kandang kandang[]);
void tampil(Kandang kandang[]);
void menu();
int isFull(Kandang kandang[]);
void tambah(Kandang kandang[]);
void tampilTertentu(Kandang kadang[], int index);

int main(int argc, char *argv[]) {
	Kandang kandang[5];
	char pil,pil2;
	bool isInit=false;
	int index;

	do{
		system("cls");
		menu();
		printf("\n\t>> "); pil=getch();
		switch (pil){
		case '1':
			if(!isInit){
				init(kandang);
				isInit=true;
				printf("\n\t\t[~] Berhasil init data");
			}else{
				printf("\n\t\t[!] Sudah init data");
			}
			
		break;
		case '2':
			if(isInit){
				if(isFull(kandang)==0){
					printf("\n\t-== Tambah Data Anjing ==-\n");
					tambah(kandang);
					printf("\n\t\t[~] Berhasil input data anjing");
				}else printf("\n\t\t[!] Kandang sudah penuh");
			}else{
				printf("\n\t\t[!] Belum init data");
			}
		break;
		case '3':
			if(isInit){
				system("cls");
				printf("\n\t-== Tampil Data Anjing ==-\n");
				printf("\n\t[1] Tampil All");
				printf("\n\t[2] Tampil Data Tertentu");
				printf("\n\t>> "); pil2=getch();
				switch(pil2){
					case '1':
						tampil(kandang);
					break;
					case '2':
						printf("\n\tMasukkan nomer kandang : "); scanf("%d", &index);
						tampilTertentu(kandang,index);
					break;
					default:
						printf("\n\t\t[!] Menu tidak tersedia");
					break;
				}
			}else{
				printf("\n\t\t[!] Belum init data");
			}
		break;
		case 27:
			printf("\n\t\t[~] Terima kasih . . .");
		break;
		default:
			printf("\n\t\t[!] Menu tidak tersedia");
		break;
		}getch();
	}while(pil!=27);
	
	return 0;
}
void menu(){
	printf("\n\t-==[ Data Pencatatan Anjing ]==-\n");
	printf("\n\t[1] Inisialisasi Data");
	printf("\n\t[2] Tambah Data Anjing");
	printf("\n\t[3] Tampil Data Anjing");
	printf("\n\t[ESC] Keluar");
}
void init(Kandang kandang[]){
	int i,j,k;
	for(i=0;i<5;i++){
		for(j=0;j<2;j++){
			strcpy(kandang[i].anjing[j].nama,"-");
			strcpy(kandang[i].anjing[j].jenis,"-");
			kandang[i].anjing[j].umur=0;
			strcpy(kandang[i].anjing[j].gender,"-");

			for(k=0;k<2;k++){
				strcpy(kandang[i].anjing[j].anak[k].nama,"-");
				strcpy(kandang[i].anjing[j].anak[k].gender,"-");
			}
		}
		
	}
}
void tampil(Kandang kandang[]){
	int i,j,k;
	for(i=0;i<5;i++){
		printf("\n\tKandang %d: ",i+1);
		for(j=0;j<2;j++){
			if(strcmp(kandang[i].anjing[j].nama,"-")==0){
				printf("[ KOSONG ]");
			}else{
				printf("[ %s ]",kandang[i].anjing[j].nama);
			}
		}
	}
}
void tampilTertentu(Kandang kandang[], int index){
	int i,j;
	if(index<1 || index>5){
		printf("\n\t\t[!] Nomer kandang yang dicari tidak ada");
	}else if(strcmp(kandang[index-1].anjing[0].nama,"-")==0){
		printf("\n\t\t[!] Kandang masih kosong");
	}
	else{
		for(i=0;i<2;i++){
			if(strcmp(kandang[index-1].anjing[i].nama,"-")!=0){
				printf("\n\tNama anjing ke-%d : %s",i+1, kandang[index-1].anjing[i].nama);
				printf("\n\tJenis             : %s", kandang[index-1].anjing[i].jenis);
				printf("\n\tUmur              : %d", kandang[index-1].anjing[i].umur);
				printf("\n\tGender            : %s",kandang[index-1].anjing[i].gender);
			}
			for(j=0;j<2;j++){
				if(strlen(kandang[index-1].anjing[i].anak[j].nama)!=0 && strcmp(kandang[index-1].anjing[i].nama,"-")!=0){
					printf("\n\t\tNama anak anjing ke-%d : %s", j+1,kandang[index-1].anjing[i].anak[j].nama);
					printf("\n\t\tGender anak anjing    : %s\n",kandang[index-1].anjing[i].anak[j].gender);
				}
			}
			printf("\n");
		}
	}
		
}
int isFull(Kandang kandang[]){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<2;j++){
			if(strcmp(kandang[i].anjing[j].nama,"-")==0) return 0;
		}
	}
	return 1;
}

void tambah(Kandang kandang[]){
	Anjing temp;
	string jwb;
	int i,j;
	printf("\n\tMasukkan nama anjing   : "); fflush(stdin); gets(temp.nama);
	while(strlen(temp.nama)==0){
		printf("\n\tNama tidak boleh kosong\n");
		printf("\n\tMasukkan nama anjing   : "); fflush(stdin); gets(temp.nama);
	}
	printf("\tMasukkan jenis anjing  : "); fflush(stdin); gets(temp.jenis);
	printf("\tMasukkan umur anjing   : "); scanf("%d", &temp.umur);
	printf("\tMasukkan gender anjing : "); fflush(stdin); gets(temp.gender);
	
	printf("\n\tIngin input anak anjing [Y/T] ? "); fflush(stdin); gets(jwb);
	if(strcmpi(jwb,"y")==0){
		for(i=0;i<2;i++){
				printf("\n\t\tMasukkan nama anak anjing : "); fflush(stdin); gets(temp.anak[i].nama);
				while(strlen(temp.anak[i].nama)==0){
					printf("\n\t\t\t[!] Nama tidak boleh kosong\n");
					printf("\n\t\tMasukkan nama anak anjing : "); fflush(stdin); gets(temp.anak[i].nama);
				}
				printf("\t\tMasukkan gender anak anjing : "); fflush(stdin); gets(temp.anak[i].gender);
				printf("\n");
				if(i==0){
					printf("\n\tIngin input anak anjing lagi [Y/T] ? "); fflush(stdin); gets(jwb);
					if(strcmpi(jwb,"t")==0){
						break;
					}
				}
			}
	}
	for(i=0;i<5;i++){
		for(j=0;j<2;j++){
			if(strcmp(kandang[i].anjing[j].nama,"-")==0){
				kandang[i].anjing[j]=temp;
				return;
			}
		}
	}
}
