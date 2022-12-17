#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int jarak = 241378, km, m, cm;
	
	km = jarak/100000;
	m = (jarak%100000)/100;
	cm = (jarak%100000)%100;
	printf("%d %d %d",km,m,cm);
	
}
