#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef char string[20];

int main(int argc, char *argv[]) {
	
	string nama = "Made Riksi Purnama";
	
	string namaPanggilan;
	float nilaiFisika, nilaiBiologi, mean=0;
	int umur;
	char jenisKelamin;
	
	printf("\n---[ Input Data ]---");
	printf("\nNama                : %s", nama);
	printf("\nNama Panggilan      : "); fflush(stdin); gets(namaPanggilan);
	printf("Nilai Fisika        : "); scanf("%f", &nilaiFisika);
	printf("Nilai Biologi	    : "); scanf("%f", &nilaiBiologi);
	printf("Umur                : "); scanf("%d", &umur);
	printf("Jenis Kelamin (L/K) : "); jenisKelamin = getche();
	
	mean += nilaiFisika;
	mean += nilaiBiologi;
	mean /= 2;
	
	umur++;
	
	printf("\n\n---[ Tampil Data ]---");
	printf("\nNama                : %s", nama);
	printf("\nNama Panggilan      : %s", namaPanggilan);
	printf("\nNilai Rata-rata     : %.2f", mean);
	printf("\nUmur                : %d", umur);
	printf("\nJenis Kelamin (L/K) : %c", jenisKelamin);
	
	return 0;
}
