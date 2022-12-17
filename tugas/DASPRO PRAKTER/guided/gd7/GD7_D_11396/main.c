#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef char string[50];
void tampilMenu();
void setBilangan(int *BilanganAsli, int inputan);
void tampilOperasi(string operasi, int angka1, int angka2, int hasil);

void prosedurPenjumlahan(int *hasil, int input1, int input2);
void prosedurPengurangan(int *hasil, int input1, int input2);
void laporanOperasi(bool sudahJumlah, bool sudahKurang, int hasilJumlah, int hasilKurang);

void inputBilangan(int *temp);
void tebakAngka(int *inputan);

int main() {	

	srand(time(NULL));

	int menu;
	int temp;
	int i;

	bool sudahInputBilangan = false;
	bool sudahPenjumlahan = false;
	bool sudahPengurangan = false;

	int bilangan1;
	int bilangan2;
	int hasilPenjumlahan;
	int hasilPengurangan;

	bool sudahInputN = false;
	int inputan;
	int n;

	do{
		tampilMenu();
		printf("\n>>> "); scanf("%d", &menu);

		switch(menu){
			case 1:
				printf("\n\t--- Input Bilangan ---");
					do{
						printf("\nInput Bilangan Pertama: "); scanf("%d", &temp);
						if(temp<0){
							printf("\nInputan tidak boleh < 0\n");
						}else{
							break;
						}
					}while(true);

				setBilangan(&bilangan1, temp);
					do{
						printf("\nInput Bilangan Kedua "); scanf("%d", &temp);
						if(temp<0){
							printf("\nInputan tidak boleh < 0\n");
						}else{
							break;
						}
					}while(true);
				setBilangan(&bilangan2, temp);
				sudahInputBilangan=true;
				printf("\n\t Berhasil Input Bilangan");
			break;

			case 2:
				if(!sudahInputBilangan){
					printf("\n\tBelum Input Bilangan !");
				}else{
					printf("\n\t--- Penjumlahan ---");
					prosedurPenjumlahan(&hasilPenjumlahan, bilangan1, bilangan2);
					tampilOperasi("Penjumlahan", bilangan1, bilangan2, hasilPenjumlahan);
					sudahPenjumlahan=true;
				}
			break;

			case 3:
				if(!sudahInputBilangan){
					printf("\n\t Belum Input Bilangan !");
				}else{
					printf("\n\t--- Pengurangan ---");
					prosedurPengurangan(&hasilPengurangan, bilangan1, bilangan2);
					tampilOperasi("Pengurangan", bilangan1, bilangan2, hasilPengurangan);
					sudahPengurangan=true;
				}
			break;

			case 4:
				if(!sudahInputBilangan){
					printf("\n\t Belum Input Bilangan !");
				}else{
					printf("\n\t--- Lapooran ---\n");
					laporanOperasi(sudahPenjumlahan, sudahPengurangan, hasilPenjumlahan, hasilPengurangan);
				}
			break;

			case 5:
			 inputBilangan(&n);

			 sudahInputN = true;
			break;

			case 6:
			if(!sudahInputN){
				printf("\n\tBelum Input N !");
			}else{
				for(i=0;i<n;i++){
					tebakAngka(&inputan);
					printf("\tKamu menginputkan: %d\n", inputan);
				}
			}
			break;

			case 0:
				printf("\n\t Program Keluar");
				printf("\n\t <Made Riksi Purnama Sadnya Agung> - <210711396>");
			break;

			default:
				printf("\n\t Menu tidak tersedia !");
			break;
		}

		getch();
	}while(menu!=0);
	return 0;
}
	void tampilMenu(){
		system("cls");
		printf("\n\t--- Guided ---");
		printf("\n[1] Input Bilangan");
		printf("\n[2] Penjumlahan   ");
		printf("\n[3] Pengurangan   ");
		printf("\n[4] Laporan       ");
		printf("\n------------------");
		printf("\n[5] Input N				");
		printf("\n[6] Input Sebanyak N Kali ");
		printf("\n[0] Keluar Program		");
	}
	void setBilangan(int *BilanganAsli, int inputan){
		*BilanganAsli = inputan;
	}
	void prosedurPenjumlahan(int *hasil, int input1, int input2){
		*hasil = input1 + input2;
	}
	void prosedurPengurangan(int *hasil, int input1, int input2){
		*hasil = input1 - input2;
	}

	void tampilOperasi(string operasi, int angka1, int angka2, int hasil){
		printf("\n\t%s %d dan %d", operasi, angka1, angka2);
		printf("\n\tMenghasilkan: %d", hasil);
	}

	void laporanOperasi(bool sudahJumlah, bool sudahKurang, int hasilJumlah, int hasilKurang){

		printf("\n\tHasil Penjumlahan Terakhir: ");
		if(sudahJumlah){
			printf("%d", hasilJumlah);
		}else{
			printf("<Belum ada>");
		}
		
		printf("\n\tHasil Pengurangan Terakhir: ");
		if(sudahKurang){
			printf("%d", hasilKurang);
		}else{
			printf("<Belum ada>");
		}
	}

	void inputBilangan(int *temp){
		int menu;
		system("cls");
		printf("\n\t--- Input N ---");
		printf("\n[1] Dari User");
		printf("\n[2] Random [1-10]");
		printf("\n>>> "); scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			do{
				printf("\n\tInput N: "); scanf("%d", temp);
				if(*temp<0){
					printf("\t\t[!] Tidak Boleh Negatif\n");
				}else{
					break;
				}
			}while(true);
			printf("\n\t Berhasil Input N");
			break;
		case 2:
			*temp = (rand() % (10-1+1)+1);
			printf("\n\t Berhasil input N");
			printf("\n\tNilai N: %d", *temp);
			break;
		default:
			printf("\n\t Menu tidak tersedia !!!");
			printf("\nKembali ke menu awal...");
			break;
		}
	}
	void tebakAngka(int *inputan){
		int temp;
		printf("\n\t Tebak Bilangan : "); scanf("%d", &temp);

		*inputan =temp;
	}


