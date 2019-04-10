#include <stdio.h>
typedef struct
{
int s;
int m;
int l;
}ropa;

 main ()
{
ropa v[3];
FILE *pf;

pf=fopen("stock.txt", "wb");

printf("\ncamisetas S: ");
scanf("%d", &v[0].s);

printf("camisetas M: ");
scanf("%d", &v[0].m);

printf("camisetas L: ");
scanf("%d", &v[0].l);


printf("\npantalones S: ");
scanf("%d", &v[1].s);

printf("pantalones M: ");
scanf("%d", &v[1].m);

printf("pantalones L: ");
scanf("%d", &v[1].l);


printf("\nsudaderas S: ");
scanf("%d", &v[2].s);

printf("sudaderas M: ");
scanf("%d", &v[2].m);

printf("sudaderas L: ");
scanf("%d", &v[2].l);


fwrite(&v[0], sizeof(ropa), 1, pf);
fflush(stdin);

fwrite(&v[1], sizeof(ropa), 1, pf); 
fflush(stdin);

fwrite(&v[2], sizeof(ropa), 1, pf); 
fflush(stdin);
fclose(pf);






	
	

pf=fopen("stock.txt", "rb");
fread(&v[0], sizeof(ropa), 1, pf);

printf("Camiseta S: %d\n", v[0].s);
printf("Camiseta M: %d\n", v[0].m);
printf("Camiseta L: %d\n", v[0].l);

fclose(pf);
}























