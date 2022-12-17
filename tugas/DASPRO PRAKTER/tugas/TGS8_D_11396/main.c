#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define hargaA 5000
#define hargaB 7500
#define hargaC 10000
#define hargaX 25000
#define hargaY 30000

typedef char string[50];

void cekLogin(string user, string pass, int *login);
void pengurangan(int *hasil, int pengurang);
void menu(int jmlA, int jmlB, int jmlC, int jmlX, int jmlY);
void init(int *bA, int *bB, int *bC, int *bX, int *bY, int *cekpembeli, int *cekPembelian, int *cekD,
		  int *jA, int *jB, int *jC, int *jX, int *jY, int *tA, int *tB, int *tC, int *tX, int *tY);
void rincian(int tA, int tB, int tC, int tX, int tY, int bA, int bB, int bC, int bX, int bY, 
			 int hA, int hB, int hC, int hX, int hY, string nama, string tgl, string jam, int cekD, string nik, string peker, string al, int all);
void perkalian(int *hasil, int harga, int beli);
void total(int *all, int tA, int tB, int tC, int tX, int tY);
void keuntungan(int tA, int tB, int tC, int tX, int tY, int bA, int bB, int bC, int bX, int bY, int hA, int hB, int hC, int hX, int hY);
void hitungUntung(int *uA, int *uB, int *uC, int *uX, int *uY, int hA, int hB, int hC, int hX, int hY,int pA, int pB, int pC, int pX, int pY);

