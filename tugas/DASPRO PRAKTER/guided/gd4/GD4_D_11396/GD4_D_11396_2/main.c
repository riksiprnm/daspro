#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

typedef char string[30];

// Made Riksi Purnama Sadnya Agung / 210711396 / D
int main() {
	
	string user, nama, npm, jawab;
	int pil;
	bool menu = true;
	int cekLog=0;
	int cekInput=0;
	
	while(menu==true){
		system("cls");
		printf("\n\t---=== GD PEMILIHAN SWITCH CASE ===---");
		printf("\n\t1. Login");
		printf("\n\t2. Input Data");
		printf("\n\t3. Tampil Data");
		printf("\n\t0. Keluar");
		printf("\n\tPilih menu > "); scanf("%d", &pil);

		switch(pil){
			case 1:
				if(cekLog==0){
					printf("\n\t[Login]");
					printf("\n\tUser : "); fflush(stdin); gets(user);

					if(strcmpi(user, "riksi")==0 || strcmpi(user,"Admin")==0){
						printf("\n\t\tBerhasil login...");
						cekLog=1;
					} else printf("\n\t\tUser tidak ditemukan[!]");
				} else{
					printf("\n\t\tAnda sudah login[!]");
				}
			break;

			case 2:
			if(cekLog==0) printf("\n\t\tAnda harus login terlebih dahulu[!]");
			else if(cekInput==1) printf("\n\t\tAnda sudah input data[!]");
			else{
				printf("\n\t[Input Data]");
				printf("\n\tNama : "); fflush(stdin); gets(nama);
				printf("\n\tNPM  : "); fflush(stdin); gets(npm);
				printf("\n\t\tBerhasil input data...");
				cekInput=1;
			}
			break;
			
			case 3: 
				if(cekLog==0) printf("\n\t\tAnda harus login terlebih dahulu[!]");
				else if(cekInput==0) printf("\n\t\tAnda belum input data[!]");
				else{
					printf("\n\t[Tampil data]");
					printf("\n\tNama  : %s", nama);
					printf("\n\tNPM   : %s", npm);

					printf("\n\tIngin hapus data ini [Ya|Tidak] : ");
					fflush(stdin); gets(jawab);

					if(strcmpi(jawab, "ya")==0){
						cekInput=0;
						printf("\n\t\tData berhasil terhapus...");
					}
				}
			break;

			case 0:
				printf("\n\t\tKeluar dari program...");
				menu = false;
			break;

			default:
				printf("\n\t\tMenu tidak ada[!]");
			break;
		}getch();
	}
	return 0;
}
