#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define ESC 27

typedef char string[50];

typedef struct{
	string nama;
	string kelas;
}Kamar_11396;

typedef struct{
	string nama;
	string noInduk;
}Dokter_11396;

typedef struct{
	string nama;
	string penyakit;
	int jmlObat;
	string namaObat[10];
	Kamar_11396 kamar;
	Dokter_11396 dokter;
}Pasien_11396;

void menu();
void subMenu();
void init(Pasien_11396 *p1);
void tampilData(Pasien_11396 p1);
void hapusDataObat(Pasien_11396 *p1);
int isEmpty(Pasien_11396 p1);
int isSameDrugs(string temp, Pasien_11396 p1);
int cekNamaKamar(Pasien_11396 p1);
int takeIndex(Pasien_11396 p1, string temp);

int main(int argc, char *argv[]) {
	char pil,pil2;
	int i, index;
	string temp, ans;;
	Pasien_11396 p1;
	init(&p1);
	do{
		system("cls");
		menu();
		printf("\n\t>> "); pil=getch();
		switch(pil){
			case '1':
				if(isEmpty(p1)==0){
					printf("\n\t\t-= Input Data Perawatan =-\n");
					printf("\n\tMasukkan nama pasien : "); fflush(stdin); gets(p1.nama);
					while(strlen(p1.nama)==0){
						printf("\n\t\t[!] Nama pasien tidak boleh kosong\n");
						printf("\n\tMasukkan nama pasien : "); fflush(stdin); gets(p1.nama);
					}
					printf("\n\tMasukkan nama penyakit : "); fflush(stdin); gets(p1.penyakit);
					while(strlen(p1.penyakit)==0){
						printf("\n\t\t[!] Nama penyakit tidak boleh kosong\n");
						printf("\n\tMasukkan nama penyakit : "); fflush(stdin); gets(p1.penyakit);
					}
					printf("\n\tMasukkan jumlah obat : "); scanf("%d", &p1.jmlObat);
					while(p1.jmlObat<1 || p1.jmlObat>10){
						printf("\n\t\t[!] Jumlah obat tidak boleh kurang dari 1 atau lebih dari 10\n");
						printf("\n\tMasukkan jumlah obat : "); scanf("%d", &p1.jmlObat);
					}
					
					for(i=0;i<p1.jmlObat;i++){
						printf("\n\tMasukkan nama obat ke-%d : ",i+1); fflush(stdin); gets(temp);
						while(strlen(temp)==0 || isSameDrugs(temp,p1)==1){
							if(strlen(temp)==0){
								printf("\n\t\t[!] Nama obat tidak boleh kosong\n");
							}else if(isSameDrugs(temp,p1)==1){
								printf("\n\t\t[!] Nama obat tidak boleh sama (harus unik)\n");
							}
							printf("\n\tMasukkan nama obat ke-%d : ",i+1); fflush(stdin); gets(temp);
						}
						strcpy(p1.namaObat[i],temp);
					}

					printf("\n\tMasukkan nama dokter : "); fflush(stdin); gets(p1.dokter.nama);
					while(strlen(p1.dokter.nama)==0){
						printf("\n\t\t[!] Nama dokter tidak boleh kosong\n");
						printf("\n\tMasukkan nama dokter : "); fflush(stdin); gets(p1.dokter.nama);
					}
					printf("\n\tMasukkan nomer induk dokter : "); fflush(stdin); gets(p1.dokter.noInduk);
					while(strlen(p1.dokter.noInduk)!=9){
						printf("\n\t\t[!] Nomer induk dokter harus 9 karakter\n");
						printf("\n\tMasukkan nomer induk dokter : "); fflush(stdin); gets(p1.dokter.noInduk);
					}
					printf("\n\tApakah ingin menginputkan data kamar? [Y/N] "); fflush(stdin); gets(ans);
					if(strcmpi(ans,"y")==0){
						printf("\n\tMasukkan nama kamar : "); fflush(stdin); gets(p1.kamar.nama);
						while(strlen(p1.kamar.nama)==0){
							if(strlen(p1.kamar.nama)==0){
								printf("\n\t\t[!] Nama kamar tidak boleh kosong\n");
							}
							printf("\n\tMasukkan nama kamar : "); fflush(stdin); gets(p1.kamar.nama);
						}
						printf("\n\tMasukkan kelas kamar [I/II/III/VIP/VVIP] : "); fflush(stdin); gets(p1.kamar.kelas);
						while(cekNamaKamar(p1)==0){
							printf("\n\t\t[!] Kelas kamar tidak valid\n");
							printf("\n\tMasukkan kelas kamar [I/II/III/VIP/VVIP] : "); fflush(stdin); gets(p1.kamar.kelas);
						}
						printf("\n\t\t[~] Pengisian data pasien selesai . . .");
					}else if(strcmpi(ans,"n")==0){
						printf("\n\t\t[~] Pengisian data pasien selesai . . .");
					}else{
						printf("\n\t\t[!] Jawaban tidak valid\n");
						printf("\n\t\t[~] Pengisian data pasien selesai . . .");
					}
				}else{
					printf("\n\t\t[!] Data pasien sudah diisi");
				}
			break;
			case '2':
				if(isEmpty(p1)==1){
					tampilData(p1);
				}else{
					printf("\n\t\t[!] Data pasien belum diisi");
				}

			break;
			case '3':
				if(isEmpty(p1)==1){
					subMenu();
					printf("\n\t>> "); pil2=getch();
					switch(pil2){
						case '1':
							printf("\n\t\t-= Pengubahan Data Pasien =-\n");
							printf("\n\tMasukkan nama pasien : "); fflush(stdin); gets(p1.nama);
							while(strlen(p1.nama)==0){
								printf("\n\t\t[!] Nama pasien tidak boleh kosong\n");
								printf("\n\tMasukkan nama pasien : "); fflush(stdin); gets(p1.nama);
							}
							printf("\n\tMasukkan nama penyakit : "); fflush(stdin); gets(p1.penyakit);
							while(strlen(p1.penyakit)==0){
								printf("\n\t\t[!] Nama penyakit tidak boleh kosong\n");
								printf("\n\tMasukkan nama penyakit : "); fflush(stdin); gets(p1.penyakit);
							}
							printf("\n\t\t[~] Berhasil mengubah data pasien . . .");
						break;
						case '2':
							printf("\n\t\t-= Pengubahan Data Dokter =-\n");
							printf("\n\tMasukkan nama dokter : "); fflush(stdin); gets(p1.dokter.nama);
							while(strlen(p1.dokter.nama)==0){
								printf("\n\t\t[!] Nama dokter tidak boleh kosong\n");
								printf("\n\tMasukkan nama dokter : "); fflush(stdin); gets(p1.dokter.nama);
							}
							printf("\n\tMasukkan nomer induk dokter : "); fflush(stdin); gets(p1.dokter.noInduk);
							while(strlen(p1.dokter.noInduk)!=9){
								printf("\n\t\t[!] Nomer induk dokter harus 9 karakter\n");
								printf("\n\tMasukkan nomer induk dokter : "); fflush(stdin); gets(p1.dokter.noInduk);
							}
							printf("\n\t\t[~] Berhasil mengubah data dokter . . .");
						break;
						case '3':
							printf("\n\t\t-= Pengubahan Data Kamar =-\n");
							printf("\n\tMasukkan nama kamar : "); fflush(stdin); gets(p1.kamar.nama);
							while(strlen(p1.kamar.nama)==0){
								if(strlen(p1.kamar.nama)==0){
									printf("\n\t\t[!] Nama kamar tidak boleh kosong\n");
								}
								printf("\n\tMasukkan nama kamar : "); fflush(stdin); gets(p1.kamar.nama);
							}
							printf("\n\tMasukkan kelas kamar [I/II/III/VIP/VVIP] : "); fflush(stdin); gets(p1.kamar.kelas);
							while(cekNamaKamar(p1)==0){
								printf("\n\t\t[!] Kelas kamar tidak valid\n");
								printf("\n\tMasukkan kelas kamar [I/II/III/VIP/VVIP] : "); fflush(stdin); gets(p1.kamar.kelas);
							}
							printf("\n\t\t[~] Berhasil mengubah data kamar . . .");
						break;
						case '4':
							printf("\n\t\t-= Pengubahan Semua Obat =-\n");
							hapusDataObat(&p1);
							printf("\n\tMasukkan jumlah obat : "); scanf("%d", &p1.jmlObat);
							while(p1.jmlObat<1 || p1.jmlObat>10){
								printf("\n\t\t[!] Jumlah obat tidak boleh kurang dari 1 atau lebih dari 10\n");
								printf("\n\tMasukkan jumlah obat : "); scanf("%d", &p1.jmlObat);
							}
							
							for(i=0;i<p1.jmlObat;i++){
								printf("\n\tMasukkan nama obat ke-%d : ",i+1); fflush(stdin); gets(temp);
								while(strlen(temp)==0 || isSameDrugs(temp,p1)==1){
									if(strlen(temp)==0){
										printf("\n\t\t[!] Nama obat tidak boleh kosong\n");
									}else if(isSameDrugs(temp,p1)==1){
										printf("\n\t\t[!] Nama obat tidak boleh sama (harus unik)\n");
									}
									printf("\n\tMasukkan nama obat ke-%d : ",i+1); fflush(stdin); gets(temp);
								}
								strcpy(p1.namaObat[i],temp);
							}
							printf("\n\t\t[~] Berhasil mengubah semua data obat");
						break;

						case '5':
							printf("\n\t\t-= Pengubahan Salah Satu Obat =-\n");
							printf("\n\tMasukkan nama obat yang ingin diubah : "); fflush(stdin); gets(temp);
							if(isSameDrugs(temp,p1)==1){
								index=takeIndex(p1,temp);
								printf("\n\tMasukkan nama obat yang baru : "); fflush(stdin); gets(temp);
								while(isSameDrugs(temp,p1)==1 || strlen(temp)==0){
									if(strlen(temp)==0){
										printf("\n\t\t[!] Nama obat tidak boleh kosong\n");
									}else if(isSameDrugs(temp,p1)==1){
										printf("\n\t\t[!] Nama obat tidak boleh sama (harus unik)\n");
									}
									printf("\n\tMasukkan nama obat yang baru : "); fflush(stdin); gets(temp);
								}
								printf("\n\tYakin ingin mengganti nama obat? [Y/N] "); fflush(stdin); gets(ans);
								if(strcmpi(ans,"y")==0){
									strcpy(p1.namaObat[index],temp);
									printf("\n\t\t[~] Penggantian nama obat berhasil");
								}else if(strcmpi(ans,"n")==0){
									printf("\n\t\t[~] Penggantian nama obat dibatalkan");
								}else{
									printf("\n\t\t[!] Jawaban tidak valid");
									printf("\n\t\t[~] Penggantian nama obat dibatalkan");
								}
							}else{
								printf("\n\t\t[!] Nama obat tidak ditemukan");
							}

						break;
						default:
							printf("\n\t\t[!] Menu tidak ditemukan");
						break;
					}
				}else{
					printf("\n\t\t[!] Data pasien belum diisi");
				}
			break;
			case '4':
				if(isEmpty(p1)==1){
					printf("\n\tYakin ingin menghapus data pasien? [Y/N] "); fflush(stdin); gets(ans);
					if(strcmpi(ans,"y")==0){
						init(&p1);
						printf("\n\t\t[~] Berhasil menghapus data pasien");
					}else if(strcmpi(ans,"n")==0){
						printf("\n\t\t[~] Penghapusan data dibatalkan");
					}else{
						printf("\n\t\t[!] Jawaban tidak valid");
						printf("\n\t\t[~] Penghapusan data dibatalkan");
					}
				}else{
					printf("\n\t\t[!] Data pasien belum diisi");
				}
			break;
			case 27:
				printf("\n\tMade Riksi Purnama Sadnya Agung - 210711396 - Praktikum Dasar Pemrograman D");
			break;
			default:
				printf("\n\t\t[!] Menu tidak tersedia");
			break;
		}
		getch();
	}while(pil!=27);
	return 0;
}
void menu(){
	printf("\n\t\t--=== Atma Hospital ===--\n");
	printf("\n\t[1] Input Data");
	printf("\n\t[2] Tampil Data");
	printf("\n\t[3] Ubah Data");
	printf("\n\t[4] Hapus Data");
	printf("\n\t[ESC] Exit");

}
void subMenu(){
	printf("\n\t\t-= Ubah Data Perawatan =-\n");
	printf("\n\t[1] Data Pasien");
	printf("\n\t[2] Data Dokter");
	printf("\n\t[3] Data Kamar");
	printf("\n\t[4] Data Semua Obat");
	printf("\n\t[5] Data Salah Satu Obat");
}
void init(Pasien_11396 *p1){
	int i;

	strcpy((*p1).nama,"");
	strcpy((*p1).penyakit,"");

	(*p1).jmlObat = 0;
	for(i=0;i<10;i++){
		strcpy((*p1).namaObat[i],"");
	}

	strcpy((*p1).kamar.nama,"");
	strcpy((*p1).kamar.kelas,"");
	strcpy((*p1).dokter.nama,"");
	strcpy((*p1).dokter.noInduk,"");

}
void hapusDataObat(Pasien_11396 *p1){
	int i;
	for(i=0;i<10;i++){
		strcpy((*p1).namaObat[i],"");
	}
}
int isEmpty(Pasien_11396 p1){
	if(strlen(p1.nama)==0) return 0;
	else return 1;
}
int isSameDrugs(string temp, Pasien_11396 p1){
	int i;
	for(i=0;i<10;i++){
		if(strcmpi(temp, p1.namaObat[i])==0) return 1;
	}
	return 0;
	
}
int cekNamaKamar(Pasien_11396 p1){
	if(strcmp(p1.kamar.kelas,"I")==0) return 1;
	else if(strcmp(p1.kamar.kelas,"II")==0) return 1;
	else if(strcmp(p1.kamar.kelas,"III")==0) return 1;
	else if(strcmp(p1.kamar.kelas,"VIP")==0) return 1;
	else if(strcmp(p1.kamar.kelas,"VVIP")==0) return 1;
	else return 0;
}
int takeIndex(Pasien_11396 p1, string temp){
	int i;
	for(i=0;i<10;i++){
		if(strcmpi(temp,p1.namaObat[i])==0) return i;
	}
}

void tampilData(Pasien_11396 p1){
	int i;
	printf("\n\t\t-= Tampil Data Perawatan =-\n");
	printf("\n\t[Pasien]");
	printf("\n\tNama pasien   : %s",p1.nama);
	printf("\n\tNama penyakit : %s",p1.penyakit);
	printf("\n\tJumlah obat   : %d", p1.jmlObat);
	for(i=0;i<p1.jmlObat;i++){
		printf("\n\t\tNama obat ke-%d : %s",i+1,p1.namaObat[i]);
	}
	printf("\n\n\t[Dokter]");
	printf("\n\tNama dokter     : %s", p1.dokter.nama);
	printf("\n\tNo induk dokter : %s", p1.dokter.noInduk);
	
	if(strlen(p1.kamar.nama)!=0){
		printf("\n\n\t[Kamar]");
		printf("\n\tNama kamar  : %s", p1.kamar.nama);
		printf("\n\tKelas kamar : %s", p1.kamar.kelas);
	}
}
