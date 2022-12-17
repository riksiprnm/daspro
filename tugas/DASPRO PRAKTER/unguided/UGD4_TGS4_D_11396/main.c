#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//bonus 1,2,3,4
typedef char string[50];

int main(int argc, char *argv[]) {
	int pil,log=0, input=0;
	string user, pass;
	int umur, lama;
	string nama, kode,jwb,no_tlp;
	float total, harga,uang, kembalian, diskon=0;
	do{
		system("cls");
		printf("\n---=== Kos Putra Sejahtera ===---");
		if(input==1){
			printf("\n Calon penyewa (bonus): %s", nama);
		}else{
			printf("\n Calon penyewa (bonus): -");
		}
		printf("\n 1. Login");
		printf("\n 2. Display");
		printf("\n 3. Reservasi");
		printf("\n 4. Pembayaran");
		printf("\n 0. Exit");
		printf("\n Pilih menu: "); scanf("%d", &pil);
		
		switch(pil){
			case 1:
				if(log==0){
					printf("\nUsername: "); fflush(stdin); gets(user);
					printf("Password: "); fflush(stdin); gets(pass);
					if(strcmp(user,"riksi")==0 && strcmp(pass,"11396")==0 || strcmp(user,"admin")==0 && strcmp(pass,"admin")==0){
						log=1;
						printf("\n Berhasil login");
					}else{
						printf("\n Username dan password salah !");
					}
					
				}else{
					printf("\n Anda sudah login");
				}
				break;
			case 2:
				if(log==1){
					printf("\n\t---=== KAMAR KOS ===---\n");
					
					printf("\n [1] Kamar Luxury");
					printf("\n\tHarga sewa/bulan : 1200000");
					printf("\n\tKode kamar       : KL");
					printf("\n\tFasilitas        : Ya");
					printf("\n");
					
					printf("\n [2] Kamar Business");
					printf("\n\tHarga sewa/bulan : 1000000");
					printf("\n\tKode kamar       : BS");
					printf("\n\tFasilitas        : Ya");
					printf("\n");
					
					printf("\n [3] Kamar Eksklusif");
					printf("\n\tHarga sewa/bulan : 850000");
					printf("\n\tKode kamar       : EL");
					printf("\n\tFasilitas        : Ya");
					printf("\n");
					
					printf("\n [4] Kamar Reguler");
					printf("\n\tHarga sewa/bulan : 500000");
					printf("\n\tKode kamar       : RL");
					printf("\n\tFasilitas        : Tidak");
					printf("\n");
					
					printf("\n [5] Kamar Ekonomi");
					printf("\n\tHarga sewa/bulan : 350000");
					printf("\n\tKode kamar       : EM");
					printf("\n\tFasilitas        : Tidak");
					printf("\n");
				}else{
					printf("\n Anda belum login");
				}
				break;
			case 3:
				if(log==1 && input==0){
					nama:
					printf("\n Nama: "); fflush(stdin); gets(nama);
					if(strlen(nama)==0){
						printf("\n Nama tidak boleh kosong");
						goto nama;
					}
					umur:
					printf("\n Umur: "); scanf("%d", &umur);
					if(umur<=0){
						printf("\n Umur tidak boleh kurang dan sama dengan nol");
						goto umur;
					}
					no:
					printf("\n No. Telepon: "); fflush(stdin); gets(no_tlp);
					if(strlen(no_tlp)==0){
						printf("\n No. telp tidak boleh kosong");
						goto no;
					}
					lama:
					printf("\n Lama sewa: "); scanf("%d", &lama);
					if(lama<=0){
						printf("\n Lama tidak boleh kurang dan sama dengan nol");
						goto lama;
					}
					kamar:
					printf("\n Kode kamar: "); fflush(stdin); gets(kode);
					if(strlen(kode)==0){
						printf("\n Kode kamar tidak boleh kosong");
						goto kamar;
					}
					
					printf("\n\n Yakin dengan pesanan ini? [ya/tidak] (bonus): ");
					printf("\n Jawab: "); fflush(stdin); gets(jwb);
					
					if(strcmpi(jwb,"ya")==0){
						input=1;
						printf("\n\n Reservasi berhasil...");
					}else if(strcmpi(jwb, "tidak")==0){
						printf("\n Silakan lakukan reservasi kembali !");
					}
				}else if(log==0){
					printf("\n Anda belum login");
				}else if(input==1){
					printf("\n Anda sudah input");
				}
				break;
			case 4:
				if(log==1 && input==1){
					printf("\n----=== BUKTI RESERVASI ===---");
					if(strcmpi(kode, "KL")==0){
						harga=1200000;
						printf("\n Kamar            : Luxury");
						printf("\n Umur             : %d", umur);
						printf("\n No. Telp         : %s", no_tlp);
						printf("\n Harga sewa/bulan : %.2f",harga);
						printf("\n Lama sewa        : %d", lama);
						
						if(lama>5){
							diskon=harga*6/100;
							printf("\n Status reservasi(bonus) : Mendapatkan diskon");
						}else{
							printf("\n Status reservasi(bonus) : Tidak mendapatkan diskon");
						}
					}else if(strcmpi(kode, "BS")==0){
						harga=1000000;
						printf("\n Kamar            : Business");
						printf("\n Umur             : %d", umur);
						printf("\n No. Telp         : %s", no_tlp);
						printf("\n Harga sewa/bulan : %.2f",harga);
						printf("\n Lama sewa        : %d", lama);
						
						if(lama>5){
							diskon=harga*6/100;
							printf("\n Status reservasi(bonus) : Mendapatkan diskon");
						}else{
							printf("\n Status reservasi(bonus) : Tidak mendapatkan diskon");
						}
					}else if(strcmpi(kode, "EL")==0){
						harga=850000;
						printf("\n Kamar            : Eksklusif");
						printf("\n Umur             : %d", umur);
						printf("\n No. Telp         : %s", no_tlp);
						printf("\n Harga sewa/bulan : %.2f",harga);
						printf("\n Lama sewa        : %d", lama);
						
						if(lama>5){
							diskon=harga*6/100;
							printf("\n Status reservasi(bonus) : Mendapatkan diskon");
						}else{
							printf("\n Status reservasi(bonus) : Tidak mendapatkan diskon");
						}
					}else if(strcmpi(kode, "RL")==0){
						harga=500000;
						printf("\n Kamar            : Reguler");
						printf("\n Umur             : %d", umur);
						printf("\n No. Telp         : %s", no_tlp);
						printf("\n Harga sewa/bulan : %.2f",harga);
						printf("\n Lama sewa        : %d", lama);
						
						if(lama>5){
							diskon=harga*6/100;
							printf("\n Status reservasi(bonus) : Mendapatkan diskon");
						}else{
							printf("\n Status reservasi(bonus) : Tidak mendapatkan diskon");
						}
					}else if(strcmpi(kode, "EM")==0){
						harga=350000;
						printf("\n Kamar            : Ekonomi");
						printf("\n Umur             : %d", umur);
						printf("\n No. Telp         : %s", no_tlp);
						printf("\n Harga sewa/bulan : %.2f", harga);
						printf("\n Lama sewa        : %d", lama);
						if(lama>5){
							diskon=harga*6/100;
							printf("\n Status reservasi(bonus) : Mendapatkan diskon");
						}else{
							printf("\n Status reservasi(bonus) : Tidak mendapatkan diskon");
						}
					}
					printf("\n==========================\n");
					total=lama*harga+diskon;
					printf("\nDiskon(bonus) : %.2f", diskon);
					printf("\nTotal: %.2f", total);
					printf("\nUang anda: "); scanf("%f", &uang);
					if(uang>total){
						kembalian=uang-total;
						printf("\n\n Kembalian: %.2f", kembalian);
						printf("\n Pembayaran berhasil !");
						log=0;
						input=0;
					}else if(uang<total){
						printf("\n Maaf uang anda tidak cukup !");
					}
				}else if(log==0){
					printf("\n Anda belum login");
				}else if(input==0){
					printf("\n Anda belum input");
				}
				break;
			case 0:
				printf("\n Made Riksi Purnama Sadnya Agung | 210711396 | D");
				printf("\n Mengerjakan UGD ini dengan jujur");
				break;
			default:
				printf("\n Menu tidak ditemukan !");
				break;
		}
		getch();	
	}while(pil!=0);
	return 0;
}
