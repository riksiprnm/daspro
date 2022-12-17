#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#define Hydrocodone 70000
#define Lisinopril 30000
#define Antibiotik 60000
#define Epogen 150000

typedef char string[50];

void menu();
void initData(string nama, int *no_meja, int *jmlHydro, int *jmlLisinopril, int *jmlAntibiotik, int *jmlEpogen, bool *sudahPesan, 
			  double *totalHarga, float *totalBayar, int *uangPelanggan, float *uangkembalian, bool *member, float *diskonMember);
void loginUser(string user, string pass, bool *cekLog);
void tampilBeli(int jmlHydro, int jmlLisinopril, int jmlAntibiotik, int jmlEpogen);
void tampilPembayaran(string nama, int no_meja, int jmlHydro, int jmlLisinopril, int jmlAntibiotik, int jmlEpogen, float totalBayar, float totalHarga, float temp, bool member, float diskonMember);
void tampilEditMenu(int jmlHydro, int jmlLisinopril, int jmlAntibiotik, int jmlEpogen);

double hitungTotalHarga(int jmlHydro, int jmlLisinopril, int jmlAntibiotik, int jmlEpogen);
double hitungPajak(double totalHarga);
double diskon(float totalBayar);
int cekLogin(string user, string pass);
double hitungKembalian(float uangPelanggan, float totalBayar);
double hitungDiskonMember(float totalBayar);
int tambah(int hasil, int penambah);
int kurang(int hasil, int pengurang);
int main(int argc, char *argv[]) {
	string user, pass, nama,jawab;
	bool cekLog=false, sudahPesan=false, member=false;
	char pil, pesan, pil2, pil3;
	int no_meja, jmlHydrocodone, jmlLisinopril, jmlAntibiotik, jmlEpogen, jumlah;
	double totalHarga;
	float totalBayar, temp;
	int uangPelanggan;
	float uangkembalian;
	float diskonMember;
	initData(nama,&no_meja,&jmlHydrocodone,&jmlLisinopril,&jmlAntibiotik,&jmlEpogen,&sudahPesan, 
			 &totalHarga, &totalBayar, &uangPelanggan, &uangkembalian, &member, &diskonMember);
	do{
		system("cls");
		menu();
		printf("\n\t>>> "); pil=getch();
		switch (pil){
		case '1':
			if(!cekLog){
				printf("\n\t\t --=== Login ===--\n");
				do{
					printf("\n\tUsername : "); fflush(stdin); gets(user);
					printf("\tPassword : "); fflush(stdin); gets(pass);
					loginUser(user,pass,&cekLog);
				}while(cekLogin(user,pass)==0);
			}else{
				printf("\n\t\t[!] Kamu sudah login");
			}
		break;
		case '2':
			if(cekLog && !sudahPesan){
				printf("\n\t\t--=== Input Pesanan ===---\n");
				do{
					printf("\n\tNama pemesan : "); fflush(stdin); gets(nama);
					if(strlen(nama)==0){
						printf("\n\t\t[!] Nama tidak boleh kosong\n");
					}
				}while(strlen(nama)==0);
				do{
					printf("\n\tMasukkan nomer meja : "); scanf("%d", &no_meja);
					if(no_meja%2==0 || (no_meja<1 || no_meja>30)){
						printf("\n\t\t[!] Nomer meja harus ganjil dan diantara 1-30)\n");
					}
				}while(no_meja%2==0 || (no_meja<1 || no_meja>30));
				
					printf("\n\t[Bonus] Apakah pelanggan merupakan member ??? [Y/N] : "); fflush(stdin); gets(jawab);
					if(strcmpi(jawab,"y")==0){
						member=true;
					}else{
						member=false;
					}
				
				do{
					do{
						system("cls");
						tampilBeli(jmlHydrocodone,jmlLisinopril,jmlAntibiotik,jmlEpogen);
						printf("\n\t>>> "); pesan=getch();
						switch (pesan){
						case '1':
							do{
								printf("\n\tJumlah Hydrocodone yang dibeli : "); scanf("%d", &jmlHydrocodone);
								if(jmlHydrocodone<1){
									printf("\n\t\tJumlah yang dibeli tidak boleh kurang dari 1\n");
								}
							}while(jmlHydrocodone<1);
							printf("\n\t\t[~] Berhasil memasukkan ke keranjang");
						break;
						case '2':
							do{
								printf("\n\tJumlah Chocolate Lisinopril yang dibeli : "); scanf("%d", &jmlLisinopril);
								if(jmlLisinopril<1){
									printf("\n\t\tJumlah yang dibeli tidak boleh kurang dari 1\n");
								}
							}while(jmlLisinopril<1);
							printf("\n\t\t[~] Berhasil memasukkan ke keranjang");
						break;
						case '3':
							do{
								printf("\n\tJumlah Antibiotik yang dibeli : "); scanf("%d", &jmlAntibiotik);
								if(jmlAntibiotik<1){
									printf("\n\t\tJumlah yang dibeli tidak boleh kurang dari 1\n");
								}
							}while(jmlAntibiotik<1);
							printf("\n\t\t[~] Berhasil memasukkan ke keranjang");
						break;
						case '4':
							do{
								printf("\n\tJumlah Epogen yang dibeli : "); scanf("%d", &jmlEpogen);
								if(jmlEpogen<1){
									printf("\n\t\tJumlah yang dibeli tidak boleh kurang dari 1\n");
								}
							}while(jmlEpogen<1);
							printf("\n\t\t[~] Berhasil memasukkan ke keranjang");
						break;
						case 27:
							if(jmlLisinopril!=0 || jmlEpogen!=0 || jmlHydrocodone!=0 || jmlAntibiotik!=0){
								printf("\n\t\t[~] Berhasil memesan . . .");
								sudahPesan=true;
							}else{
								printf("\n\t\t[!] Belum memesan apapun");
							}
							
						break;
						default:
							printf("\n\n\t[!] Pilihan menu tidak ada");
						break;
						}getch();
					}while(jmlLisinopril==0 && jmlEpogen==0 && jmlHydrocodone==0 && jmlAntibiotik==0);
					
				}while(pesan!=27);
				printf("\n\t\tKembali ke menu utama . . .");
			}else if(!cekLog){
				printf("\n\t\t[!] Silakan login terlebih dahulu");
			}else if(sudahPesan){
				printf("\n\t\t[!] Makanan sudah dipesan, masuk ke menu pembayaran");
			}
		break;
		case '3':
			if(sudahPesan && cekLog){
				totalHarga=hitungTotalHarga(jmlHydrocodone,jmlLisinopril,jmlAntibiotik,jmlEpogen);
				totalBayar=totalHarga+hitungPajak(totalHarga);
				temp=totalBayar;
				if(jmlAntibiotik>=5 && jmlEpogen>=2){
					totalBayar=totalBayar-diskon(totalBayar);
				}
				if(member){
					totalBayar=totalBayar-hitungDiskonMember(totalBayar);
				}
				tampilPembayaran(nama,no_meja,jmlHydrocodone,jmlLisinopril,jmlAntibiotik,jmlEpogen,totalBayar, totalHarga,temp, member, diskonMember);
				printf("\n\tLanjutkan Pembayaran? [Y/N] : "); fflush(stdin); gets(jawab);
				if(strcmpi(jawab,"y")==0){
					do{
						printf("\n\tMasukkan uang pembayaran : "); scanf("%d", &uangPelanggan);
						if(uangPelanggan<totalBayar){
							printf("\n\t\t[!] Uang yang dimasukkan kurang\n");
						}
					}while(uangPelanggan<totalBayar);
					uangkembalian=hitungKembalian(uangPelanggan,totalBayar);
					if(uangkembalian>0){
						printf("\n\n\tUang kembalian: %.2f", uangkembalian);
					}
					printf("\n\t\t[~] Pembayaran berhasil");
					initData(nama,&no_meja,&jmlHydrocodone,&jmlLisinopril,&jmlAntibiotik,&jmlEpogen,&sudahPesan, 
							 &totalHarga, &totalBayar, &uangPelanggan, &uangkembalian, &member, &diskonMember);
				}else{
					printf("\n\t\t[!] Pembayaran tidak jadi dilakukan");
				}

			}else if(!cekLog){
				printf("\n\t\t[!] Silakan login terlebih dahulu");
			}else if(!sudahPesan){
				printf("\n\t\t[!] Pesan makanan terlebih dahulu");
			}
		break;
		case '4':
			if(sudahPesan && cekLog){
				printf("\n\tAnda yakin ingin menghapus data ? [Y/N] "); fflush(stdin); gets(jawab);
				if(strcmpi(jawab,"y")==0){
					initData(nama,&no_meja,&jmlHydrocodone,&jmlLisinopril,&jmlAntibiotik,&jmlEpogen,&sudahPesan, &totalHarga, &totalBayar, &uangPelanggan, &uangkembalian, &member, &diskonMember);
					printf("\n\t\t[~] Berhasil membatalkan pesanan . . .");
				}else{
					printf("\n\t\t[~] Data batal dihapus");
				}
				
			}else if(!cekLog){
				printf("\n\t\t[!] Silakan login terlebih dahulu");
			}else if(!sudahPesan){
				printf("\n\t\t[!] Pesan makanan terlebih dahulu");
			}
			
		break;
		case '5':
			if(sudahPesan && cekLog){
				do{
					system("cls");
					tampilEditMenu(jmlHydrocodone,jmlLisinopril,jmlAntibiotik,jmlEpogen);
					printf("\n\t>>> "); pil2=getch();
					switch (pil2){
						case '1':
							printf("\n\n\t[1] Tambah Pesanan");
							printf("\n\t[2] Kurangi Pesanan");
							printf("\n\t>>> "); pil3=getch();
							switch (pil3){
							case '1':
								do{
									printf("\n\tMasukkan jumlah ditambah : "); scanf("%d", &jumlah);
									if(jumlah<1){
										printf("\n\t\t[!] Inputan tidak boleh kurang dari 1");
									}
								}while(jumlah<1);
								
								jmlHydrocodone=tambah(jmlHydrocodone,jumlah);
							break;
							case '2':
								if(jmlHydrocodone>0){
									do{
										printf("\n\tMasukkan jumlah dikurang : "); scanf("%d", &jumlah);
										if(jumlah<1){
											printf("\n\t\t[!] Inputan tidak boleh kurang dari 1");
										}
									}while(jumlah<1);
									if(jmlHydrocodone<jumlah){
										printf("\n\t\t[!] Jumlah kurang lebih besar dari jumlah beli");
										getch();
									}else{
										jmlHydrocodone=kurang(jmlHydrocodone,jumlah);
									}
								}else{
									printf("\n\t\t[!] Anda belum memesan menu ini");
									getch();
								}
							break;
							default:
								printf("\n\n\t[!] Pilihan menu tidak ada");
							break;
							}
						break;
						
						case '2':
							printf("\n\n\t[1] Tambah Pesanan");
							printf("\n\t[2] Kurangi Pesanan");
							printf("\n\t>>> "); pil3=getch();
							switch (pil3){
							case '1':
								do{
									printf("\n\tMasukkan jumlah ditambah : "); scanf("%d", &jumlah);
									if(jumlah<1){
										printf("\n\t\t[!] Inputan tidak boleh kurang dari 1");
									}
								}while(jumlah<1);
								
								jmlLisinopril=tambah(jmlLisinopril,jumlah);
							break;
							case '2':
								if(jmlLisinopril>0){
									do{
										printf("\n\tMasukkan jumlah dikurang : "); scanf("%d", &jumlah);
										if(jumlah<1){
											printf("\n\t\t[!] Inputan tidak boleh kurang dari 1");
										}
									}while(jumlah<1);
									if(jmlLisinopril<jumlah){
										printf("\n\t\t[!] Jumlah kurang lebih besar dari jumlah beli");
										getch();
									}else{
										jmlLisinopril=kurang(jmlLisinopril,jumlah);
									}
								}else{
									printf("\n\t\t[!] Anda belum memesan menu ini");
									getch();
								}
							break;
							default:
								printf("\n\n\t[!] Pilihan menu tidak ada");
							break;
							}
						break;

						case '3':
							printf("\n\n\t[1] Tambah Pesanan");
							printf("\n\t[2] Kurangi Pesanan");
							printf("\n\t>>> "); pil3=getch();
							switch (pil3){
							case '1':
								do{
									printf("\n\tMasukkan jumlah ditambah : "); scanf("%d", &jumlah);
									if(jumlah<1){
										printf("\n\t\t[!] Inputan tidak boleh kurang dari 1");
									}
								}while(jumlah<1);
								
								jmlAntibiotik=tambah(jmlAntibiotik,jumlah);
							break;
							case '2':
								if(jmlAntibiotik>0){
									do{
										printf("\n\tMasukkan jumlah dikurang : "); scanf("%d", &jumlah);
									if(jumlah<1){
										printf("\n\t\t[!] Inputan tidak boleh kurang dari 1");
									}
									}while(jumlah<1);
									if(jmlAntibiotik<jumlah){
										printf("\n\t\t[!] Jumlah kurang lebih besar dari jumlah beli");
										getch();
									}else{
										jmlAntibiotik=kurang(jmlAntibiotik,jumlah);
									}
								}else{
									printf("\n\t\t[!] Anda belum memesan menu ini");
									getch();
								}
							break;
							default:
								printf("\n\n\t[!] Pilihan menu tidak ada");
							break;
							}
						break;

						case '4':
							printf("\n\n\t[1] Tambah Pesanan");
							printf("\n\t[2] Kurangi Pesanan");
							printf("\n\t>>> "); pil3=getch();
							switch (pil3){
							case '1':
								do{
									printf("\n\tMasukkan jumlah ditambah : "); scanf("%d", &jumlah);
									if(jumlah<1){
										printf("\n\t\t[!] Inputan tidak boleh kurang dari 1");
									}
									}while(jumlah<1);
								jmlEpogen=tambah(jmlEpogen,jumlah);
							break;
							case '2':
								if(jmlEpogen>0){
									do{
										printf("\n\tMasukkan jumlah dikurang : "); scanf("%d", &jumlah);
									if(jumlah<1){
										printf("\n\t\t[!] Inputan tidak boleh kurang dari 1");
									}
									}while(jumlah<1);
									
									
									if(jmlEpogen<jumlah){
										printf("\n\t\t[!] Jumlah kurang lebih besar dari jumlah beli");
										getch();
									}else{
										jmlEpogen=kurang(jmlEpogen,jumlah);
									}
								}else{
									printf("\n\t\t[!] Anda belum memesan menu ini");
									getch();
								}
							break;
							default:
								printf("\n\n\t[!] Pilihan menu tidak ada");
							break;
							}
						break;

						case 27:
							printf("\n\t\t[~] Kembali ke menu utama . . .");
						break;
						
						default:
							printf("\n\n\t[!] Pilihan menu tidak ada");
						break;
					}
					
				}while(pil2!=27);
			}else if(!cekLog){
				printf("\n\t\t[!] Silakan login terlebih dahulu");
			}else if(!sudahPesan){
				printf("\n\t\t[!] Pesan makanan terlebih dahulu");
			}

		break;
		case 27:
			printf("\n\t\t[~] Terima kasih . . .");
		break;
		default:
			printf("\n\n\t[!] Pilihan menu tidak ada");
		break;
		}
		getch();
	}while(pil!=27);



	return 0;
}

