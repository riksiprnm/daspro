#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include <conio.h>
typedef char string[50];

typedef struct{
	string nama;
	int sks;
}MataKuliah;

typedef struct{
	string username;
	string password;
	string nama;
	MataKuliah matkul[3];
}Mahasiswa;

int cekLog(Mahasiswa mhs[], string user, string pass);
int isFullMhs(Mahasiswa mhs[]);
int takeMhsNull(Mahasiswa mhs[]);
int takeIndexMhs(Mahasiswa mhs[], string user);
int isSameUser(Mahasiswa mhs[], string user);
int isFullMatkul(Mahasiswa mhs[], int indexMhs);
int takeMatkulNull(Mahasiswa mhs[], int indexMhs);
int takeIndexMatkul(Mahasiswa mhs[], int indexMhs, string matkul);

void init(Mahasiswa mhs[]);
void menuAdmin();
void menuMhs(Mahasiswa mhs[], int indexMhs);
void tampilMhs(Mahasiswa mhs[]);
void tampilData(Mahasiswa mhs[], int indexMhs);

int main(int argc, char *argv[]){
	Mahasiswa mhs[3];
	int pil[2], indexMhs, indexMatkul, sks;
	string user, pass,nama, matkul;
	init(mhs);
	do{
		do{
			system("cls");
			printf("\n\t\t--== LOGIN ===--\n");
			printf("\n\tUsername : "); fflush(stdin); gets(user);
			printf("\tPassword : "); fflush(stdin); gets(pass);
			if(cekLog(mhs,user,pass)==-1){
				printf("\n\t\t[!] Username atau password salah"); getch();
			}
		}while(cekLog(mhs,user,pass)==-1);

		pil[0]=cekLog(mhs,user,pass);
		switch (pil[0]){
		case 1:
			printf("\n\t\t[~] Login sebagai admin");
			getch();
			do{
				system("cls");
				menuAdmin();
				printf("\n\t>> "); scanf("%d", &pil[1]);
				switch (pil[1]){
				case 1:
					if(isFullMhs(mhs)==0){
						printf("\n\t\t--=== Input Mahasiswa ===--\n");
						do{
							printf("\n\tInput Username : "); fflush(stdin); gets(user);
							if(strlen(user)==0){
								printf("\n\t\t[!] Username tidak boleh kosong\n");
							}else if(isSameUser(mhs,user)==1){
								printf("\n\t\t[!] Username tidak boleh sama\n");
							}
						}while(strlen(user)==0 || isSameUser(mhs,user)==1);
						do{
							printf("\n\tInput Password : "); fflush(stdin); gets(pass);
							if(strlen(pass)==0){
								printf("\n\t\t[!] Password tidak boleh kosong\n");
							}
						}while(strlen(pass)==0);
						do{
							printf("\n\tInput Nama     : "); fflush(stdin); gets(nama);
							if(strlen(nama)==0){
								printf("\n\t\t[!] Nama tidak boleh kosong\n");
							}
						}while(strlen(nama)==0);
						indexMhs=takeMhsNull(mhs);
						strcpy(mhs[indexMhs].username,user);
						strcpy(mhs[indexMhs].password,pass);
						strcpy(mhs[indexMhs].nama,nama);
						printf("\n\t\t[~] Berhasil input data mahasiswa");
					}else{
						printf("\n\t\t[!] Mahasiswa sudah penuh");
					}
					getch();
					break;
				case 2:
					tampilMhs(mhs);
					getch();
				break;
				case 0:
					printf("\n\t\t[~] Kembali ke menu utama . . .");
				break;
				default:
					printf("\n\t\t[!] Menu tidak tersedia");
					getch();
				break;
				}
				
			}while(pil[1]!=0);

		break;
		
		case 2:
			printf("\n\t\t[~] Login sebagai Mahasiswa");
			getch();
			indexMhs=takeIndexMhs(mhs,user);
			do{
				system("cls");
				menuMhs(mhs,indexMhs);
				printf("\n\t>> "); scanf("%d", &pil[1]);
				switch (pil[1]){
				case 1:
					if(isFullMatkul(mhs, indexMhs)==0){
						printf("\n\t\t--=== Input Mata Kuliah ===--\n");
						do{
							printf("\n\tInput Nama Mata Kuliah : "); fflush(stdin); gets(matkul);
							if(strlen(matkul)==0){
								printf("\n\t\t[!] Nama mata kuliah tidak boleh kosong\n");
							}
						}while(strlen(matkul)==0);
						do{
							printf("\n\tInput Jumlah SKS       : "); scanf("%d", &sks);
							if(sks<=0){
								printf("\n\t\t[!] Jumlah SKS tidak boleh kurang dari 1\n");
							}
						}while(sks<=0);
						indexMatkul=takeMatkulNull(mhs,indexMhs);
						strcpy(mhs[indexMhs].matkul[indexMatkul].nama, matkul);
						mhs[indexMhs].matkul[indexMatkul].sks=sks;
						printf("\n\t\t[~] Berhasil input  mata kuliah");
					}else{
						printf("\n\t\t[!] Mata kuliah mahasiswa sudah penuh");
					}
					getch();
				break;
				case 2:
					printf("\n\tMasukkan nama mata kuliah : "); fflush(stdin); gets(matkul);
					if(takeIndexMatkul(mhs,indexMhs,matkul)!=-1){
						indexMatkul=takeIndexMatkul(mhs,indexMhs,matkul);
						strcpy(mhs[indexMhs].matkul[indexMatkul].nama,"-");
						mhs[indexMhs].matkul[indexMatkul].sks=0;
						printf("\n\t\t[~] Berhasil hapus data mata kuliah");
					}else{
						printf("\n\t\t[!] Mata kuliah tidak ada");
					}
					getch();
				break;
				case 3:
					tampilData(mhs,indexMhs);
					getch();
				break;
				case 0:
					printf("\n\t\t[~] Kembali ke menu utama");
				break;
				default:
					printf("\n\t\t[!] Menu tidak ditemukan");
					getch();
				break;
				}
			}while(pil[1]!=0);
		break;
		case 0:
			printf("\n\t\t[~] Logout . . .");
		break;
		default:
			printf("\n\t\t[!] Menu tidak ditemukan");
			break;
		}
	getch();	
	}while(pil[0]!=0);
	return 0;
}

