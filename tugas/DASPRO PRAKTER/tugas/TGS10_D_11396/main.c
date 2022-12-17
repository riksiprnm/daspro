#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define ESC 27

//BONUS
//Made Riksi Purnama Sadnya Agung 210711396

typedef char string[50];
int cekUser(string user, string pass);
int cekHewan(string nama, string dataHewan[]);
int isFull(string dataHewan[]);
int cariIndex(string dataHewan[], string nama);
int namaSama(string dataHewan[], string nama);
void tampilData(string dataHewan[], string dataKelas[]);
void menuGuest();
void menuPengelola();
void sorting(string dataHewan[], string dataKelas[]);
void reverse(string dataHewan[], string dataKelas[]);
int main(int argc, char *argv[]) {
	string dataHewan[17]={"Beruang Kutub", "Katak", "Burung Merak", 
						 "Singa", "Macan", "Burung Unta", "Salmon",
						 "Buaya", "Serigala", "Ikan Mas", "Ular Piton",
						 "Ikan Cupang", "Burung Elang", "Kura kura",
						 "Kelinci", "Alligator", "Paus"};

	string dataKelas[17]={"Mamalia", "Amfibi", "Burung", "Mamalia",
						  "Mamalia", "Burung", "Ikan", "Reptil", "Mamalia",
						  "Ikan", "Reptil", "Ikan", "Burung", "Reptil",
						  "Mamalia", "Reptil", "Mamalia"};

	string user, pass,nama,jenis;
	char pil1,pil2;
	int index;

	do{
		do{
			system("cls");
			printf("\n\t\tMENU LOGIN\n");
			printf("\n\tUsername : "); fflush(stdin); gets(user);
			printf("\tPassword : "); fflush(stdin); gets(pass);
			if(cekUser(user, pass)==-1){
				printf("\n\t\t[!] Username atau Password salah\n");
				getch();
			}
		}while(cekUser(user, pass)==-1);

		if(cekUser(user,pass)==1){
			do{
				system("cls");
				menuGuest();
				printf("\n\t>>> "); pil1=getch();
				switch (pil1)
				{
				case '1':
					do{
						printf("\n\tMasukkan nama hewan : "); fflush(stdin); gets(nama);
						if(strlen(nama)==0){
							printf("\n\t\t[!] Inputan nama tidak boleh kosong\n");
						}
					}while(strlen(nama)==0);
					if(cekHewan(nama,dataHewan)!=-1){
						index=cekHewan(nama,dataHewan);
						printf("\n\tHewan tersebut merupakan hewan [ %s ]",dataKelas[index]);
					}else{
						printf("\n\t\t[!] Data kelas tidak tersedia");
					}
					
				break;
				
				case 27:
					printf("\n\tLogout . . .");
				break;
				default:
					printf("\n\t\t[!] Menu tidak tersedia");
				break;
				}
				getch();
			}while(pil1!=27);
		}else if(cekUser(user,pass)==2){
			do{
				system("cls");
				menuPengelola();
				printf("\n\t>>> "); pil2=getch();
				switch (pil2){
				case '1':
				if(isFull(dataHewan)!=-1){
					do{
						printf("\n\tMasukkan nama hewan : "); fflush(stdin); gets(nama);
						if(strlen(nama)==0){
							printf("\nInputan nama hewan tidak boleh kosong\n");
						}else if(namaSama(dataHewan,nama)==1){
							printf("\n\t\t[!] Nama harus unik\n");
						}
					}while(strlen(nama)==0 || namaSama(dataHewan,nama)==1);
					do{
						printf("\n\tMasukkan nama kelas : "); fflush(stdin); gets(jenis);
						if(strlen(jenis)==0){
							printf("\nInputan nama kelas tidak boleh kosong\n");
						}
					}while(strlen(jenis)==0);
					
					index=cariIndex(dataHewan,nama);
					strcpy(dataHewan[index],nama);
					strcpy(dataKelas[index],jenis);
					tampilData(dataHewan,dataKelas);

				}else{
					printf("\n\t\t[!] Data hewan sudah terisi penuh");
				}
				break;
				case '2':
					printf("\n\tMasukkan nama hewan yang diedit : "); fflush(stdin); gets(nama);
					index=cekHewan(nama, dataHewan);
					if(namaSama(dataHewan,nama)==1){
						do{
							printf("\n\tMasukkan nama hewan yang baru : "); fflush(stdin); gets(nama);
							if(strlen(nama)==0){
								printf("\n\t\t[!] Inputan nama tidak boleh kosong\n");
							}else if( namaSama(dataHewan,nama)==1){
								printf("\n\t\t[!] Nama harus unik\n");
							}
						}while(strlen(nama)==0 || namaSama(dataHewan,nama)==1);
						do{
							printf("\n\tMasukkan nama kelas yang baru : "); fflush(stdin); gets(jenis);
							if(strlen(jenis)==0){
								printf("\n\t\t[!] Inputan nama kelas tidak boleh kosong\n");
							}
						}while(strlen(jenis)==0);
						strcpy(dataHewan[index],nama);
						strcpy(dataKelas[index],jenis);
						tampilData(dataHewan,dataKelas);
					}else{
						printf("\n\t\t[!] Nama hewan tidak ditemukan");
					}
				break;
				case '3':
					printf("\n\tMasukkan nama hewan yang dihapus: "); fflush(stdin); gets(nama);
					if(cekHewan(nama,dataHewan)!=-1){
						index=cekHewan(nama,dataHewan);
						strcpy(dataHewan[index],"-");
						strcpy(dataKelas[index],"-");
						tampilData(dataHewan,dataKelas);
					}else{
						printf("\n\t\t[!] Nama hewan tidak ditemukan");
					}
				break;
				case '4':
					if(isFull(dataHewan)==-1){
						printf("\n\n\t[~] Sebelum Sorting [~]");
						tampilData(dataHewan,dataKelas);
						printf("\n\n\t-------------------------------------------------------\n");
						sorting(dataHewan,dataKelas);
						printf("\n\t[~] Setelah Sorting [~]");
						tampilData(dataHewan,dataKelas);
					}else{
						printf("\n\t\t[!] Data hewan tidak terisi penuh");	
					}
				break;
				case '5':
					printf("\n\n\t[~] Sebelum Reverse [~]");
					tampilData(dataHewan,dataKelas);
					printf("\n\n\t-------------------------------------------------------\n");
					printf("\n\t[~] Setelah Reverse [~]");
					reverse(dataHewan,dataKelas);
					tampilData(dataHewan,dataKelas);
				break;
				case 27:
					printf("\n\tLogout . . .");
				break;
				
				default:
					printf("\n\t\t[!] Menu tidak tersedia");
				break;
				}
				getch();
			}while(pil2!=27);
		}
	}while(cekUser(user,pass)!=0);
	return 0;
}
int cekUser(string user, string pass){
	if(strcmp(user,"Zooey")==0 && strcmp(pass,"zooeyjaya")==0){
		return 2;
	}else if(strcmp(user,"guest")==0 && strcmp(pass,"guest")==0){
		return 1;
	}else if(strcmpi(user,"exit")==0 && strcmpi(pass,"exit")==0){
		return 0;
	}else{
		return -1;
	}
}
void menuGuest(){
	printf("\n\t\tLOGIN : PENGUNJUNG\n");
	printf("\n\t[1] Menu Input");
	printf("\n\t[ESC] Exit");
}
void menuPengelola(){
	printf("\n\t\tLOGIN: PENGELOLA\n");
	printf("\n\t[1] Menu Input");
	printf("\n\t[2] Menu Edit");
	printf("\n\t[3] Menu Delete");
	printf("\n\t[4] Sorting [Bonus]");
	printf("\n\t[5] Reverse [Tugas]");
	printf("\n\t[ESC] Exit");
}
int cekHewan(string nama, string dataHewan[]){
	int i;
	for(i=0;i<17;i++){
		if(strcmpi(nama,dataHewan[i])==0) return i;
	}
	return -1;
}
int cariIndex(string dataHewan[], string nama){
	int i;
	for(i=0;i<17;i++){
		if(strcmpi(dataHewan[i],"-")==0) return i;
	}
}
int isFull(string dataHewan[]){
	int i;
	for(i=0;i<17;i++){
		if(strcmp(dataHewan[i],"-")==0) return 1;
	}
	return -1;
}