//int hargaA=5000, hargaB=7500, hargaC=10000, hargaX=25000, hargaY=30000;
int main(int argc, char *argv[]) {
	string user, pass;
	string nama, no_tlp, tglDatang, jamDatang;
	string tali;
	int cekPembeli, cekPembelian, cekData;
	int toleransi=3;
	int login=0;
	int pil;
	int jmlA=50, jmlB=50, jmlC=50, jmlX=100, jmlY=100;
	int beliA, beliB, beliC, beliX, beliY;
	int totA, totB, totC, totX, totY, allTotal;
	string nik, pekerjaan, alamat;
	string jawab;

	init(&beliA, &beliB, &beliC, &beliX, &beliY,&cekPembeli,&cekPembelian,&cekData,
		 &jmlA,&jmlB,&jmlC,&jmlX,&jmlY,&totA,&totB,&totC,&totX,&totY);
	do{
		system("cls");
		printf("\n\t\t--=== LOGIN ===--\n");
		printf("\n\tTolerasi: %d", toleransi);
		printf("\n\tUsername: "); fflush(stdin); gets(user);
		printf("\tpassword: "); fflush(stdin); gets(pass);
		cekLogin(user,pass,&login);
		if(login==1){
			do{
				system("cls");
				printf("\n\t\t--=== MENU ===--\n");
				menu(jmlA,jmlB,jmlC,jmlX,jmlY);
				printf("\n\t>>> "); scanf("%d", &pil);
				switch (pil){
				case 1:
					if(cekPembeli==0){
						printf("\n\t\t-- Input Pembeli --\n");
						printf("\n\tNama: "); fflush(stdin); gets(nama);
						while(strlen(nama)==0){
							printf("\n\t\t[!] Nama tidak boleh kosong");
							printf("\n\tNama: "); fflush(stdin); gets(nama);
						}
						printf("\n\tNo. Telp: "); fflush(stdin); gets(no_tlp);
						while(strlen(no_tlp)==0){
							printf("\n\t\t[!] Nomer telepon tidak boleh kosong");
							printf("\n\tNo. Telp: "); fflush(stdin); gets(no_tlp);
						}
						printf("\n\tTanggal Kedatangan: "); fflush(stdin); gets(tglDatang);
						while(strlen(tglDatang)!=10){
							printf("\n\t\t[!] Tanggal salah");
							printf("\n\tTanggal Kedatangan: "); fflush(stdin); gets(tglDatang);
						}
						printf("\n\tJam Kedatangan: "); fflush(stdin); gets(jamDatang);
						while(strlen(jamDatang)!=8){
							printf("\n\t\t[!] Jam salah");
							printf("\n\tJam Kedatangan: "); fflush(stdin); gets(jamDatang);
						}
						printf("\n\t\tBerhasil input data...");
						cekPembeli=1;

					}else{
						printf("\n\t\t[!] Data Pembeli sudah terinput!");
					}
				break;
				case 2:
					if(cekPembeli==1){
						printf("\n\t\t-- Input Pembelian --\n");
						printf("\n\tJenis tali yang ingin dibeli (A/B/C/X/Y) :"); fflush(stdin); gets(tali);
						
						if(strcmpi(tali,"a")==0){
							if(jmlA>0){
								printf("\n\tJumlah tali yang ingin dibeli (m): "); scanf("%d", &beliA);
								while(beliA<=0 || beliA>jmlA){
									if(beliA<=0){
										printf("\n\t[!] Jumlah yang dibeli tidak boleh kurang dari sama dengan 0");
									}else if(beliA>jmlA){
										printf("\n\t[!] Jumlah yang dibeli tidak boleh melebihi persediaan");
									}
									printf("\n\tJumlah tali yang ingin dibeli (m): "); scanf("%d", &beliA);
								}
								pengurangan(&jmlA,beliA);
								printf("\n\tBerhasil input pembelian");
							}else{
								printf("\n\t[!] Persediaan habis");
							}
						}else if(strcmpi(tali,"b")==0){
							if(jmlB>0){
								printf("\n\tJumlah tali yang ingin dibeli (m): "); scanf("%d", &beliB);
								while(beliB<=0 || beliB>jmlB){
									if(beliB<=0){
										printf("\n\t[!] Jumlah yang dibeli tidak boleh kurang dari sama dengan 0");
									}else if(beliB>jmlB){
										printf("\n\t[!] Jumlah yang dibeli tidak boleh melebihi persediaan");
									}
									printf("\n\tJumlah tali yang ingin dibeli (m): "); scanf("%d", &beliB);
								}
								pengurangan(&jmlB,beliB);
								printf("\n\tBerhasil input pembelian");
							}else{
								printf("\n\t[!] Persediaan habis");
							}
							
						}else if(strcmpi(tali,"c")==0){
							if(jmlC>0){
								printf("\n\tJumlah tali yang ingin dibeli (m): "); scanf("%d", &beliC);
								while(beliC<=0 || beliC>jmlC){
									if(beliC<=0){
										printf("\n\t[!] Jumlah yang dibeli tidak boleh kurang dari sama dengan 0");
									}else if(beliC>jmlC){
										printf("\n\t[!] Jumlah yang dibeli tidak boleh melebihi persediaan");
									}
									printf("\n\tJumlah tali yang ingin dibeli (m): "); scanf("%d", &beliC);
								}
								pengurangan(&jmlC,beliC);
								printf("\n\tBerhasil input pembelian");
							}else{
								printf("\n\t[!] Persediaan habis");
							}
						}else if(strcmpi(tali,"x")==0){
							if(jmlX>0){
								printf("\n\tJumlah tali yang ingin dibeli (m): "); scanf("%d", &beliX);
								while(beliX<=0 || beliX>jmlX){
									if(beliX<=0){
										printf("\n\t[!] Jumlah yang dibeli tidak boleh kurang dari sama dengan 0");
									}else if(beliX>jmlX){
										printf("\n\t[!] Jumlah yang dibeli tidak boleh melebihi persediaan");
									}
									printf("\n\tJumlah tali yang ingin dibeli (m): "); scanf("%d", &beliX);
								}
								pengurangan(&jmlX, beliX);
								if(cekData==0){
									printf("\n\tNIK: "); fflush(stdin); gets(nik);
									while(strlen(nik)!=16){
										printf("\n\t[!] NIK salah");
										printf("\n\tNIK: "); fflush(stdin); gets(nik);
									}
									printf("\n\tPekerjaan: "); fflush(stdin); gets(pekerjaan);
									while(strlen(pekerjaan)==0){
										printf("\n\t[!] Pekerjaan tidak boleh kosong");
										printf("\n\tPekerjaan: "); fflush(stdin); gets(pekerjaan);
									}
									printf("\n\tAlamat: "); fflush(stdin); gets(alamat);
									while(strlen(alamat)==0){
										printf("\n\t[!] Alamat tidak boleh kosong");
										printf("\n\tAlamat: "); fflush(stdin); gets(alamat);
									}
									cekData=1;
								}
								printf("\n\tBerhasil input pembelian");
							}else{
								printf("\n\t[!] Persediaan habis");
							}
							
						}else if(strcmpi(tali,"y")==0){
							if(jmlY>0){
								printf("\n\tJumlah tali yang ingin dibeli (m): "); scanf("%d", &beliY);
								while(beliY<=0 || beliY>jmlY){
									if(beliY<=0){
										printf("\n\t[!] Jumlah yang dibeli tidak boleh kurang dari sama dengan 0");
									}else if(beliY>jmlY){
										printf("\n\t[!] Jumlah yang dibeli tidak boleh melebihi persediaan");
									}
									printf("\n\tJumlah tali yang ingin dibeli (m): "); scanf("%d", &beliY);
								}
								pengurangan(&jmlY, beliY);
								if(cekData==0){
									printf("\n\tNIK: "); fflush(stdin); gets(nik);
									while(strlen(nik)!=16){
										printf("\n\t[!] NIK salah");
										printf("\n\tNIK: "); fflush(stdin); gets(nik);
									}
									printf("\n\tPekerjaan: "); fflush(stdin); gets(pekerjaan);
									while(strlen(pekerjaan)==0){
										printf("\n\t[!] Pekerjaan tidak boleh kosong");
										printf("\n\tPekerjaan: "); fflush(stdin); gets(pekerjaan);
									}
									printf("\n\tAlamat: "); fflush(stdin); gets(alamat);
									while(strlen(alamat)==0){
										printf("\n\t[!] Alamat tidak boleh kosong");
										printf("\n\tAlamat: "); fflush(stdin); gets(alamat);
									}
									cekData=1;
								}
								printf("\n\tBerhasil input pembelian");
							}else{
								printf("\n\t[!] Persediaan habis");
							}
							
						}else{
							printf("\n\t[!] Jenis tali tidak diketahui");
						}
						cekPembelian=1;
					}else{
						printf("\n\t[!] Belum input data pembeli");
					}
				break;

				case 3:
					if(cekPembeli==1 && cekPembelian==1){
						printf("\n\t\t-- Pembayaran --\n");
						rincian(totA,totB,totC,totX,totY,beliA,beliB,beliC,beliX,beliY,
								hargaA,hargaB,hargaC,hargaX,hargaY,nama,tglDatang,jamDatang, cekData,nik,pekerjaan,alamat,allTotal);
					}else if(cekPembelian==0 && cekPembeli==0){
						printf("\n\t[!] Input Data Pembeli dan Data Pembelian terlebih dahulu");
					}else if(cekPembelian==0){
						printf("\n\t[!] Input Data Pembelian terlebih dahulu");
					}

				break;

				case 4:
					printf("\n\t\t-- RESET DATA --\n");
					printf("\tApakah Anda yakin ingin mereset data? [ya/tidak]");
					printf("\n\tJawab : "); fflush(stdin); gets(jawab);
					if(strcmpi(jawab, "ya")==0){
						init(&beliA, &beliB, &beliC, &beliX, &beliY,&cekPembeli,&cekPembelian,&cekData,
						 &jmlA,&jmlB,&jmlC,&jmlX,&jmlY,&totA,&totB,&totC,&totX,&totY);
						printf("\n\t\t[~] Data berhasil direset...");
					}else if(strcmpi(jawab,"tidak")==0){
						printf("\n\t\t[~] Data tidak jadi direset...");
					}else{
						printf("\n\t\t[!] Inputan tidak sesuai");
					}
				break;

				case 5:
					if(cekPembeli==1 && cekPembelian==1){
						printf("\n\t\t-- Hitung Keuntungan --\n");
						keuntungan(totA, totB,totC,totX,totY,beliA,beliB,beliC,beliX,beliY,hargaA,hargaB,hargaC,hargaX,hargaY);	
					}else if(cekPembeli==0 && cekPembelian==0){
						printf("\n\t[!] Input Data Pembeli dan Data Pembelian terlebih dahulu");
					}else if(cekPembelian==0){
						printf("\n\t[!] Input Data Pembelian terlebih dahulu");
					}
					
				break;

				case 0:
					printf("\n\t[~] Kembali ke halaman login...");
				break;
				default:
					printf("\n\t[!] Menu tidak tersedia");
				break;
				}
				getch();
			}while(pil!=0);
		}else if(login==-1){
			printf("\n\t[!]Username atau password salah!");
			pengurangan(&toleransi,1);
			getch();
		}else if(login==0){
			break;
		}
	}while(toleransi>0);
	printf("\n\n\tBerhasil keluar...");
	printf("\n\tMade Riksi Purnama Sadnya Agung - 210711396 - D");
	getch();
	return 0;
}
void cekLogin(string user, string pass, int *login){
	if(strcmp(user,"Atma")==0 && strcmp(pass,"11396")==0){
		*login=1;
	}else if(strcmp(user,"0")==0 && strcmp(pass,"0")==0){
		*login=0;
	}else{
		*login=-1;
	}	
}
void pengurangan(int *hasil, int pengurang){
	*hasil=*hasil-pengurang;
}

