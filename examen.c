#include <stdio.h>
#include <string.h>

#define N 3

void captura(int clave[N], char nombre[N][20], float datos[N][2]);
int buscaMasAlto(float info[N][2]);
void ordenaSueldos(int clave[N], char nombre[N][20], float datos[N][2]);
void imprimirTabla(int clave[N], char nombre[N][20], float datos[N][2]);

int main()
{
    int clave[N];
    char nombre[N][20];
    float datos[N][2];

    int posicionMasAlta;
    
    captura(clave, nombre, datos);

    ordenaSueldos(clave, nombre, datos);

    imprimirTabla(clave, nombre, datos);
    
    posicionMasAlta=buscaMasAlto(datos);

    printf("El Nombre del empleado mas alto es: %s", nombre[posicionMasAlta]);
    printf("Y su estatura es: %f", datos[posicionMasAlta][0]);

    return 0;
}

void captura(int clave[N], char nombre[N][20], float datos[N][2])
{
    int empleado;

    for(empleado=0; empleado<N; empleado++)
    {
        printf("Clave[%d]: ", empleado);
        scanf("%d", &clave[empleado]);

        printf("Nombre[%d]: ", empleado);
        scanf("%s", nombre[empleado]);

        printf("Estatura[%d]: ", empleado);
        scanf("%f", &datos[empleado][0]);

        printf("Sueldo[%d]: ", empleado);
        scanf("%f", &datos[empleado][1]);
    }
}

int buscaMasAlto(float info[N][2])
{
    int empleado;
    float Alto=info[0][0];
    int posicion=0;

    for(empleado=0; empleado<N; empleado++)
    {
        if(info[empleado][0]>Alto)
        {
           Alto=info[empleado][0];
           posicion=empleado;
        }
    } 
    return posicion;
}

void ordenaSueldos(int clave[N], char nombre[N][20], float datos[N][2])
{
    int i, j;
    float aux;
    int auxCl;
    char auxNom[20];

    for(i=0; i<N-1; i++)
    {
        for(j=0; j<N-1; j++)
        {
           if(datos[j][1]<datos[j+1][1])
           {
               aux=datos[j][1];
               datos[j][1]=datos[j+1][1];
               datos[j+1][1]=aux;

               aux=datos[j][0];
               datos[j][0]=datos[j+1][0];
               datos[j+1][0]=aux;
               
               auxCl=clave[j];
               clave[j]=clave[j+1];
               clave[j+1]=auxCl;

               strcpy(auxNom, nombre[j]);
               strcpy(nombre[j], nombre[j+1]);
               strcpy(nombre[j+1], auxNom);
           }
        }
    }
}

void imprimirTabla(int clave[N], char nombre[N][20], float datos[N][2])
{
    int empleado;

    printf("Clave    Nombre    Estatura   Sueldo\n");

    for(empleado=0; empleado<N; empleado++)
    {
       printf("%d\t", clave[empleado]);
       printf("%s\t", nombre[empleado]);
       printf("%f\t", datos[empleado][0]);
       printf("%f\n", datos[empleado][1]);
    }
}