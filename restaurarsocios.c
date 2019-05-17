#include <stdio.h>

typedef struct
{
	char nombre[100];
	char apellido[100];
	int codigo;


}socia;


main()
{
	FILE *pf;
	socia u[10]={{"Sandra","Rebollo",1234},{"Annia","Malvar",2345}};
	int i;
	int dimension=2;


	pf=fopen("sociod.txt", "w");
	fprintf(pf, "%d", dimension);
	fclose(pf);

	pf=fopen("socios.txt", "wb");
	for (i=0; i<dimension; i++)
		fwrite(&u[i], sizeof(socia), 1, pf);
	fclose(pf);
							

	//Leer socio
	pf=fopen("sociod.txt", "r");
	fscanf(pf,"%d", &dimension);
	printf("%d\n",dimension);
	fclose(pf);


	pf=fopen("socios.txt", "rb");
	for (i=0; i<dimension; i++)
	{
		fread(&u[i], sizeof(socia), 1, pf);

		printf("Nombre: %s.\n", u[i].nombre);
		printf("Apellido: %s.\n", u[i].apellido);
		printf("Codigo: %d.\n", u[i].codigo);

	}
	fclose(pf);								
																
}
