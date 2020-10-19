#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;

void mostrar(eNotebook lista[], int tam);
void ordenar(eNotebook lista[], int tam);
float aplicarDescuento(int valorProducto);
int contarCaracteres(char cadena[], char caracter);

int main()
{
    eNotebook lista[TAM] = {{1,"snapdragon","intel",300.84},{2,"ryzen","amd",400.69},{3,"snapdragon","ryzen",1000.54},{4,"pentium","intel",200}};
    int valorProducto = 300;
    char palabra[] = "pepitos";
    char letra = 'p';
    printf("el precio con descuento es: %.2f\n\n", aplicarDescuento(valorProducto));
    printf("La letra %c se encuentra repetida: %d veces\n\n", letra, contarCaracteres(palabra,letra));


    mostrar(lista,TAM);
    ordenar(lista,TAM);
    printf("Array ordenado \n\n");
    mostrar(lista,TAM);
    return 0;
}

float aplicarDescuento(int valorProducto)
{
    int porcentaje = 5;
    int descuento;
    int resultado;
    descuento = (float)valorProducto * porcentaje /100;
    resultado = valorProducto - descuento;
    return resultado;
}
int contarCaracteres(char cadena[], char caracter)
{
    int j = 0;
    int contador = 0;
    while(cadena[j] != '\0')
    {
      if(cadena[j] == caracter)
      {
          contador++;
      }
      j++;
    }
    return contador;
}


void ordenar(eNotebook lista[], int tam)
{
    int i;
    int j;
    eNotebook auxiliar;

    for(i = 0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(lista[i].marca , lista[j].marca)>0)
                    {
                        auxiliar = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxiliar;
                    }

            else
            {
                if(strcmp(lista[i].marca, lista[j].marca)==0 &&(lista[i].precio > lista[j].precio))
            {
                auxiliar = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliar;
            }
                }
            }
        }
}

void mostrar(eNotebook lista[], int tam)
{
    for(int i = 0; i<tam;i++)
    {
        printf("%d %20s %20s %.2f\n", lista[i].id,lista[i].marca,lista[i].procesador,lista[i].precio);
    }
    printf("\n\n");
}
