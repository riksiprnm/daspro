#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef char string[30];

// Made Riksi Purnama Sadnya Agung /  210711396 / D
int main() {
	string nama, hobi, kode;
	int umur;

	printf("---=== GD PEMILIHAN IF-ELSE ===---");
	printf("\nNama : "); fflush(stdin); gets(nama);
	printf("hobi : "); fflush(stdin); gets(hobi);
	printf("Umur : "); scanf("%d", &umur);

	if (strlen(nama)>0 && strlen(hobi)>0 && umur>0){
		printf("\n\tNama : %s", nama);
		printf("\n\tHobi : %s", hobi);
		printf("\n\tUmur : %d", umur);
		printf("\n\tKode [A23 | B45]: "); fflush(stdin); gets(kode);

		if (strcmpi(kode, "A23")==0){
			printf("\n\tSelamat Kamu Menjadi gold member...");
			
		} else if (strcmpi(kode, "B45")==0){
			printf("\n\tSelamat Kamu Menjadi silver member...");
		} else{
			printf("\nKode salah [!]");
		}
		
	} else{
		printf("\nSemua data tidak boleh kosong[!]");
	}
	
	return 0;
}
