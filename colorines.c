/*Este programa nos permite cambiar el color de las letras del programa,consiguiendo asi una mejor estetica en el programa. */

// Annia Pocomucha García	54162
// Yaiza Martín Cabrerizo	54283

#include <windows.h> 
#include <stdio.h>


int main()
{
	int k;
	
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// nos permite imprimir una lista con todas los colores disponibles
	for(k = 1; k < 255; k++)
	{
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),k);
    	printf("%i I want to be nice today!\n",k);
  	}
  	
}