int namaSama(string dataHewan[], string nama){
	int i;
	for(i=0;i<17;i++){
		if(strcmpi(nama,dataHewan[i])==0) return 1;
	}
	return 0;
}
void tampilData(string dataHewan[], string dataKelas[]){
	int i,j=0;
	printf("\n\tData hewan : \n\t");
	for(i=0;i<17;i++){
		printf("| %s ", dataHewan[i]);
		j++;
		if(i%5==0){
			printf("|\n\t");
			j=0;
		}
	}
	printf("|");
	printf("\n\tData Kelas : \n\t");
	j=0;
	for(i=0;i<17;i++){
		printf("| %s ", dataKelas[i]);
		j++;
		if(j==5){
			printf("|\n\t");
			j=0;
		}
	}
	printf("|");
}

void sorting(string dataHewan[], string dataKelas[]){
	int i,j;
	string temp,temp2;
	for(i=0;i<16;i++){
		for(j=i+1;j<17;j++){
			if(strcmpi(dataHewan[i],dataHewan[j])>0){
				strcpy(temp,dataHewan[i]);				
				strcpy(dataHewan[i],dataHewan[j]);
 				strcpy(dataHewan[j],temp);

				strcpy(temp2,dataKelas[i]);				
				strcpy(dataKelas[i],dataKelas[j]);
 				strcpy(dataKelas[j],temp2);

			}
		}
	}
}
void reverse(string dataHewan[], string dataKelas[]){
	int i,j=16;
	string tempHewan[17], tempKelas[17];
	for(i=0;i<17;i++){
		strcpy(tempHewan[i],dataHewan[i]);
		strcpy(tempKelas[i],dataKelas[i]);
	}
	for(i=0;i<17;i++){
		strcpy(dataHewan[j],tempHewan[i]);
		strcpy(dataKelas[j],tempKelas[i]);
		j--;
	}
}