void menu(){
	printf("\n\t\t--=== Apotek 24 OK ===---\n");
	printf("\n\t[1] Login");
	printf("\n\t[2] Input Data Pesanan");
	printf("\n\t[3] Pembayaran");
	printf("\n\t[4] Batalkan Pesanan");
	printf("\n\t[5] Edit Pesanan");
	printf("\n\t[ESC] Keluar");
}

void initData(string nama, int *no_meja, int *jmlHydro, int *jmlLisinopril, int *jmlAntibiotik, int *jmlEpogen, bool *sudahPesan, 
			  double *totalHarga, float *totalBayar, int *uangPelanggan, float *uangkembalian, bool *member, float *diskonMember){

	strcpy(nama,"");
	*no_meja=0;
	*jmlHydro=0;
	*jmlLisinopril=0;
	*jmlAntibiotik=0;
	*jmlEpogen=0;
	*sudahPesan=false;
	*totalHarga=0;
	*totalBayar=0;
	*uangkembalian=0;
	*uangPelanggan=0;
	*member=false;
	*diskonMember=0;
}
void loginUser(string user, string pass, bool *cekLog){
	if(cekLogin(user,pass)==1){
		printf("\n\t\t[~] Login berhasil . . .\n");
		*cekLog=true;
	}else if(cekLogin(user, pass)==0){
		printf("\n\t\t[!] Username atau Password salah\n");
	}
}
int cekLogin(string user, string pass){
	if(strcmp(user,"Apotek24OK")==0 && strcmp(pass,"11396")==0){
		return 1;
	}else{
		return 0;
	}
}

