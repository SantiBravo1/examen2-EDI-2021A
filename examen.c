#include <stdio.h>
#define N 3
#define M 2
#define C 15

void capturaArreglos(int arr1[N], char nom[C], float ES[N][M]);
float buscaMasAlto(float EsSu[N], int *renglon, int *columna);
void burbuja(float ESTSUE[N][M]);
void imprimirDatos(int arrcl, char n, float es[N][M]);

int main()
{
    int arrclave[N];
    char nombre[C];
    float EstSue[N][M];
    int ren, col;
    float mayor;

    capturaArreglos(arrclave, nombre, EstSue);

    mayor=buscaMasAlto(EstSue, &ren, &col);
    printf("La persona mas alta se encuentra en la posicion[%d][%d]", ren, col);

    imprimirDatos(arrclave, nombre, EstSue);
    return 0;
}

void capturaArreglos(int arr1[N], char nom[C], float ES[N][M])
{
    int i, j;

    for(i=0; i<N; i++)
    {
        printf("Clave[%d]: ", i);
        scanf("%d", &arr1[i]);
    }
    for(i=0; i<N; i++)
    {
        printf("Nombre[%d]: ", i);
        scanf("%s", nom);
        fflush(stdin);
    }
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            printf("Estatura y sueldo[%d][%d]: ", i, j);
            scanf("%f", &ES[i][j]);
        }
    }
}
float buscaMasAlto(float EsSu[N][M], int *renglon, int *columna)
{
    int ren, col;
    float mayor=EsSu[0][0];
    for(ren=0; ren<N; ren++)
    {
        for(col=0; col<M; col++)
        {
            if(EsSu[ren][col]>mayor)
            {
                mayor=EsSu[ren][col];
                *renglon=ren;
                *columna=col;
            }
        }
    }
    return mayor;
}

void burbuja(float ESTSUE[N][M])
{
    int i, j;
    float aux;
    for(j=0; j<N-1; j++)
    {
        for(i=0; i<N-(j+1); i++)
        {
            if(ESTSUE[i]>ESTSUE[i+1])
            {
                aux=ESTSUE[i+1];
                ESTSUE[i+1]=ESTSUE[i];
                ESTSUE[i]=aux;
            }
        }
    }
}

void imprimirDatos(int arrcl, char n, float es[N][M])
{
    int i, j;
    printf("Clave \t\ Nombre \t\ Estatura \t\ Sueldo\n");
    for(i=0; i<N; i++)
    {
        printf("%d\n", &arrcl[i]);
    }
    printf("\t");
    for(i=0; i<N; i++)
    {
        printf("%s\n", n);
    }
    printf("\t");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            {
              printf("%f\n", &es[i][j]);
            }
    }
    printf("\t");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            {
              printf("%f\n", &es[j][i]);
            }
    }
    printf("\t");
}
