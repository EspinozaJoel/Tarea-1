#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Libro
{
	char *titulo;
	int anioDePublicacion;
	struct Libro *next;
};

void crear_nodo (struct Libro **lista)
{
	char titulo[64];
	printf("Titulo:  ");
	scanf("%s", titulo);
	
	struct Libro *libro = malloc(sizeof(struct Libro));
	libro->titulo = malloc(strlen(titulo)+1);
	strcpy(libro->titulo, titulo);
	
	printf("Anio:  ");
	scanf("%d", &libro->anioDePublicacion);
	
	libro->next = NULL;
	
	
	if ((*lista) == NULL)
	{
		(*lista) = libro;
	}
	else
	{
		struct Libro *actual;
		actual = (*lista);
		while (actual->next != NULL)
		{
			actual = actual->next;
		}
		actual->next = libro;
	}
}


int main (int argc, char *argv[])

{
	struct Libro *lista = NULL;
	
	crear_nodo(&lista);
	
	printf("\ntitulo: %s", lista->titulo);
	printf("\nanio %d", lista->anioDePublicacion);
	
	return 0;
}