void tampilBeli(int jmlHydro, int jmlLisinopril, int jmlAntibiotik, int jmlEpogen){

	printf("\n\n\t\t--=== Pemesanan Makanan ===--\n");
	
	if(jmlLisinopril!=0 || jmlEpogen!=0 || jmlHydro!=0 || jmlAntibiotik!=0){
		printf("\n\n\tKeranjang pesanan: ");
		printf("\n\tJumlah Hydrocodone\t\t: %d",jmlHydro);
		printf("\n\tJumlah Lisinopril\t\t: %d",jmlLisinopril);
		printf("\n\tJumlah Antibiotik Amoxcillin\t: %d",jmlAntibiotik);
		printf("\n\tJumlah Epogen\t\t\t: %d",jmlEpogen);
		printf("\n\n\t--========================--\n");
	}
	
	printf("\n\tJenis makanan: ");
	printf("\n\t[1] Hydrocodone\t\t\t: %d", Hydrocodone);
	printf("\n\t[2] Lisinopril\t\t\t: %d", Lisinopril);
	printf("\n\t[3] Antibiotik Amoxcillin\t: %d", Antibiotik);
	printf("\n\t[4] Epogen\t\t\t: %d", Epogen);
	printf("\n\t[ESC] Back");

}
double hitungTotalHarga(int jmlHydro, int jmlLisinopril, int jmlAntibiotik, int jmlEpogen){
	return (jmlHydro*Hydrocodone)+(jmlLisinopril*Lisinopril)+(jmlAntibiotik*Antibiotik)+(jmlEpogen*Epogen);
}
double hitungPajak(double totalHarga){
	return totalHarga*0.12;
}
double diskon(float totalBayar){
	return totalBayar*0.0022;
}

