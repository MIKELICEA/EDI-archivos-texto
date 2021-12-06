#include <stdio.h>
#define M 100

int main()
{
    FILE *archivo;
    int cerrado;
    int calif;
    char alumno[50];
    int pudoleer;
    int alumnos;
    int arr[M];
    int promedio = 0;
    int promediofinal;
    int j = 1;


    archivo = fopen("ejemplo4.txt", "w"); //Si el archivo no existe y lo intento abrir con r, me regresa null

    printf("¿Cuántos alumnos quieres insertar?: ");
    scanf("%d", &alumnos);

    for(int i = 1; i <= alumnos; i++)
    {
        printf("Dame el nombre del alumno número %d: ", i);
        scanf("%s", alumno);

        printf("Dame la calificacion: ");
        scanf("%d", &calif);

        fprintf(archivo, "%s %d\n", alumno, calif);
    }

    cerrado = fclose(archivo);

    archivo = fopen("ejemplo4.txt", "r"); //Siempre crea el archivo

   do
   {
       fscanf(archivo, "%s", alumno);
       pudoleer = fscanf(archivo, "%d", &calif);

       arr[j] = calif;
       j++;

   }while(pudoleer != EOF && j <= alumnos);


   cerrado = fclose(archivo);

   for(int k = 1; k <= alumnos; k++)
   {
       promedio = promedio + arr[k];
   }

   promediofinal = promedio/alumnos;

   printf("\nEl promedio de los alumnos es: %d\n", promediofinal);

    if(cerrado == EOF) //fclose regresa EOF cuando no se puede cerrar correctamente 
    {
        printf("El archivo no se cerró bien");
    }
    return 0;
}