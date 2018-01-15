/*
 ============================================================================
 Name        : Quejamatic.c
 Author      : Madriz, Chavez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct Queja {
	char nombre[30];
	char texto[1000];
	short int genero: 2;
	unsigned short int codigoPostal: 14;
	unsigned int edad: 7;
	unsigned int id: 20;
}queja;

queja complaints[MAX];//arreglo tipo estructura

int main(void) {
	queja temporal[1];//variable temporal para ordenamiento
	int menu, ord;//menu: opción ingresada del menu principal, ord:número ordinal para mostrar queja
	char exit = 1;//Bandera para salir
	int numDir = 0;//acumulador para aumentar posición de arreglo
	int t_id, t_zp, t_age;//variables temporales para almacenar entradas
	char t_gend[10];//variable temporal para almacenar entrada
	setbuf(stdout, NULL);

	while(exit){//comienza el loop exit=true
		printf("1. Alta\n2. Despliegue\n3. Fin\n");
		scanf("%d", &menu);

		switch(menu){
		case 1:
			printf("Ingrese los datos en el orden establecido.\n");
			scanf("%i", &t_id);
			scanf("\n");//almacena caracter no leeido
			scanf("%30[^\n]",complaints[numDir].nombre);//lectura de 30 caracteres exceptuando salto de linea
			scanf("\n");
			scanf("%10[^\n]", t_gend);
			scanf("%i",&t_age);
			scanf("%i", &t_zp);
			scanf("\n");
			scanf("%1000[^\n]",complaints[numDir].texto);

			complaints[numDir].id=t_id;
			complaints[numDir].codigoPostal=t_zp;
			complaints[numDir].edad=t_age;

			//comparación unicamente con primer letra ingresada de cada género
			if(t_gend[0]=='M' || t_gend[0]=='m')
				complaints[numDir].genero = 0;
			else if(t_gend[0]=='F' || t_gend[0]=='f')
				complaints[numDir].genero = 1;
			else if(t_gend[0]=='O' || t_gend[0]=='o')
				complaints[numDir].genero = 2;

			printf("Queja #%u ingresada.\n\n", complaints[numDir].id);

			numDir++;//aumenta la posición del arreglo

			int i, j;

			//algoritmo para ordenar quejas
			for(j=1; j<=numDir-1; j++)
				for(i=0; i<numDir-1; i++)
					if(complaints[i].id > complaints[i+1].id)
					{
						temporal[0] = complaints[i];
						complaints[i] = complaints[i+1];
						complaints[i+1] = temporal[0];
					}

			break;

		case 2:
			printf("Inserte el ordinal de la queja: ");
			scanf("%i", &ord);

			printf("Queja: %u\n", complaints[ord-1].id);
			printf("Quejoso: %s\n", complaints[ord-1].nombre);

			if(complaints[ord-1].genero == 0)
				printf("Genero: MASCULINO\n");
			else if(complaints[ord-1].genero == 1)
				printf("Genero: FEMENINO\n");
			else if(complaints[ord-1].genero == 2)
				printf("Genero: OTRX\n");

			printf("Edad: %i\n", complaints[ord-1].edad);
			printf("C. postal: %i\n", complaints[ord-1].codigoPostal);
			printf("Contenido: %s\n", complaints[ord-1].texto);
			printf("\n\n");

			break;
		case 3:
			exit = 0;//exit=false
			break;
		}
	}
	return 0;
}