void tampilPembayaran(string nama, int no_meja, int jmlHydro, int jmlLisinopril, int jmlAntibiotik, int jmlEpogen, float totalBayar, float totarHarga, float temp, bool member, float diskonMember){
	int temp2;
	printf("\n\t\t--=== Menu Pembayaran ===--\n");
	printf("\n\tNama pemesan \t\t\t: %s",nama);
	printf("\n\tNomer meja \t\t\t: %d", no_meja);
	printf("\n\n\tJumlah Hydrocodone \t\t: %d", jmlHydro);
	printf("\n\tJumlah Lisinopril \t\t: %d", jmlLisinopril);
	printf("\n\tJumlah Antibiotik Amoxcillin \t: %d", jmlAntibiotik);
	printf("\n\tJumlah Epogen \t\t\t: %d", jmlEpogen);
	printf("\n\t-----------------------------------------");
	printf("\n\tTotal Harga \t\t: %.2f", totarHarga);
	printf("\n\tPajak \t\t\t: %.2f", hitungPajak(totarHarga));
	printf("\n\tTotal Bayar \t\t: %.2f", temp);
	if(jmlAntibiotik>=5 && jmlEpogen>=2){
		printf("\n\tDiskon \t\t\t: %.2f", diskon(temp));
	}
	temp2=temp-diskon(temp);
	if(member){
		printf("\n\t[BONUS] Diskon Member\t: %.2f", hitungDiskonMember(temp2));
	}
	printf("\n\t-----------------------------------------");
	printf("\n\tTotal Pembayaran : %.2f\n\n", totalBayar);	
}

double hitungKembalian(float uangPelanggan, float totalBayar){
	return uangPelanggan-totalBayar;
}
double hitungDiskonMember(float totalBayar){
	return totalBayar*0.055;
}
void tampilEditMenu(int jmlHydro, int jmlLisinopril, int jmlAntibiotik, int jmlEpogen){
	printf("\n\t\t--=== Edit Pesanan ===---\n");
		printf("\n\n\tKeranjang pesanan: ");
		printf("\n\t[1]Jumlah Hydrocodone\t\t: %d",jmlHydro);
		printf("\n\t[2]Jumlah Lisinopril\t\t: %d",jmlLisinopril);
		printf("\n\t[3]Jumlah Antibiotik Amoxcillin\t: %d",jmlAntibiotik);
		printf("\n\t[4]Jumlah Epogen\t\t: %d",jmlEpogen);
		printf("\n\t[ESC] Kembali");
		printf("\n\n\t--========================--\n");
}

int tambah(int hasil, int penambah){
	return hasil+penambah;
}
int kurang(int hasil, int pengurang){
	return hasil-pengurang;
}