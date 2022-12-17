#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
	
	int npmSaya = 210711396, npmTeman = 210711397;
	int inputan;
	bool boolean;
	
	printf("\n1 : Benar / True");
	printf("\n2 : Salah / False");
	
	printf("\n\nMasukkan npm : "); scanf("%d", &inputan);
	
	boolean = npmSaya == inputan;
	printf("\n%d sama dengan %d ? %d", npmSaya, inputan, boolean);
	
	boolean = npmSaya != npmTeman;
	printf("\nNPM saya tidak sama dengan NPM teman ? %d", boolean);
	
	boolean = npmSaya > npmTeman;
	printf("\nNPM saya lebih besar dengan NPM teman ? %d", boolean);
	
	boolean = npmSaya < npmTeman;
	printf("\nNPM saya lebih kecil dengan NPM teman ? %d", boolean);
	return 0;
}
