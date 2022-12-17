#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i,j,n,menu, cekMenu=0;

	do{
			system("cls");
			printf("\n\tGuided Perulangan 2");
			printf("\n[1] Masukkan jumlah baris");
			printf("\n[2] Show");
			printf("\n[0] Keluar");
			printf("\n===> "); scanf("%d", &menu);

			switch (menu){
			case 1:
				do{
					printf("Masukkan jumlah baris: "); scanf("%d", &n);
					if(n<1){
						printf("\nInputan tidak boleh di bawah 1\n");
					}else{
						printf("\nBerhasil menginput data");
						cekMenu++;
					}
				}while(n<1);
				break;

			case 2:
				if(cekMenu==0){
					printf("\nInputkan jumlah baris terlebih daulu");
				}else{
					printf("\nTampilan bentuk dari jumlah baris-%d\n",n);
					char huruf='A';

					for(i=1;i<=n+2;i++){
						for(j=1;j<=n+2;j++){
							if(j==1 || i==1 || j==n+2 || i==n+2){
								printf("* ");
							}else{
								printf("%c ", huruf++);
							}

							if(huruf > 'Z'){
								huruf = 'A';
							}
						}
						printf("\n");
					}
				}
				break;
			case 0:
				printf("Guided Perulangan 2 - Made Riksi Purnama Sadnya Agung / 210711396 / D");
				break;
			default:
				printf("Pilihan menu tidak tersedia");
				break;
			}
			getch();
	}while(menu !=0);
	return 0;
}
