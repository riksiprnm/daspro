#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[50];

typedef struct{
	string nama;
	string penyakit;
}Pasien;

typedef struct{
	string nama;
	int noInduk;
	Pasien pasien[2];
}Dokter; 

void initData(Dokter dokter[]); //pendeklarasian prosedur inisialisasi record 'dokter'

int main() {
	Dokter dokter[3]; 

	initData(dokter); //pemanggilan prosedur

	return 0;
}

void initData(Dokter dokter[]){ //code
	int i,j;
	for(i=0;i<3;i++){
		strcpy(dokter[i].nama,"-");
		dokter[i].noInduk=0;

		for(j=0;j<2;j++){
			strcpy(dokter[i].pasien[j].nama,"-");
			strcpy(dokter[i].pasien[j].penyakit,"-");
		}
	}
}

