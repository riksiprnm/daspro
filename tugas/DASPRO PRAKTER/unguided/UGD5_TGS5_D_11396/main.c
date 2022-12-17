
//Made Riksi Purnama Sadnya Agung / D / 210711396

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef char string[50];


int main(int argc, char *argv[]) {
	srand(time(NULL));
	int pil, cekLog=0, cekInput=0;
	string user, pass;
	string barang1="Patung Rajawali",barang2="Patung Garuda",barang3="Patung Naga";
	int jml1,jml2,jml3;
	int harga1, harga2, harga3;
	int uang, pilihBid,i, random;
	do{
		system("cls");
		printf("\n\t---=== TOKO KESENIAN TEBRI ===---\n");
		printf("\n1. Login");
		printf("\n2. Input stok");
		printf("\n3. Tampil barang");
		printf("\n4. Pelelangan");
		printf("\n5. Pelelangan Auto (Tugas)");
		printf("\n6. Exit");
		printf("\nPilih menu : "); scanf("%d", &pil);

		switch(pil){
			case 1:
				if(cekLog==0){
					system("cls");
					printf("\n\t---===LOGIN===---\n");
					do{
						printf("\nUsername: "); fflush(stdin); gets(user);
						if(strlen(user)==0){
							printf("\nUsername tidak boleh kosong !");
						}else if(strcmp(user,"tebri")!=0){
							printf("\nUsername salah !");
						}
					}while(strlen(user)==0 || strcmp(user,"tebri")!=0);

					do{
						printf("\nPassword: "); fflush(stdin); gets(pass);
						if(strlen(pass)==0){
							printf("\nPassword tidak boleh kosong !");
						}else if(strcmp(pass,"1396")!=0){
							printf("\nPassword salah !");
						}
					}while(strlen(pass)==0 || strcmp(pass,"1396")!=0);
					cekLog=1;
					printf("\nLogin berhasil...\n");

				}else{
					printf("\nAnda sudah login !\n");
				}
			break;

			case 2:
				if(cekLog==1){
					system("cls");
					printf("\n\t---===INPUT STOK===---\n");
					do{
						printf("\nMasukkan jumlah stok %s", barang1);
						printf("\nJumlah stok: "); scanf("%d", &jml1);
						if(jml1<=0){
							printf("\nStok barang tidak boleh kurang dari sama dengan 0");
						}
					}while(jml1<=0);

					do{
						printf("\nMasukkan jumlah stok %s", barang2);
						printf("\nJumlah stok: "); scanf("%d", &jml2);
						if(jml2<=0){
							printf("\nStok barang tidak boleh kurang dari sama dengan 0");
						}
					}while(jml2<=0);

					do{
						printf("\nMasukkan jumlah stok %s", barang3);
						printf("\nJumlah stok: "); scanf("%d", &jml3);
						if(jml3<=0){
							printf("\nStok barang tidak boleh kurang dari sama dengan 0");
						}
					}while(jml3<=0);
					cekInput=1;
					printf("\nBerhasil menginputkan stok barang...\n");

				}else{
					printf("\n[!] LOGIN TERLEBIH DAHULU [!]\n");
				}
				
			break;

			case 3:
				if(cekLog==1 && cekInput==1){
					system("cls");
					printf("\n---===TAMPIL DATA BARANG===---\n");
					printf("\nBarang %s", barang1);
					printf("\nJumlah stok: %d", jml1);

					printf("\n\nBarang %s", barang2);
					printf("\nJumlah stok: %d", jml2);

					printf("\n\nBarang %s", barang3);
					printf("\nJumlah stok: %d", jml3);

					printf("\n");

				}else if(cekLog==0){
					printf("\n[!] LOGIN TERLEBIH DAHULU [!]\n");
				}else if(cekInput==0){
					printf("\n[!] INPUT STOK BARANG TERLEBIH DAHULU [!]\n");
				}
			break;

			case 4:
				if(cekLog==1 && cekInput== 1){
					harga1=0;
					harga2=0;
					harga3=0;
					for(i=0;i<5;i++){
						system("cls");
						printf("\n\t---===PELELANGAN===---\n");
						printf("\n%s \t: %d", &barang1, harga1);
						printf("\n%s \t\t: %d", &barang2, harga2);
						printf("\n%s \t\t: %d", &barang3, harga3);
							do{
								printf("\nPilih barang yang ingin anda bid (1-3): "); scanf("%d", &pilihBid);
								if(pilihBid<1 || pilihBid>3){
									printf("\n Barang yang dipilih tidak tersedia !");
								}
							}while(pilihBid<1 || pilihBid>3);

							if(pilihBid==1){
								do{
									printf("\n Jumlah uang yang anda pasang : "); scanf("%d", &uang);
									if(uang<=0){
										printf("\n Jumlah uang tidak boleh kurang dari sama dengan 0 !");
									}
								}while(uang<=0);
								harga1 += uang;
							}else if(pilihBid==2){
								do{
									printf("\n Jumlah uang yang anda pasang : "); scanf("%d", &uang);
									if(uang<=0){
										printf("\n Jumlah uang tidak boleh kurang dari sama dengan 0 !");
									}
								}while(uang<=0);
								harga2 += uang;
							}else if(pilihBid==3){
								do{
									printf("\n Jumlah uang yang anda pasang : "); scanf("%d", &uang);
									if(uang<=0){
										printf("\n Jumlah uang tidak boleh kurang dari sama dengan 0 !");
									}
								}while(uang<=0);
								harga3 += uang;
							}
					}
					system("cls");
						printf("\n\t---===PELELANGAN===---\n");
						printf("\n%s \t: %d", &barang1, harga1);
						printf("\n%s \t\t: %d", &barang2, harga2);
						printf("\n%s \t\t: %d", &barang3, harga3);
						printf("\n");
					if(harga1 == harga2 || harga1 == harga3 || harga2 == harga3){
						printf("\nTidak ada barang yang memenangkan lelang !");
					}else if(harga1>harga2 &&harga1>harga3){
						printf("\n\tSelamat barang %s memenangkan lelang !", barang1);
					}else if(harga2>harga3){
						printf("\n\tSelamat barang %s memenangkan lelang !",barang2);
					}else{
						printf("\n\tSelamat barang %s memenangkan lelang !", barang3);
					}
					printf("\n");
				}else if(cekLog==0){
					printf("\n[!] LOGIN TERLEBIH DAHULU [!]\n");
				}else if(cekInput==0){
					printf("\n[!] INPUT STOK BARANG TERLEBIH DAHULU [!]\n");
				}
			break;
			
			case 5:
			if(cekLog==1 && cekInput== 1){
					harga1=0;
					harga2=0;
					harga3=0;
					for(i=0;i<5;i++){
						system("cls");
						printf("\n\t---===PELELANGAN===---\n");
						printf("\n%s \t: %d", barang1, harga1);
						printf("\n%s \t\t: %d", barang2, harga2);
						printf("\n%s \t\t: %d", barang3, harga3);
							do{
								printf("\nPilih barang yang ingin anda bid (1-3): "); scanf("%d", &pilihBid);
								if(pilihBid<1 || pilihBid>3){
									printf("\n Barang yang dipilih tidak tersedia !");
								}
							}while(pilihBid<1 || pilihBid>3);

							if(pilihBid==1){
								do{
									printf("\n Jumlah uang yang anda pasang : "); scanf("%d", &uang);
									if(uang<=0){
										printf("\n Jumlah uang tidak boleh kurang dari sama dengan 0 !");
									}
								}while(uang<=0);
								harga1 += uang;
								random = (rand() %(100+1));
								harga2 += random;
								random = (rand() %(100+1));
								harga3 += random;
							}else if(pilihBid==2){
								do{
									printf("\n Jumlah uang yang anda pasang : "); scanf("%d", &uang);
									if(uang<=0){
										printf("\n Jumlah uang tidak boleh kurang dari sama dengan 0 !");
									}
								}while(uang<=0);
								harga2 += uang;
								random = (rand() %(100+1));
								harga1 += random;
								random = (rand() %(100+1));
								harga3 += random;
							}else if(pilihBid==3){
								do{
									printf("\n Jumlah uang yang anda pasang : "); scanf("%d", &uang);
									if(uang<=0){
										printf("\n Jumlah uang tidak boleh kurang dari sama dengan 0 !");
									}
								}while(uang<=0);
								harga3 += uang;
								random = (rand() %(100+1));
								harga1 += random;
								random = (rand() %(100+1));
								harga2 += random;
							}
					}
					system("cls");
						printf("\n\t---===PELELANGAN===---\n");
						printf("\n%s \t: %d", barang1, harga1);
						printf("\n%s \t\t: %d", barang2, harga2);
						printf("\n%s \t\t: %d", barang3, harga3);
						printf("\n");
					if(harga1 == harga2 || harga1 == harga3 || harga2 == harga3){
						printf("\nTidak ada barang yang memenangkan lelang !");
					}else if(harga1>harga2 &&harga1>harga3){
						printf("\n\tSelamat barang %s memenangkan lelang !\n", barang1);
					}else if(harga2>harga3){
						printf("\n\tSelamat barang %s memenangkan lelang !\n",barang2);
					}else{
						printf("\n\tSelamat barang %s memenangkan lelang !\n", barang3);
					}
					printf("\n");
				}else if(cekLog==0){
					printf("\n[!] LOGIN TERLEBIH DAHULU [!]\n");
				}else if(cekInput==0){
					printf("\n[!] INPUT STOK BARANG TERLEBIH DAHULU [!]\n");
				}

			break;

			case 6:
				printf("\n Made Riksi Purnama Sadnya Agung / D / 210711396");
				printf("\n Mengambil bonus 1, 2, 3\n");
			break;

			default:
				printf("\n Menu tidak tersedia !\n");
			break;
		}system("pause");

	}while(pil!=6);
	
	return 0;
}