int cekLog(Mahasiswa mhs[], string user, string pass){
	int i;
	if(strcmp(user,"Admin")==0 && strcmp(pass,"Admin")==0) return 1;
	else if(strcmp(user,"logout")==0 && strcmp(pass,"logout")==0){
		return 0;
	}else{
		for(i=0;i<3;i++){
			if(strcmp(user,mhs[i].username)==0 && strcmp(pass,mhs[i].password)==0) return 2;
		}
	}
	return -1;
}
int isFullMhs(Mahasiswa mhs[]){
	int i;
	for(i=0;i<3;i++){
		if(strcmp(mhs[i].nama,"-")==0) return 0;
	}
	return 1;
}
int takeMhsNull(Mahasiswa mhs[]){
	int i;
	for(i=0;i<3;i++){
		if(strcmp(mhs[i].nama,"-")==0) return i;
	}
}
int takeIndexMhs(Mahasiswa mhs[], string user){
	int i;
	for(i=0;i<3;i++){
		if(strcmp(mhs[i].username,user)==0) return i;
	}
}
int isSameUser(Mahasiswa mhs[], string user){
	int i;
	for(i=0;i<3;i++){
		if(strcmp(user, mhs[i].username)==0) return 1;
	}
	return 0;
}
int isFullMatkul(Mahasiswa mhs[], int indexMhs){
	int i;
	for(i=0;i<3;i++){
		if(strcmp(mhs[indexMhs].matkul[i].nama,"-")==0) return 0;
	}
	return -1;
}
int takeMatkulNull(Mahasiswa mhs[], int indexMhs){
	int j;
	for(j=0;j<3;j++){
		if(strcmp(mhs[indexMhs].matkul[j].nama,"-")==0) return j;
	}
	return -1;
}
int takeIndexMatkul(Mahasiswa mhs[], int indexMhs, string matkul){
	int i;
	for(i=0;i<3;i++){
		if(strcmp(mhs[indexMhs].matkul[i].nama,matkul)==0) return i;
	}
	return -1;
}

void init(Mahasiswa mhs[]){
	int i,j;
	for(i=0;i<3;i++){
		strcpy(mhs[i].username,"-");
		strcpy(mhs[i].password,"-");
		strcpy(mhs[i].nama,"-");
		for(j=0;j<3;j++){
			strcpy(mhs[i].matkul[j].nama,"-");
			mhs[i].matkul[j].sks=0;
		}
	}
}
void menuAdmin(){
	printf("\n\t\t--=== Menu Admin ===--\n");
	printf("\n\t[1] Input Mahasiswa");
	printf("\n\t[2] Tampil Mahasiswa");
	printf("\n\t[0] Logout");
}
void menuMhs(Mahasiswa mhs[], int indexMhs){
	printf("\n\t\t--=== Menu Mahasiswa ===--\n");
	printf("\n\t\tHalo pengguna : %s", mhs[indexMhs].nama);
	printf("\n\t[1] Input Mata Kuliah");
	printf("\n\t[2] Hapus Mata Kuliah");
	printf("\n\t[3] Tampil Mahasiswa");
	printf("\n\t[0] Logout");
}
void tampilMhs(Mahasiswa mhs[]){
	int i,j;
	printf("\n\t\t--=== Tampil Data Mahasiswa ===--\n");
	for(i=0;i<3;i++){
		if(strcmp(mhs[i].nama,"-")!=0){
			printf("\n\t--- Data Mahasiswa ke-%d ---", i+1);
			printf("\n\tUsername Mahasiswa : %s",mhs[i].username);
			printf("\n\tPassword Mahasiswa : %s",mhs[i].password);
			printf("\n\tNama Mahasiswa     : %s\n",mhs[i].nama);
			for(j=0;j<3;j++){
				if(strcmp(mhs[i].matkul[j].nama,"-")!=0){
					printf("\n\t\t--- Data Mata Kuliah ---");
					printf("\n\t\tNama Mata Kuliah : %s", mhs[i].matkul[j].nama);
					printf("\n\t\tSKS              : %d\n", mhs[i].matkul[j].sks);
				}
			}
		}
	}
}
void tampilData(Mahasiswa mhs[], int indexMhs){
	int i;
	printf("\n\t\t--=== Data Mahasiswa ===--");
	printf("\n\tUsername Mahasiswa : %s",mhs[indexMhs].username);
	printf("\n\tPassword Mahasiswa : %s",mhs[indexMhs].password);
	printf("\n\tNama Mahasiswa     : %s\n",mhs[indexMhs].nama);
	for(i=0;i<3;i++){
		if(strcmp(mhs[indexMhs].matkul[i].nama,"-")!=0){
			printf("\n\t\t--- Data Mata Kuliah ---");
			printf("\n\t\tNama Mata Kuliah : %s", mhs[indexMhs].matkul[i].nama);
			printf("\n\t\tSKS              : %d\n", mhs[indexMhs].matkul[i].sks);
		}
	}
}
