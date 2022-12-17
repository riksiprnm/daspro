//Nama	:  Made Riksi Purnama Sadnya Agung
//NPM	: 210711396
//Kelas	: D

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef char string[50];

int main(int argc, char *argv[]) {
	string nama, jenis;
	int model=12000, harga;
	int cepat1, cepat2, cepat3;
	int no_kereta = 1, totHarga, totHargaKereta, totCepat, jarak, tiket;
	float rata2;
	int terendah;
	float upgrade;
	char type='A';
	
	bool boolean;
	
	printf("\n\t===[ WELCOME TO PT AKI ]===");
	printf("\n Please input your data: ");
	printf("\n Kereta api %d", no_kereta);
	printf("\n Nama               : "); fflush(stdin); gets(nama);
	printf(" Model              : %d", model);
	printf("\n Type               : %c", type);
	printf("\n Jenis              : "); fflush(stdin); gets(jenis); 
	printf(" Harga              : "); scanf("%d", &harga);
	printf(" Kecepatan Maksimum : "); scanf("%d", &cepat1);
	totHarga = harga+ harga*5/100 +harga*6/100;
	totHargaKereta = totHarga;
	printf("\n\n\t[ Harga kereta : Rp %d,- ]",totHarga);
	totCepat = cepat1;
	model++;
	type++;
	no_kereta++;
	
	printf("\n Kereta api %d", no_kereta);
	printf("\n Nama               : "); fflush(stdin); gets(nama);
	printf(" Model              : %d", model);
	printf("\n Type               : %c", type);
	printf("\n Jenis              : "); fflush(stdin); gets(jenis); 
	printf(" Harga              : "); scanf("%d", &harga);
	printf(" Kecepatan Maksimum : "); scanf("%d", &cepat2);
	totHarga = harga+ harga*5/100 +harga*6/100;
	totHargaKereta += totHarga;
	printf("\n\n\t[ Harga kereta : Rp %d,- ]",totHarga);
	totCepat +=cepat2;
	model++;
	type++;
	no_kereta++;

	printf("\n Kereta api %d", no_kereta);
	printf("\n Nama               : "); fflush(stdin); gets(nama);
	printf(" Model              : %d", model);
	printf("\n Type               : %c", type);
	printf("\n Jenis              : "); fflush(stdin); gets(jenis); 
	printf(" Harga              : "); scanf("%d", &harga);
	printf(" Kecepatan Maksimum : "); scanf("%d", &cepat3);
	totHarga = harga+ harga*5/100 +harga*6/100;
	totHargaKereta += totHarga;
	totCepat +=cepat3;
	
	printf("\n\n\t[ Harga kereta : Rp %d,- ]",totHarga);
	
	rata2 = totCepat/3;
	printf("\n\n\t ===[ Tampil Data ]===");
	printf("\n\tJumlah Kereta       : %d",no_kereta);
	printf("\n\tTotal Harga Kereta  : Rp %d",totHargaKereta);
	printf("\n\tRata-rata Kecepatan : %.2f KM/J", rata2);
	
	printf("\n\n\t=== [ Perkiraan Untuk atau Tidak] ===");
	printf("\n\tHarga tiket dan jarak : "); scanf("%d:%d", &tiket, &jarak);
	tiket = tiket*100;
	jarak = jarak*1000000;
	printf("\n\tKeuntungan         : %d", tiket);
	printf("\n\tBiaya operasional  : %d", jarak);
	boolean = tiket > jarak;
	printf("\n\tApakah untung ? :%d", boolean);
	
	printf("\n\n\t=== [ Upgrade Kecepatan ] ===\n");
	
	upgrade = totHargaKereta*3/100;
	terendah = ((cepat1 + cepat2 + cepat3)-(abs((cepat1 + cepat2 + cepat3)-cepat1-cepat2))-(abs(cepat1 + cepat2 + cepat3)-cepat1-cepat3));
	printf("\n\tKecepatan terendah : %d",terendah);
	printf("\n\tBiaya Upgrade      : Rp %.2f",upgrade);
	return 0;
}
