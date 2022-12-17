#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hargaA 500000
#define hargaB 650000
#define hargaC 700000


typedef char string[50];

void init( int *toleransi, int *tipeA, int *tipeB, int *tipeC, int *pembeli, int *pembelian, int *jmlA,
		   int *jmlB, int *jmlC, int *totA, int *totB, int *totC, int *total);
void cekLog(int *cek, string user, int pass);
void pengurangan(int *angka, int pengurang);
void penjumlahann(int *angka, int penjumlah);
void perkalian(int *hasil, int angka, int pengali);
void cekHarga(int *harga, string tipe);
void cekJumlahTipe(int *temp, int tasA, int tasB, int tasC, string tipe);
void pembaruanStockTas(int *tasA, int *tasB, int *tasC, int *jmlA, int *jmlB, int *jmlC, int jml, string tipe);
void printRincian(string nama, string tgl, int jmlA, int jmlB, int jmlC, int totA, int totB, int totC, int total);
void hitungTotal(int *tot, int jmlA, int jmlB, int jmlC);
void cekLogout(int *cekLog, string konfirm);

int main(int argc, char *argv[]) {
	string user, konfirm, nama, tgl, tipe;
	int pass, menu, cek, logout, harga, jumlah, tempJumlah;
	int toleransi, tipeA, tipeB, tipeC, pembeli, pembelian, jmlA, jmlB, jmlC, totA, totB, totC, total;

	init(&toleransi, &tipeA, &tipeB, &tipeC, &pembeli, &pembelian, &jmlA, &jmlB, &jmlC, &totA, &totB, &totC, &total);

	do{
		logout=0;
		system("cls");
		printf("\n\t\t--- LOGIN SYSTEM ---");
		printf("\n  Toleransi: %d\n", toleransi);
		printf("\tUsername : "); fflush(stdin); gets(user);
		printf("\tPassword : "); scanf("%d", &pass);
		cekLog(&cek, user, pass);

		if(cek==1){
			do{
				system("cls");
				printf("\n\tTOKO TAS SISKA");
				printf("\n\t---- MENU ----");
				printf("\n %d Tipe A - %d Tipe B - %d Tipe C", tipeA,tipeB,tipeC);
				printf("\n[1] Input data pembeli");
				printf("\n[2] Input pembelian");
				printf("\n[3] Rincian");
				printf("\n[0] Logout");
				printf("\n>>> "); scanf("%d", &menu);

				switch (menu){
				case 1:
					if(pembeli==1){
						printf("\n Data pembeli sudah terinput [!]");

					}else{
						printf("\n\t---- INPUT DATA PEMBELI ----\n");
						printf("\nNama : "); fflush(stdin); gets(nama);
						while(strlen(nama)==0 || strcmp(nama,"-")==0){
							printf("\nNama tidak boleh kosong [!]");
							printf("\nNama : "); fflush(stdin); gets(nama);
						}
						printf("\nTanggal pembelian : "); fflush(stdin); gets(tgl);
						while(strlen(tgl)!=10){
							printf("\nTanggal salah [!]");
							printf("\nTanggal pembelian : "); fflush(stdin); gets(tgl);
						}
						printf("\nBerhasil input data pembeli...");
						pembeli=1;
					}
				break;
				
				case 2:
					if(pembeli==0){
						printf("\nData pembeli belum ada [!}");
					}else{
						printf("\n\t--- INPUT PEMBELIAN\n");
						printf("\nTipe tas (A/B/C) : "); fflush(stdin); gets(tipe);
						while(strcmpi(tipe, "A")!=0 && strcmpi(tipe,"B")!=0 && strcmpi(tipe,"C")!=0){
							printf("\nTipe tidak diketahui [!]");
							printf("\nTipe tas (A/B/C) : "); fflush(stdin); gets(tipe);
						}
						
						cekHarga(&harga, tipe);
						printf("\n\tHarga				: %d", harga);
						printf("\n\tJumlah pembelian		: "); scanf("%d", &jumlah);
						cekJumlahTipe(&tempJumlah, tipeA, tipeB, tipeC, tipe);

						if(jumlah<=0){
							printf("\n\t Jumlah pembelian tidak boleh kurang dari 1 [!]");
						}else if(jumlah>tempJumlah){
							printf("\n\t Jumlah pembelian melebihi ketersediaan [!]");
							
						}else{
							pembaruanStockTas(&tipeA, &tipeB, &tipeC, &jmlA, &jmlB, &jmlC, jumlah, tipe);
							printf("\nBerhasil input pembelian...");
							pembelian=1;
						}
					}
				break;

				case 3:
					if(pembeli==0){
						printf("\nData pembeli belum ada [!]");
					}else if(pembelian==0){
						printf("\nBelum ada pembelian [!]");
					}else{
						printf("\n\t\t--- RINCIAN ---\n");
						perkalian(&totA, jmlA, hargaA);
						perkalian(&totB, jmlB, hargaB);
						perkalian(&totC, jmlC, hargaC);

						hitungTotal(&total, totA, totB, totC);
						printRincian(nama, tgl,jmlA, jmlB, jmlC, totA, totB, totC, total);
					}
				break;

				case 0:
					printf("\nYakin ingin logout? (Ya/Tidak)\n\t"); fflush(stdin); gets(konfirm);
					cekLogout(&logout, konfirm);

					if(logout==1){
						printf("\nTerima kasih...");
						init(&toleransi, &tipeA, &tipeB, &tipeC, &pembeli, &pembelian,
							 &jmlA, &jmlB, &jmlC, &totA, &totB, &totC, &total);
					}
				break;

				default:
					printf("\nMenu tidak tersedia [!]");
				break;
				}getch();
			}while(logout!=1);
		}else{
			printf("\n\t\t Username atau password salah [!]");
			pengurangan(&toleransi, 1);
		}
		getch();
	}while(toleransi !=0);

	printf("\n\n\t Keluar");
	printf("\n\t Terima kasih...");
	return 0;
}

