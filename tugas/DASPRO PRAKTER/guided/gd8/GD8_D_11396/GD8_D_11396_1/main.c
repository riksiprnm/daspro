#include <stdio.h>
#include <stdlib.h>

void tukarNilai(int *N1, int *N2);
void kuadrat(int *nilai);

int main(int argc, char *argv[]) {
	int nilai1, nilai2;

	printf("\n\t GUIDED 1\n");
	printf("\nMasukkan nilai 1: "); scanf("%d", &nilai1);
	printf("\nMasukkan nilai 2:: "); scanf("%d", &nilai2);
	printf("\n Input berhasil [!]");
	getch();
	system("cls");

	printf("\n\t GUIDED 1\n");
	printf("\nNilai awal");
	printf("\nNilai 1: %d", nilai1);
	printf("\nNilai 2: %d", nilai2);

	kuadrat(&nilai1);
	kuadrat(&nilai2);

	printf("\n\nSetelah dikuadratkan");
	printf("\nNilai 1: %d", nilai1);
	printf("\nNilai 2: %d", nilai2);

	tukarNilai(&nilai1, &nilai2);

	printf("\n\nSetelah nilai1 dan nilai2 ditukar");
	printf("\nNilai 1: %d", nilai1);
	printf("\nNilai 2: %d", nilai2);
	getch();
	
	return 0;
}

void tukarNilai(int *N1, int *N2){
	int temp;

	temp = *N1;
	*N1 = *N2;
	*N2 = temp;
}

void kuadrat(int *nilai){
	*nilai = (*nilai) * (*nilai);
}
