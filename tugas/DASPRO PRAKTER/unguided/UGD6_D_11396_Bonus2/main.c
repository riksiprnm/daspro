#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i,j,pil,n,cekInput=0;
	float harga, harga_diskon;
	do{
	system("cls");
	printf("\n---=== TOKO ALAT TULIS ===---");
	printf("\n[1] Menu Input");
	printf("\n[2] Menu Tampil Pembelian");
	printf("\n[3] Bonus");
	printf("\n[4] Tugas");
	printf("\n[0] Keluar");
	printf("\n>>> "); scanf("%d", &pil);

		switch (pil){
		case 1:
			do{
				printf("\nMasukkan banyak pesanan alat tulis (Paket): "); scanf("%d", &n);
				if(n<1){
					printf("\nPaket tidak boleh kurang dari 1 !!!");
				}else{
					printf("\nBerhasil input paket...");
					harga=n*12000;
					cekInput=1;
				}
			}while(n<1);
		break;
		
		case 2:
			if(cekInput==1){
				printf("\nBukti pembelian %d paket Alat Tulis\n", n);
				
				for(i=1;i<=5;i++){
					for(j=1;j<=n;j++){
						printf("|* ");
					}
					printf("\n");
				}
				printf("\nTotal harga: Rp %.2f", harga);
			}else{
				printf("\nSilakan input paket terlebih dahulu!!!");
			}
		break;

		case 3:
			if(cekInput==1){
					if(n>=6){
						printf("\nSelamat anda mendapatkan kupon diskon...\n");
						for(i=1;i<=6;i++){
							for(j=1;j<=n;j++){
								if(j==1 || i==1 || j==n || i==6){
									printf("*");
								}else{
									printf(" ");
								}
							}
							printf("\n");
						}
						printf("\nTotal harga pembelian %d Alat Tulis menjadi", n);
						harga_diskon=harga-harga*0.1;
						printf("\nRp %.2f", harga_diskon);
					}else{
						printf("\nAnda tidak bisa mendapatkan kupon diskon!!!");
					}

					
				}else{
					printf("\nSilakan input paket terlebih dahulu!!!");
				}

		break;

		case 4:
			if(cekInput==1){
				if(n>2 && n%2==1){
					for(i=1;i<=n;i++){
						for(j=1;j<=i;j++){
							if(j%2==0){
								printf("* ");
							}else{
								printf("%d ", i);
							}
						}
						printf("\n");
					}
					printf("\nSelamat anda mendapatkan bonus Penggaris Segitiga Unik");
				}else{
					printf("\nMohon maaf anda tidak bisa mendaptkan bonus Penggaris Segitiga Unik");
				}
			}else{
				printf("\nSilakan input paket terlebih dahulu!!!");
			}
		break;

		case 0:
			printf("\nBerhasil keluar - Made Riksi Purnama Sadnya Agung/D/210711396");
		break;

		default:
			printf("\nMenu tidak tersedia !!!");
		break;
		}
		getch();
	}while(pil!=0);

	return 0;
}