void init( int *toleransi, int *tipeA, int *tipeB, int *tipeC, int *pembeli, int *pembelian, int *jmlA,
		   int *jmlB, int *jmlC, int *totA, int *totB, int *totC, int *total){
			   *toleransi = 5;
			   *tipeA = 10;
			   *tipeB = 10;
			   *tipeC = 10;
			   *pembeli = 0;
			   *pembelian = 0; 
			   *jmlA = 0;
			   *jmlB = 0;
			   *jmlC = 0;
			   *totA = 0;
			   *totB = 0;
			   *totC = 0;
			   *total = 0;
		   }
void cekLog(int *cek, string user, int pass){
	if(strcmp(user, "Siska")==0 && pass==12345){
		*cek=1;
	}else{
		*cek=0;
	}
}

void pengurangan(int *angka, int pengurang){
	(*angka) = (*angka) - pengurang;
}
void penjumlahan(int *angka, int penjumlah){
	(*angka) = (*angka) + penjumlah;
}
void perkalian(int *hasil, int angka, int pengali){
	(*hasil)= angka * pengali;
}
void cekHarga(int *harga, string tipe){
	if(strcmpi(tipe,"A")==0){
		*harga=hargaA;
	}else if(strcmpi(tipe,"B")==0){
		*harga=hargaB;
	}else{
		*harga=hargaC;
	}
}
void cekJumlahTipe(int *temp, int tasA, int tasB, int tasC, string tipe){
	if(strcmpi(tipe,"A")==0){
		*temp = tasA;
	}else if(strcmpi(tipe,"B")==0){
		*temp = tasB;
	}else{
		*temp = tasC;
	}
}
void pembaruanStockTas(int *tasA, int *tasB, int *tasC, int *jmlA, int *jmlB, int *jmlC, int jml, string tipe){
	if(strcmpi(tipe,"A")==0){
		pengurangan(&(*tasA),jml);
		penjumlahan(&(*jmlA),jml);
	}else if(strcmpi(tipe, "B")==0){
		pengurangan(&(*tasB),jml);
		penjumlahan(&(*jmlB),jml);
	}else{
		pengurangan(&(*tasC),jml);
		penjumlahan(&(*jmlC),jml);
	}
}
void printRincian(string nama, string tgl, int jmlA, int jmlB, int jmlC, int totA, int totB, int totC, int total){
	printf("\n\tNama 			: %s", nama);
	printf("\n\tTanggal pembelian	: %s", tgl);
	printf("\n\t [Tas A]	| %d | |\t| @Rp %d |\t---> Total : Rp. %d", jmlA, hargaA, totA);
	printf("\n\t [Tas A]	| %d | |\t| @Rp %d |\t---> Total : Rp. %d", jmlB, hargaB, totB);
	printf("\n\t [Tas A]	| %d | |\t| @Rp %d |\t---> Total : Rp. %d", jmlC, hargaC, totC);

	printf("\n\n\tTotal yang harus dibayar : %d", total);
}
void hitungTotal(int *tot, int jmlA, int jmlB, int jmlC){
	*tot = jmlA + jmlB + jmlC;
}
void cekLogout(int *logout, string konfirm){
	if(strcmp(konfirm, "ya")==0){
		*logout=1;
	}else{
		*logout=0;
	}
}
