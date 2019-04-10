// Simulación de una visita a una tienda de ropa.
// Grupo N06
// Annia Pocomucha García
// Yaiza Martín CAbrerizo


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define A 3
#define B 1


//Estructuras
typedef struct
{
	int s;
	int m;
	int l;
}ropa;

typedef struct
{
	int s;
	int m;
	int l;
}listadecompra;

typedef struct
{
	char nombre[100];
	char apellido[100];
	int codigo;
}socia;

typedef struct
{
	char nombre[100];
	char apellido[100];
	int codigo;
}sociointroducido;


//Funciones
void banner();
void ticketfinal(int g0, int g1, int g2, float x, float y, float z);
void descuentos(int f0, int f1, int f2, float x, float y, float z, float a, float b, float c);
char opciones();

int cargarstock(ropa* v0, ropa* v1, ropa* v2);
void guardarstock(ropa v0, ropa v1, ropa v2);
void cargardimension(int *p);
float cargarsocios(int a, socia *u);
void guardarsocios(int a, socia *u);


main()
{
	double dinero;
	int d;
	float x;		//Para el dinero (dos cifras)
	int x_entero;	//Para el dinero (dos cifras)
	char opcion;	//opcion comprar o devolver
	char volver;	//opcion volver a empezar
	char masmas;	//opcion volver a empezar (pero no tienes que introducir el efectivo más veces)
	char de; 		//opcion de devolucion (camiseta o pantalon o sudadera)
	char masde;		//opcion de devolver mas cosas
	char co;		//opcion de comprar (camiseta o pantalon o sudadera)
	char mascom;    //opcion de comprar mas cosas
	float precio;
	float camiseta = 9.99;
	float pantalon = 24.99;
	float sudadera = 29.99;
	char talla;
	float ticket;
	int w0;			//total de camisetas
	int w1;			//total de pantalones
	int w2;			//total de sudaderas
	char pago; 		//opcion de pago
	int i;
	int pin;
	char socio;		//Ser socio o no
	char nuevosocio; //Querer ser socio o no
	int j;			//Indice para leer socios
	int dimension;	//Leer la cantidad de socios
	int dimen;		//Indica a la memoria dinamica el tamaño del vector
	int orden;		//Para comparar los socios con los socios nuevos si son iguales
	int a;			//Indice para recorrer los socios y comparar
	int anadir;		//Si es ==0 no hay socios repetidos
	int annadir;
	char intento;	//Si al añadir socio da error, intentarlo otra vez
	float descuento=0.15;
	float iva=0.21;
	float ivas;
	float valoracion;
	int nn; 		//para saber si es camiseta, pantalon o sudadera
	int cantidad;	//numero de prendas que quieres llevarte
	
	

//Miembros de las estructuras
ropa *v;
v=malloc(A*sizeof(ropa));

listadecompra *w;
w=malloc(A*sizeof(listadecompra));

sociointroducido *y;
y=malloc(B*sizeof(sociointroducido));	

socia *u;


//Palabras
char *pd;
char pd1 []="camiseta";
char pd2 []="pantalon";
char pd3 []="sudadera";
	
FILE *pf;	



//Cargar el stock
cargarstock( &v[0], &v[1], &v[2]);
																

do{

banner();

							
	printf ("\n\n\250De cu\240nto dinero dispone para gastar en nuestra tienda\77 \n");

do{
	printf ("\n(Debe insertar una cifra positiva con menos de dos cifras decimales\n");
	scanf ("%lf", &dinero);
	fflush (stdin);
	
		x= 100 * dinero;
		x_entero = x;	
		
		if (x - x_entero)
			{	
			printf ("\nIntentelo otra vez.\n");
			d=0;
			}
		else if (dinero < 0)
			{		
			printf ("\nIntentelo otra vez.\n");
			d=0;
			}
		else
			{			
			printf ("\nSu saldo es de %.2f$", dinero);
			d=1;
			}
				
} while (d==0); //Comprobar que tiene dos cifras decimales y positico

do{

printf ("\n\n\250Qu\202 desea hacer en nuestra tienda?\n\n");
	printf ("\tD - Devoluci\242n\n");
	printf ("\tC - Compra\n");
	printf ("\tS - Salir de la tienda\n");
	
	scanf("%c", &opcion);
	fflush (stdin);
	
	switch (opcion)
	{
		case 'D':
		case 'd':
			do{
			
			printf ("\250Qu\202 desea devolver?\n");			
			
				de=opciones();
					
					if (de=='c'|| de=='C')
					{
					pd=malloc(sizeof(pd1));
					nn=0;
					strcpy(pd,pd1); 
					precio=camiseta;
					}
						
					if (de=='p'|| de=='P')
					{
					pd=malloc(sizeof(pd2));
					nn=1;
					strcpy(pd,pd2); 
					precio=pantalon;
					}
					
					if (de=='s'|| de=='S')
					{
					pd=malloc(sizeof(pd3));
					nn=2;
					strcpy(pd,pd3); 
					precio=sudadera;
					}
							
							if (de=='c'|| de=='C'||de=='p'|| de=='P'||de=='s'|| de=='S')
							{												
							printf ("\n\250De que talla es su %s?\n",pd);
									printf ("\tS \t");
									printf ("\tM \t");
									printf ("\tL \n");
							scanf ("%c", &talla);
							fflush (stdin);
								
								if (talla=='s' || talla == 'S')
									{
									v[nn].s += 1;
								
									if (v[nn].s==1)
									{
										if (de=='p'|| de=='P')
										printf("\n\nQuedan %d pantal\242n de talla %c en stock.", v[nn].s, talla);
										else
										printf("\nQuedan %d %s de talla %c en stock.", v[nn].s,pd, talla);
									}
									else
									{
										if (de=='p'|| de=='P')
										printf("\n\nQuedan %d %ses  de talla %c en stock.", v[nn].s, pd, talla);
										else
										printf("\n\nQuedan %d %ss de talla %c en stock.", v[nn].s,pd, talla);
									}
									
									
									dinero+=precio;
									printf ("\n\nSe le ha devuelto el importe de la prenda.");
									printf ("\n\nSu dinero es ahora de %.2f$", dinero);
									}
								
								else if (talla=='m' || talla == 'M')
									{
									v[nn].m += 1;
								
									if (v[nn].m==1)
									{
										if (de=='p'|| de=='P')
										printf("\n\nQuedan %d pantal\242n de talla %c en stock.", v[nn].m, talla);
										else
										printf("\n\nQuedan %d %s de talla %c en stock.", v[nn].m,pd, talla);
									}
									else
									{
										if (de=='p'|| de=='P')
										printf("\n\nQuedan %d %ses  de talla %c en stock.", v[nn].m, pd, talla);
										else
										printf("\n\nQuedan %d %ss de talla %c en stock.", v[nn].m,pd, talla);
									}
									
									
									dinero+=precio;
									printf ("\n\nSe le ha devuelto el importe de la prenda.");
									printf ("\n\nSu dinero es ahora de %.2f$", dinero);
									}
								
								else if (talla=='l' || talla == 'L')
									{
									v[nn].l += 1;
								
									if (v[nn].l==1)
									{
										if (de=='p'|| de=='P')
										printf("\n\nQuedan %d pantal\242n de talla %c en stock.", v[nn].l, talla);
										else
										printf("\n\nQuedan %d %s de talla %c en stock.", v[nn].l,pd, talla);
									}
									else
									{
										if (de=='p'|| de=='P')
										printf("\n\nQuedan %d %ses  de talla %c en stock.", v[nn].l, pd, talla);
										else
										printf("\n\nQuedan %d %ss de talla %c en stock.", v[nn].l,pd, talla);
									}
									
									
									dinero+=precio;
									printf ("\n\nSe le ha devuelto el importe de la prenda.");
									printf ("\n\nSu dinero es ahora de %.2f$", dinero);
									}
								else
									{
									printf ("\n\nTalla err\242nea.");
									printf ("\n\nNo podemos realizar la devoluci\242n.");
									}	
									
								//Guardar modificaciones	
								
								
								guardarstock(v[0], v[1], v[2]);
								
						}
						else
						puts ("\n\n Opci\242n err\242nea.");
				
				
				printf ("\n\n\250Desea devolver otro art\241culo?\n");
				scanf ("%c", &masde);	
				fflush (stdin);
			}while (masde != 'n' && masde != 'N');
			
				break;
				
		case 'C':
		case 'c':

		ticket=0;
					
		w[0].s=0;
		w[0].m=0;
		w[0].l=0;
		w[1].s=0;
		w[1].l=0;
		w[1].m=0;
		w[2].s=0;
		w[2].l=0;
		w[2].m=0;

				do
				{
				printf ("\n\250Qu\202 desea comprar?\n");
				
				co=opciones();
				
							
							if (co=='c'|| co=='C')
							{
							pd=malloc(sizeof(pd1));	
							nn=0;
							strcpy(pd,pd1); 
							precio=camiseta;
							}
									
							if (co=='p'|| co=='P')
							{
							pd=malloc(sizeof(pd2));
							nn=1;
							strcpy(pd,pd2); 
							precio=pantalon;
							}
								
							if (co=='s'|| co=='S')
							{
							pd=malloc(sizeof(pd3));
							nn=2;
							strcpy(pd,pd3); 
							precio=sudadera;
							}
										
							
							if (co=='c'|| co=='C'|| co=='p'|| co=='P'|| co=='s'|| co=='S')
							{
							printf ("\n\250De que talla quiere su %s?\n",pd);
									printf ("\tS \t");
									printf ("\tM \t");
									printf ("\tL \n");
							scanf ("%c", &talla);
							fflush (stdin);
								if (talla=='s' || talla == 'S')
								{
									if (v[nn].s == 0)
										printf ("\nNo quedan prendas de esta talla.");
																			
									else									
									{
										printf ("\n\250Cu\240ntas unidades desea llevar?");
										do
										{
										printf ("\n(Debe ser un n\243mero positivo)\n");
										scanf("%d", &cantidad);
										fflush (stdin);
										}while (cantidad<=0);
									
									if (v[nn].s-cantidad<0)
										printf ("\n\nLo sentimos, no disponemos de esa cantidad de prendas.");
									else
									{
									
									w[nn].s+=cantidad;
									v[nn].s-=cantidad;
									
								
									
									if (w[nn].s==1)
									{
										if (co=='p'|| co=='P')
										printf("\nHa elegido %d pantal\242n de talla %c.", w[nn].s, talla);
										else
										printf("\nHa elegido %d %s de talla %c.", w[nn].s, pd, talla);
									}
									
									else
									{
										if (co=='p'|| co=='P')
										printf("\nHa elegido %d %ses  de talla %c.", w[nn].s, pd, talla);
										else
										printf("\nHa elegido %d %ss de talla %c.", w[nn].s, pd, talla);
									}
									
									
									
									w0=w[0].s+w[0].m+w[0].l;
									w1=w[1].s+w[1].m+w[1].l;
									w2=w[2].s+w[2].m+w[2].l;
									printf("\n\nLleva en su cesta: \n\t%d camiseta/s \n\t%d pantal\242n/es  \n\t%d sudadera/s.", w0, w1, w2);
								
									ticket+=precio*cantidad;
									printf ("\n\nTotal de la cesta:  %.2f$", ticket);
									}
									}
									
									
								}
								else if (talla=='m' || talla == 'M')
								{
									if (v[nn].m == 0)
									printf ("\nNo quedan prendas de esta talla.");
									else
									{
										printf ("\n\250Cu\240ntas unidades desea llevar?");
										do
										{
										printf ("\n\(Debe ser un n\243mero positivo)\n");
										scanf("%d", &cantidad);
										fflush (stdin);
										}while (cantidad<=0);
									
									if (v[nn].m-cantidad<0)
										printf ("\nNo disponemos de esa cantidad de prendas.");
									else
									{
										
									w[nn].m+=cantidad;
									v[nn].m-=cantidad;
									
								
									
									if (w[nn].m==1)
									{
										if (co=='p'|| co=='P')
										printf("\nHa elegido %d pantal\242n de talla %c.", w[nn].m, talla);
										else
										printf("\nHa elegido %d %s de talla %c.", w[nn].m, pd, talla);
									}
									
									else
									{
										if (co=='p'|| co=='P')
										printf("\nHa elegido %d %ses  de talla %c.", w[nn].m, pd, talla);
										else
										printf("\nHa elegido %d %ss de talla %c.", w[nn].m, pd, talla);
									}
									
									
									
									w0=w[0].s+w[0].m+w[0].l;
									w1=w[1].s+w[1].m+w[1].l;
									w2=w[2].s+w[2].m+w[2].l;
									printf("\n\nLleva en su cesta: \n\t%d camiseta/s \n\t%d pantal\242n/es  \n\t%d sudadera/s.", w0, w1, w2);
								
									ticket+=precio*cantidad;
									printf ("\n\nTotal de la cesta:  %.2f$", ticket);
									}
									}
									
								}
								else if (talla=='l' || talla == 'L')
								{
				 						if (v[nn].l == 0)
										printf ("\nNo quedan prendas de esta talla.");
									else
									{
										printf ("\n\250Cu\240ntas unidades desea llevar?");
										do
										{
										printf ("\n\(Debe ser un n\243mero positivo)\n");
										scanf("%d", &cantidad);
										fflush (stdin);
										}while (cantidad<=0);
									
									if (v[nn].l-cantidad<0)
										printf ("\nNo disponemos de esa cantidad de prendas.");
									else
									{
										
									w[nn].l+=cantidad;
									v[nn].l-=cantidad;
									
								
									
									if (w[nn].l==1)
									{
										if (co=='p'|| co=='P')
										printf("\nHa elegido %d pantal\242n de talla %c.", w[nn].l, talla);
										else
										printf("\nHa elegido %d %s de talla %c.", w[nn].l, pd, talla);
									}
									
									else
									{
										if (co=='p'|| co=='P')
										printf("\nHa elegido %d %ses  de talla %c.", w[nn].l, pd, talla);
										else
										printf("\nHa elegido %d %ss de talla %c.", w[nn].l, pd, talla);
									}
									
									
									
									w0=w[0].s+w[0].m+w[0].l;
									w1=w[1].s+w[1].m+w[1].l;
									w2=w[2].s+w[2].m+w[2].l;
									printf("\n\nLleva en su cesta: \n\t%d camiseta/s \n\t%d pantal\242n/es  \n\t%d sudadera/s.", w0, w1, w2);
								
									ticket+=precio*cantidad;
									printf ("\n\nTotal de la cesta:  %.2f$", ticket);
															
									}
									}
								}
								else
									printf ("Talla incorrecta.");	
						
						
							}
							else
							puts ("\n Opci\242n err\242nea.");		
				
					
				
				
				printf ("\n\250Desea coger otro art\241culo?\n");
				scanf ("%c", &mascom);
				fflush (stdin);				
	
		
				}while (mascom != 'n' && mascom != 'N');
				

free (pd);	
					
if (ticket!=0)
{
		
				printf ("\nLleva usted:\n");					
					
					ticketfinal(w0, w1, w2, camiseta, pantalon, sudadera);
					
					ivas=ticket*iva;
					printf ("\nIVA(21%%):\t\t\t    +%.2f$",ivas);		
					ticket=ticket+ticket*iva;
					printf ("\n\nTOTAL:\t\t\t\t%.2f$", ticket);
					

//SOCIO
printf ("\n\n\250Eres socio de la tienda? S/N\n");
scanf ("%c", &socio);	
fflush (stdin);		

switch (socio)	
{
	case 'S':
	case 's':
		
		
//CODIGO PARA LEER LOS SOCIOS
		cargardimension(&dimension);
		
		//Se pone el tamaño del vector
		u=malloc(dimension*sizeof(socia));
					
		cargarsocios(dimension, u);								

				
								do{
									annadir=0; //Reseteamos valor anadir para el futuro for
									
									printf("\nIntroduzca su nombre:\n");
									gets(y[0].nombre);
									fflush (stdin);
									printf("\nIntroduzca su apellido:\n");
									gets(y[0].apellido);
									fflush (stdin);							
															
									printf("\nIntroduzca un c\242digo:\n");
									scanf("%d", &y[0].codigo);
									fflush (stdin);
								
															
								//Comparar
								for (a=0; a<dimension; a++)
								{
								orden = strcmp(u[a].nombre, y[0].nombre);	
									if (orden == 0)
										{
										orden = strcmp(u[a].apellido, y[0].apellido);	
										if (orden == 0)
										{								
											//  printf ("\nUsuario correcto");																					
											if (u[a].codigo == y[0].codigo)
											{
											//	printf ("\nContrase\244a correcta");	
												annadir+=1;													
											}
											else
											{
											//	printf ("\nContrase\244a incorrecta");																																			
											}
										}
										else 
										{								
											//	printf ("\nUsuario incorrecto");										
										}							
										}									
								}
								
										
								
								if (annadir ==0)
								{				
								printf("\nEl usuario o la contraseña es incorrecta.");				
								printf("\n\250Desea intentarlo otra vez?\n");							
								scanf ("%c", &intento);
								fflush (stdin);
								}
								else
								{								
									intento ='n';
									
									descuentos(w0, w1, w2, camiseta, pantalon, sudadera, ivas, descuento, ticket);						
								}
									
									
								}while	(intento != 'n' && intento != 'N');																	
					
		free (u);
			
		break;
		
	case 'N':
	case 'n':
	
	printf ("\n\250Desea hacerse socio? S/N  \n");
		scanf ("%c", &nuevosocio);
		fflush (stdin);
			if(nuevosocio == 's' || nuevosocio == 'S')
				{
				
				
					//CODIGO PARA LEER LOS SOCIOS
														
									cargardimension(&dimension);
									
									//Se pone el tamaño del vector
									dimen=dimension+1;
									u=malloc(dimen*sizeof(socia));	
										
															
									cargarsocios(dimension, u);	
																										
					
					//CODIGO PARA INTRODUCIR SOCIO				
									
						pf=fopen("socios.txt","w");	
								dimension+=1;

								
								do{
									anadir=0; //Reseteamos valor anadir para el futuro for
									
									printf("\nIntroduzca su nombre:\n");
									gets(u[dimension-1].nombre);
									fflush (stdin);
									printf("\nIntroduzca su apellido:\n");
									gets(u[dimension-1].apellido);
									fflush (stdin);
								
								
															
								//Comparar
								for (a=0; a<dimension-1; a++)
								{
								orden = strcmp(u[a].nombre, u[dimension-1].nombre);	
									if (orden == 0)
										{
										orden = strcmp(u[a].apellido, u[dimension-1].apellido);	
										if (orden == 0)
											anadir+=1;
								
										}
								}				
										
								
								if (anadir !=0)
								{
								printf("\nLo sentimos pero ya existe ese socio.");
								printf("\n\250Desea intentarlo otra vez?\n");
								scanf ("%c", &intento);
								fflush (stdin);
								}
								else
								{								
									intento ='n';									
									
															
									printf("\nIntroduzca un c\242digo:\n");
									do{
										printf ("Recuerde que el n\243mero debe tener cuatro cifras.\n");
										scanf("%d", &u[dimension-1].codigo);
										fflush (stdin);
									}while (u[dimension-1].codigo <= 999 || u[dimension-1].codigo >= 10000);
																		
													
									descuentos(w0, w1, w2, camiseta, pantalon, sudadera, ivas, descuento, ticket);
	
									
//Guardar socios añadidos									
guardarsocios(dimension, u);
						
								}		
									
								}while	(intento != 'n' && intento != 'N');	
																														
						fclose(pf);
						free (u);
					}
			
			
			else 
				printf ("\nDe acuerdo.");
			
				
		break;
		
		
	default:
			puts ("\n Opci\242n err\242nea.");
}


					//Forma de pago
					
					printf("\n\n\n\250C\242mo desea pagar?\n");
					printf("\tE- En efectivo\n");
					printf("\tT- Con tarjeta de cr\202dito\n");
				
				
				
					do
					{
					
					scanf("%c", &pago);
					fflush (stdin);
					
					if (pago != 'E'&& pago != 'e' && pago != 'T' && pago != 't')
					{					
						printf ("\nOpci\242n incorrecta.");
						printf ("\nIntentelo otra vez.\n");
					}
					
					}while (pago != 'E'&& pago != 'e' && pago != 'T' && pago != 't');
					
						switch (pago)
						{
							case 'E':
							case 'e':
								if(ticket>dinero)
								{
									printf ("\nLleva usted %.2f$", dinero);
									printf ("\nLo sentimos pero no puede llevarse la/s prenda/s.");
											for (i=0; i<A; i++)
											{
											v[i].s+=w[i].s;
											v[i].m+=w[i].m;
											v[i].l+=w[i].l;
											}
										
								}
								else
								{
									dinero-=ticket;
									printf ("\nAhora tienes %.2f$ - %.2f$ = %.2f$ en efectivo.", dinero+ticket, ticket, dinero);
									
									printf ("\n\255Tenga un buen d\241a!");
									
								}
								break;
								
							case 'T':
							case 't':
								printf ("\nHa introducido su tarjeta, ahora teclee su n\243mero secreto:");
								printf ("\nAseg\243rese de que nadie mire su n\243mero secreto.");
								
								do{
								printf ("\nRecuerde que el n\243mero debe tener cuatro cifras.\n");
								scanf ("%d", &pin);
								fflush (stdin);
								}while (pin <= 999 || pin >= 10000);
									
								printf ("\n\255Tenga un buen d\241a!");
								break;
								
							default:
							puts ("\n Opci\242n err\242nea.");	
						}										
						
						//Guardar el stock
						guardarstock(v[0], v[1], v[2]);
}
else
{
	printf("\n\nSu compra es 0$");
	printf("\n\nEsperamos volver a verle pronto.");
}
				break;
				
		case 'S':
		case 's':
				printf ("\n\255Tenga un buen d\241a!");
				break;
		
		
		default:
			puts ("\n Opci\242n err\242nea.");
	}
	
	
//No tiene sentido pedir si quieres realizar otra operacion si ya has dicho que quieres salir de la tienda	
if (opcion != 's' && opcion != 'S')
{
printf ("\n\n\250Desea realizar otra operaci\242n en la tienda?\n");
scanf ("%c", &masmas);
fflush (stdin);	
}
else
masmas='n';

}while (masmas != 'n' && masmas != 'N');	



printf ("\n\n\250Desea volver a la tienda?\n");
scanf ("%c", &volver);
fflush (stdin);

if(volver== 'n' || volver=='N')
	{
	
	printf("\n\nValore su experiencia en nuestra tienda.");
	
			printf ("\nDebe ser un n\243mero del 1 al 10.\n");
		
			scanf ("%f",&valoracion);
			fflush (stdin);

		
	if (valoracion<0)
		printf ("\nNo aceptamos cr\241ticas negativas.\n");
	else if (valoracion<5)
		printf ("\nGracias por su valoraci\242n. Intentaremos mejorar.\n");	
	else if (valoracion<9)
		printf ("\nGracias por su valoraci\242n.\n");
	else if (valoracion<11)
		printf ("\nGracias por su valoraci\242n. Nos alegra que este satisfecho con nuestros servicios.\n");
	else 
		printf ("\nNos enorgullece saberlo. Gracias.\n");
	
	}
}while (volver != 'n' && volver != 'N');

	free (v);
	free (w);
	free (y);
	
	
}