void menu(int jmlA, int jmlB, int jmlC, int jmlX, int jmlY){
	printf("\n\tKetersediaan tali: ");
	printf("\n\t| %d Tali A | %d Tali B | %d Tali C | %d Tali X | %d Tali Y |\n", jmlA,jmlB,jmlC,jmlX,jmlY);
	printf("\n\t[1] Input Pembeli");
	printf("\n\t[2] Input Pembelian");
	printf("\n\t[3] Rincian");
	printf("\n\t[4] Reset Data");
	printf("\n\t[0] Logout");
	printf("\n\n\t[5] Hitung Keuntungan [TUGAS]");
}
void init(int *bA, int *bB, int *bC, int *bX, int *bY, int *cekpembeli, int *cekPembelian, int *cekD,
		  int *jA, int *jB, int *jC, int *jX, int *jY, int *tA, int *tB, int *tC, int *tX, int *tY){	  
	*bA=0;*bB=0;*bC=0;*bX=0;*bY=0;
	*tA=0;*tB=0;*tC=0;*tX=0;*tY=0;
	*jA=50;*jB=50;*jC=50;*jX=100;*jY=100;
	*cekpembeli=0;*cekPembelian=0;*cekD=0;
}

void perkalian(int *hasil, int harga, int beli){
	*hasil= harga*beli;
}

