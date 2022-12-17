#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[50];


typedef struct{
	string nama;
	string nidn;
}Dospem;
typedef struct{
	string nama;
	float ipk;
	int umur;
	Dospem DP;
}Mahasiswa;

void init(Mahasiswa *mhs);
void menu();
int alreadyInputMhs(Mahasiswa mhs);
int alreadyInputDospem(Mahasiswa mhs);
void tampilData(Mahasiswa mhs);
int tahunLahir(Mahasiswa mhs);

int main(int argc, char *argv[]) {
	Mahasiswa mhs;
	int pil[2];
	string jwb;
	init(&mhs);
	do{
		system("cls");
		menu();
		printf("\n\t>>> "); scanf("%d", &pil[0]);
		switch(pil[0]){
			case 1:
				if(alreadyInputMhs(mhs)==0){
					printf("\n\t\tInput Data\n");
					printf("\n\tMasukkan nama mahasiswa : "); fflush(stdin); gets(mhs.nama);
					while(strlen(mhs.nama)==0){
						printf("\n\t\t[!] Nama tidak boleh kosong\n");
						printf("\n\tMasukkan nama mahasiswa : "); fflush(stdin); gets(mhs.nama);
					}
					printf("\tMasukkan IPK mahasiswa  : "); scanf("%f", &mhs.ipk);
					printf("\tMasukkan umur mahasiswa : "); scanf("%d", &mhs.umur);
					printf("\n\tApakah sudah ada dosen pembimbing? [Y/N] ");
					printf("\n\t>>> "); fflush(stdin); gets(jwb);
					if(strcmpi(jwb,"y")==0){
						printf("\n\tMasukkan nama dosen pembimbing : "); fflush(stdin); gets(mhs.DP.nama);
						while(strlen(mhs.DP.nama)==0){
							printf("\n\t\t[!] Nama tidak boleh kosong\n");
							printf("\n\tMasukkan nama dosen pembimbing : "); fflush(stdin); gets(mhs.DP.nama);
						}
						printf("\tMasukkan nidn dosen pembimbing : "); fflush(stdin); gets(mhs.DP.nidn);
						printf("\n\t\tInput data selesai !");
					}else{
						
						printf("\n\t\tInput sudah selesai !");
					}
				}else{
					printf("\n\t\t[!] Data mahasiswa sudah diinput");
				}
			break;
			case 2:
				if(alreadyInputMhs(mhs)==1){
					tampilData(mhs);
				}else{
					printf("\n\t\t[!] Data mahasiswa belum diinput");
				}
			break;
			case 3:
				if(alreadyInputMhs(mhs)==1){
					printf("\n\t\tUbah Data\n");
					printf("\n\t[1] Data mahasiswa");
					printf("\n\t[2] Data dosen pembimbing");
					printf("\n\t>>> "); scanf("%d", &pil[1]);
					switch(pil[1]){
						case 1:
							printf("\n\tMasukkan nama mahasiswa : "); fflush(stdin); gets(mhs.nama);
							while(strlen(mhs.nama)==0){
								printf("\n\t\t[!] Nama tidak boleh kosong\n");
								printf("\n\tMasukkan nama mahasiswa : "); fflush(stdin); gets(mhs.nama);
							}
							printf("\tMasukkan IPK mahasiswa  : "); scanf("%f", &mhs.ipk);
							printf("\tMasukkan umur mahasiswa : "); scanf("%d", &mhs.umur);
							printf("\n\t\tInput sudah selesai !");
						break;
						case 2:
							printf("\n\tMasukkan nama dosen pembimbing : "); fflush(stdin); gets(mhs.DP.nama);
							while(strlen(mhs.DP.nama)==0){
								printf("\n\t\t[!] Nama tidak boleh kosong\n");
								printf("\n\tMasukkan nama dosen pembimbing : "); fflush(stdin); gets(mhs.DP.nama);
							}
							printf("\tMasukkan nidn dosen pembimbing : "); fflush(stdin); gets(mhs.DP.nidn);
							printf("\n\t\tInput data selesai !");
						break;
						default:
							printf("\n\t\t[!] Menu tidak ditemukan");
							printf("\n\t\tKembali ke menu utama...");
						break;
					}
				}else{
					printf("\n\t\t[!] Data mahasiswa belum diinput");
				}
			break;
			case 4:
				if(alreadyInputMhs(mhs)==1){
					printf("\n\n\tYakin menghapus data? [Y/N]"); fflush(stdin); gets(jwb);
					if(strcmpi(jwb,"y")==0){
						init(&mhs);
						printf("\n\t\tData berhasil dihapus");
					}else if(strcmpi(jwb,"n")==0){
						printf("\n\t\tData batal dihapus");
					}else{
						printf("\n\t\t[!] Jawaban tidak valid");
						printf("\n\t\tData batal dihapus");
					}
				}else{
					printf("\n\t\t[!] Data mahasiswa belum diinput");
				}
			break;
			case 0:	
				printf("\n\tMade Riksi Purnama Sadnya Agung - 210711396 - Praktikum Dasar Pemrograman D");
			break;
			default:
				printf("\n\t\t[!] Menu tidak ditemukan");
			break;
		}
		getch();
	}while(pil[0]!=0);
	return 0;
}
void init(Mahasiswa *mhs){
	strcpy((*mhs).nama,"");
	(*mhs).ipk=0;
	(*mhs).umur=0;
	strcpy((*mhs).DP.nama,"");
	strcpy((*mhs).DP.nidn,"");
}
void menu(){
	printf("\n\t\t--=== Mahasiswa x Dosen Pembimbing ===--\n");
	printf("\n\t[1] Input Data");
	printf("\n\t[2] Tampil Data");
	printf("\n\t[3] Ubah Data");
	printf("\n\t[4] Hapus Data");
	printf("\n\t[0] Keluar");
}
int alreadyInputMhs(Mahasiswa mhs){
	if(strlen(mhs.nama)==0) return 0;
	return 1;
}
int alreadyInputDospem(Mahasiswa mhs){
	if(strlen(mhs.DP.nama)==0) return 0;
	return 1;
}
void tampilData(Mahasiswa mhs){
	printf("\n\t\tTampil Data\n");
	printf("\n\t[~] Data Mahasiswa :");
	printf("\n\tNama mahasiswa : %s", mhs.nama);
	printf("\n\tIPK mahasiswa  : %.2f", mhs.ipk);
	printf("\n\tUmur mahasisaw : %d", mhs.umur);
	printf("\n\tTahun lahir    : %d", tahunLahir(mhs));
	if(alreadyInputDospem(mhs)==1){
		printf("\n\n\t\t[~] Data Dosen Pembimbing :");
		printf("\n\t\tNama dosen pembimbing   : %s", mhs.DP.nama);
		printf("\n\t\tNidn dosen pembimbing   : %s", mhs.DP.nidn);
	}else{
		printf("\n\n\t[Untuk data dosen pembimbing belum ada]");
	}
}

int tahunLahir(Mahasiswa mhs){
	return 2022-mhs.umur;
}