void banner()
{
//Variables para el Banner	
char z1[]= "             XXXXX  XXXXX   XXXXX   XXXXX   XXXXX";
char z2[]= "                X   X   X   X   X   X   X   X   X";
char z3[]= "               X    XXXXX   XXXXX   XXXXX   XXXXX";
char z4[]= "              X     X   X   X  X    X  X    X   X";
char z5[]= "             XXXX   X   X   X   X   X   X   X   X";
	
int longitud;
	int b;
	

	
	printf ("\n\n BIENVENIDO A:\n\n\n");
	
//Banner
	longitud= strlen(z1);
						for (b=0;b<longitud;b++)
						{
							printf("%c", z1[b]);
						}
						printf("\n");
						for (b=0;b<longitud;b++)
						{
							printf("%c", z2[b]);
						}
						printf("\n");
						for (b=0;b<longitud;b++)
						{
							printf("%c", z3[b]);
						}
						printf("\n");
						for (b=0;b<longitud;b++)
						{
							printf("%c", z4[b]);
						}
						printf("\n");
						for (b=0;b<longitud;b++)
						{
							printf("%c", z5[b]);
						}
						printf("  S.A");
						printf("\n");	
}

void ticketfinal(int g0, int g1, int g2, float x, float y, float z)
{
											if (g0 != 0)
												printf ("\n%d camiseta/s\t\t\t%d x %.2f$", g0, g0, x);
											if (g1 != 0)
												printf ("\n%d pantal\242n/es\t\t\t%d x %.2f$", g1, g1, y);
											if (g2 != 0)
												printf ("\n%d sudadera/s\t\t\t%d x %.2f$", g2, g2, z);	
}