void total(int *all, int tA, int tB, int tC, int tX, int tY){
	*all=tA+tB+tC+tX+tY;
}
void rincian(int tA, int tB, int tC, int tX, int tY, int bA, int bB, int bC, int bX, int bY, 
			 int hA, int hB, int hC, int hX, int hY, string nama, string tgl, string jam, int cekD, string nik, string peker, string alamat, int all){

	
	printf("\n\tNama\t\t\t: %s", nama);
	printf("\n\tWaktu kedatangan\t: %s %s", tgl, jam);

	if(cekD==1){
		printf("\n\tNIK\t\t\t: %s",nik);
		printf("\n\tPekerjaan\t\t: %s", peker);
		printf("\n\tAlamat\t\t\t: %s",alamat);
	}

	perkalian(&tA,hA,bA);
	perkalian(&tB,hB,bB);
	perkalian(&tC,hC,bC);
	perkalian(&tX,hX,bX);
	perkalian(&tY,hY,bY);
	total(&all,tA,tB,tC,tX,tY);
	printf("\n\t\t-- Rincian --\n");
	printf("\n\tTali A	|%d|	 |@Rp %d | Total: Rp %d",bA,hA,tA);
	printf("\n\tTali B	|%d|	 |@Rp %d | Total: Rp %d",bB,hB,tB);
	printf("\n\tTali C	|%d|	 |@Rp %d| Total: Rp %d",bC,hargaC,tC);
	printf("\n\tTali X	|%d|	 |@Rp %d| Total: Rp %d",bX,hargaX,tX);
	printf("\n\tTali Y	|%d|	 |@Rp %d| Total: Rp %d",bY,hargaY,tY);
	printf("\n\n\t Total : Rp %d", all);
}

void hitungUntung(int *uA, int *uB, int *uC, int *uX, int *uY, int hA, int hB, int hC, int hX, int hY,int pA, int pB, int pC, int pX, int pY){
	*uA=hA-pA;
	*uB=hB-pB;
	*uC=hC-pC;
	*uX=hX-pX;
	*uY=hY-pY;
}

void keuntungan(int tA, int tB, int tC, int tX, int tY, int bA, int bB, int bC, int bX, int bY, int hA, int hB, int hC, int hX, int hY){
	int uA, uB, uC, uX, uY;
	int pA=3000,pB=5000,pC=7000, pX=19000, pY=23000;
	int kA=0,kB=0,kC=0,kX=0,kY=0;
	int totalK;
	
	hitungUntung(&uA, &uB, &uC, &uX, &uY, hA, hB, hC, hX, hY, pA, pB, pC, pX, pY);
	perkalian(&kA,uA,bA); perkalian(&kB,uB,bB); perkalian(&kC,uC,bC); perkalian(&kX,uX,bX); perkalian(&kY,uY,bY);
	
	printf("\n\n\tKeuntungan Tali A : %d", kA);
	printf("\n\tKeuntungan Tali B : %d", kB);
	printf("\n\tKeuntungan Tali C : %d", kC);
	printf("\n\tKeuntungan Tali X : %d", kX);
	printf("\n\tKeuntungan Tali Y : %d", kY);
	total(&totalK,kA,kB,kC,kX,kY);
	printf("\n\n\tTotal : Rp %d", totalK);
}

//maaf kk program sy rada ribet
//jiwa" mager sy kluar
