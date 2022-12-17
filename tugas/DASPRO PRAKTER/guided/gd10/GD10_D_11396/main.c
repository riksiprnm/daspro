#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

void tampilArray(int arr[]){
	int i;
	for(i=0;i<MAX;i++){
		printf("Array index-%d : %d\n",i,arr[i]);
	}
}
int cariData(int arr[], int cariNilai){
	int i;
	for(i=0;i<MAX;i++){
		if(arr[i]==cariNilai){
			return i;
		}
	}
	return -1;
}
void editArray(int arr[], int cariNilai, int nilaiBaru){
	int i;
	int indexDiCari=cariData(arr,cariNilai);
	if(indexDiCari!=-1){
		arr[indexDiCari]=nilaiBaru;
	}else{
		printf("Data tidak ditemukan!");
	}
}

int main(int argc, char *argv[]) {
	int arrA[MAX];
	int arrB[MAX];
	int arrC[MAX];

	int i,j;
	printf("\nArray A: ");
	for(i=0;i<MAX;i++){
		printf("\nMasukkan data Array A index-%d : ",i); scanf("%d", &arrA[i]);
	}
	printf("\n\nArray B: ");
	for(i=0;i<MAX;i++){
		printf("\nMasukkan data Array B index-%d : ",i); scanf("%d", &arrB[i]);
	}

	printf("\n\nIsi seluruh Array A : \n");
	tampilArray(arrA);

	printf("\n\nIsi seluruh Array B : \n");
	tampilArray(arrB);

	int cari,index,nilaiBaru;
	printf("\n\nMasukkan nilai yang ingin di cari pada Array A : "); scanf("%d", &cari);
	index=cariData(arrA,cari);
	if(index==-1){
		printf("Data tidak ditemukan!");
	}else{
		printf("Data %d terdapat pada index ke-%d Array A", cari,index);
	}

	printf("\n\nMasukkan nilai yang ingin diubah pada Array B : "); scanf("%d", &cari);
	printf("Masukkan nilai yang baru : "); scanf("%d", &nilaiBaru);
	editArray(arrB,cari,nilaiBaru);
	printf("\n\nArray B yang sudah diedit : \n");
	tampilArray(arrB);
	return 0;
}