void descuentos(int f0, int f1, int f2, float x, float y, float z, float a, float b, float c)
{
printf ("\n\n\n\nSe le ha aplicado un descuento del 15%%:");
									printf ("\nSu ticket es ahora de:");
					
									ticketfinal(f0, f1, f2, x, y, z);
									
									printf ("\nIVA(21%%):\t\t\t    +%.2f$", a);			
									printf ("\nDescuento:\t\t\t    -%.2f$", c*b);
									printf ("\n\nTOTAL:\t\t\t\t    %.2f$", c-c*b);
}


char opciones()
{
	char op;
				printf ("\tC - Camiseta (9.99$)\n");
				printf ("\tP - Pantal\242n (24.99$)\n");
				printf ("\tS - Sudadera (29.99$)\n");
				scanf ("%c", &op);
				fflush (stdin);	
	return op;
}



int cargarstock(ropa* v0, ropa* v1, ropa* v2)
{	
FILE *pf;
int i;

	pf=fopen("stock.txt", "rb");

					
				if (pf==NULL)
				{
				perror("stock.txt");
				return;
				}


fread(v0, sizeof(ropa), 1,  pf);
/*
printf("Camiseta S: %d\n", v0.s);
printf("Camiseta M: %d\n", v0.m);
printf("Camiseta L: %d\n", v0.l);
*/
fread(v1, sizeof(ropa), 1, pf);
/*
printf("Pantalon S: %d\n", v1.s);
printf("Pantalon M: %d\n", v1.m);
printf("Pantalon L: %d\n", v1.l);
*/
fread(v2, sizeof(ropa), 1, pf);
/*
printf("Sudadera S: %d\n", v2.s);
printf("Sudadera M: %d\n", v2.m);
printf("Sudadera L: %d\n", v2.l);
*/

				
				if (ferror(pf))
				{
				perror("Error de lectura");
				clearerr(pf);
				}
				//else
				//printf("Lectura correcta");


fclose(pf);	
}


