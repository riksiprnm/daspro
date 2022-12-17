#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef char string[50];
void menu();
void setJmlTebak(int *jmlTebakan, int rentang);
void setRentangTebak(int *min, int *max, int *rentang, int jmlTebakan);
void tampil(int jmlTebak, int min, int max);
void tebakAngka(int *tebak1, int *tebak2, int *kunci, int max, int min, int jmlTebak, int *selisih, int useCheat, int *status);
void cheat(int *useCheat);
void statusGame(int jmlTebak, int min, int max);
void history(int status, int min, int max, int kunci);

int main(int argc, char *argv[]) {

	srand(time(NULL));
	bool pernahMain=false;
	int pil;
	int jmlTebakan=1;
	int minRange=0, maxRange=10;
	int tebakan1,tebakan2;
	int rentang=11;
	int angkaKunci;
	int selisih;
	int useCheat=0;
	int status=0;

	do{
		system("cls");
		menu();
		printf("\n>>> "); scanf("%d", &pil);
		switch (pil){
		case 1:
			printf("\n\t--=== Set Jumlah Tebakan ===--\n");
			setJmlTebak(&jmlTebakan, rentang);
			printf("\n\t[*] Jumlah Tebakan Berhasil di Update");
		break;
		
		case 2:
			printf("\n\t--=== Set Rentang Permainan ===--\n");
			setRentangTebak(&minRange, &maxRange, &rentang, jmlTebakan);
			printf("\n\t[*] Berhasil Update Rentang Permainan");
		break;

		case 3:
			system("cls");
			printf("\n   --=== Let's Play The Game ===--\n");
			tampil(jmlTebakan,minRange,maxRange);
			printf("\n\n   --===========================--\n");
			tebakAngka(&tebakan1,&tebakan2, &angkaKunci,maxRange,minRange, jmlTebakan, &selisih, useCheat, &status);
			pernahMain=true;
		break;

		case 4:
			cheat(&useCheat);
		break;

		case 5:
			statusGame(jmlTebakan,minRange,maxRange);
		break;

		case 6:
			if(pernahMain){
				history(status,minRange,maxRange,angkaKunci);
			}else{
				printf("\n\t[!] Belum pernah main");
			}
		break;
		case 0:
			printf("\n\tKeluar dari program . . .");
		break;

		default:
			printf("\n\t[!] Menu tidak tersedia");
		break;
		}
		getch();
	}while(pil!=0);
	
	return 0;
}

void menu(){
	printf("\n\t\t--=== UGD Prosedur 1 ===--\n");
	printf("\n[1] Set Jumah Tebakan");
	printf("\n[2] Set Rentang Permainan");
	printf("\n[3] Mulai Permainan");
	printf("\n\t--======--");
	printf("\n[4] Set Tampil Selisih");
	printf("\n[5] Status Permainan");
	printf("\n[6] History Permainan");
	printf("\n\n[0] Exit\n");
	
}
void setJmlTebak(int *jmlTebakan, int rentang){
	do{
		printf("\nInput Jumlah Tebakan : "); scanf("%d", jmlTebakan);
		if(*jmlTebakan<1){
			printf("\n\t[!] Jumlah tebakan tidak boleh kurang dari 1\n");
		}else if(*jmlTebakan>rentang){
			printf("\n\t[!] Jumlah Tebakan tidak boleh lebih dari Rentang Permainan\n");
		}
	}while(*jmlTebakan<1 || *jmlTebakan>rentang);
}
void setRentangTebak(int *min, int *max, int *rentang, int jmlTebakan){
	do{
		printf("\nInput rentang max: "); scanf("%d", max);
		printf("\nInput rentang min: "); scanf("%d", min);
		*rentang= (*max)-(*min)+1;
		if(*min > *max){
			printf("\n\t[!] Rentang Invalid\n");
		}else if(*rentang<=jmlTebakan){
			printf("\n\t[!] Rentang Tidak Boleh < Jumlah Tebakan\n");
		}
	}while(*min>*max || *rentang<=jmlTebakan);
}

void tampil(int jmlTebak, int min, int max){
	printf("\n\tJumlah Tebakan : %d", jmlTebak);
	printf("\n\tMax Range      : %d", max);
	printf("\n\tMin Range      : %d", min);
}

void tebakAngka(int *tebak1, int *tebak2, int *kunci, int max, int min, int jmlTebak, int *selisih, int useCheat, int *status){
	int temp;
	int keberapa=0;
	int i=0;
	temp=jmlTebak;
	*kunci= (rand()% (max-min+1)+min);
	do{
		printf("\nTebak angka: "); scanf("%d", tebak1);
		keberapa++;
		if(i>=1){
			if(*tebak1==*kunci){
			break;
			}else if(abs(*tebak1-*kunci)<abs(*tebak2-*kunci)){
				printf("\n\t[~] Semakin Dekat");
			}else if(abs(*tebak1-*kunci)>abs(*tebak2-*kunci)){
				printf("\n\t[~] Semakin Jauh");
			}else if( abs(*tebak1-*kunci) == abs(*tebak2-*kunci)){
				printf("\n\t[~] Jarak Sama");
			}
		}
		i++;
		*tebak2=*tebak1;
		temp--;
		if(*tebak1==*kunci){
			break;
		}
		if(useCheat==1){
			*selisih=abs(*tebak1-*kunci);
			printf("\n\t[~] Selisih jarak : %d\n", *selisih);
		}
	}while(temp>0);
	if(*tebak1==*kunci){
		printf("\n\n\t[*] Tebakan Kamu Benar !");
		printf("\n\tNilai tebakan %d", *kunci);
		printf("\n\tBenar di tebakan ke-%d", keberapa);
		*status=1;
	}else{
		printf("\n\n\t[!] Kamu Gagal");
		printf("\n\tNilai tebakan %d", *kunci);
		*status=0;
	}
	
}
void cheat(int *useCheat){
	string temp;
	printf("\n\t\t--=== Set Tampil Selisih ===--\n");
	printf("\ntampilkan selisih tebakan? [Y/T]: "); fflush(stdin); gets(temp);
	if(strcmpi(temp,"y")==0){
		*useCheat=1;
		printf("\n\t[*] Menampilkan Selisih Tebakan");
	}else if(strcmpi(temp,"t")==0){
		*useCheat=0;
		printf("\n\t[*] Menyembunyikan Selisih tebakan");
	}else{
		printf("\n\t[!] Inputan tidak valid");
	}
}

void statusGame(int jmlTebak, int min, int max){
	printf("\n\t--=== Status Permainan ===--");
	printf("\n\t Jumlah Tebakan: %d", jmlTebak);
	printf("\n\t Max Range: %d", max);
	printf("\n\t Min Range: %d", min);
	printf("\n\t--========================--");
}
void history(int status, int min, int max, int kunci){
	printf("\n\t--=== Laporan Permainan ===--\n");
	printf("\n\tStatus pemainan terakhir: ");
	if(status==1){
		printf("Menang");
	}else if(status==0){
		printf("Kalah");
	}
	printf("\n\tMax Range Permainan     : %d", max);
	printf("\n\tMin Range Permainan     : %d", min);
	printf("\n\tNilai tebakan           : %d", kunci);
}