void guardarstock(ropa v0, ropa v1, ropa v2)
{
	FILE *pf;
	pf=fopen("stock.txt", "wb");
								fwrite(&v0, sizeof(ropa), 1, pf);
								fflush(stdin);

								fwrite(&v1, sizeof(ropa), 1, pf); 
								fflush(stdin);
								
								fwrite(&v2, sizeof(ropa), 1, pf); 
								fflush(stdin);
	
								fclose(pf);
	
}


void cargardimension(int *p)
{
FILE *pf;
pf=fopen("sociod.txt", "r");

		
		if (pf==NULL)
		{
		perror("sociod.txt");
		return;
		}


fscanf(pf,"%d", p);

	
		if (ferror(pf))
		{
		perror("Error de lectura");
		clearerr(pf);
		}
		//else
		//printf("Lectura correcta");


fclose(pf);
}


float cargarsocios(int a, socia *u)
{
FILE *pf;
int i;
			
pf=fopen("socios.txt", "rb");

		if (pf==NULL)
		{
		perror("socios.txt");
		return;
		}

for (i=0; i<a; i++)
{
fread((u+i), sizeof(socia), 1, pf);

//printf("Nombre: %s.\n", *(u+i).nombre);
//printf("Apellido: %s.\n", *(u+i).apellido);
//printf("Codigo: %d.\n", *(u+i).codigo);
}

		if (ferror(pf))
		{
		perror("Error de lectura");
		clearerr(pf);
		}
		//else
		//printf("Lectura correcta");

fclose(pf);		
	
}


void guardarsocios(int a, socia *u)
{
FILE *pf;
int i;
																	
pf=fopen("sociod.txt", "w");
fprintf(pf, "%d", a);
fclose(pf);


pf=fopen("socios.txt", "wb");
for (i=0; i<a; i++)
{
		fwrite((u+i), sizeof(socia), 1, pf);
}
fclose(pf);

}



