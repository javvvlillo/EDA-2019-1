#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#define LENGHT 7
#define TEST_COUNT 4

int BUSCA_LIN(int *A,int k,bool comp);
int BUSCA_BIN(int *A,int k,bool comp);
void test();
void menu();

int main()
{
    int input;
    while(true){
        menu();
        scanf("%d", &input);
        if (input==1){
            test();
        }
        else if (input==0)
        {
            break;
        }
        
    }
   return 0;
}

int BUSCA_LIN(int *A,int k,bool comp){
    /*
    Busqueda lineal de un número en un arreglo.
    A: Arreglo de números
    k: número entero a buscar
    comp: booleano de comparaciones
    Returns: if comp == True =>  Número de comparaciones
             if comp == False => Posición arreglo 
    */


    int contador_comparacion,pos;
    pos=-1; contador_comparacion=0;

    for(int i = 0; i < LENGHT; i++)
    {
        contador_comparacion++;
        if(A[i]==k){
            pos = i;
            break;
        }
    }
    if(comp){
        return contador_comparacion;
    }
    else{
        return pos;
    }
}
int BUSCA_BIN(int *A,int k,bool comp){
      /*
    Busqueda binaria de un número en un arreglo.
    A: Arreglo de números
    k: número entero a buscar
    comp: booleano de comparaciones
    Returns: if comp == True =>  Número de comparaciones
             if comp == False => Posición arreglo
    */

    int final = LENGHT - 1; 
    int  contador_Comporaciones,pos,inicio;
    contador_Comporaciones=0; pos=-1; inicio=0;

    while(inicio <= final){
        contador_Comporaciones++;
        int mitad = (inicio + final)/2;
            if(A[mitad]==k){
                pos=mitad;
                break;
            }
            else if (A[mitad]<k)
            {
                inicio= mitad + 1;
            }
            else{
                final=mitad-1;
            }
    }
    if (comp) {return contador_Comporaciones;};
    return pos;
            
}

void menu(){
    printf("##########  Tarea 1 ################\n");
    printf("Elige una de las siguientes soluciones: \n");
    printf("Ingresa 1 Si quieres probar todos los casos de correción\n");
    printf("Ingresa 0 Si quieres salir\n");
}
void test(){

    int a_buscar[]={1,3,5,7};
    int contador;
    char ch;
    bool skip=false;
    int array[LENGHT];
    char file_Name[20];

    for(int i = 1; i < TEST_COUNT+1; i++)
    {
        sprintf(file_Name,"test%d.txt",i);
        printf("%s",file_Name);
        FILE * file = fopen (file_Name, "r");
        contador=0;
        printf ("  El contenido del arreglo es:");
        while( (ch = getc(file)) != EOF) {
            skip=false;
            if (ch==13 || ch==10) {
                skip=true;
            }
            if (!skip) {
                int num = atoi(&ch);
                array[contador]=num;
                contador++;
                printf("%d",num);
            }
        }
        printf("\n -------- BUSQUEDA LINEAL --------\n");
        for(size_t j = 0; j < TEST_COUNT; j++)
        {
            printf("Cantidad de comparaciones caso k=%d: %d\n",a_buscar[j], BUSCA_LIN(array, a_buscar[j], true));
            printf("Posición del entero caso k=%d: %d\n\n",a_buscar[j], BUSCA_LIN(array, a_buscar[j], false));
        }
        printf(" -------- BUSQUEDA BIN --------\n");
        for(size_t k = 0; k < TEST_COUNT; k++)
        {
            printf("Cantidad de comparaciones caso k=%d: %d\n",a_buscar[k], BUSCA_BIN(array, a_buscar[k], true));
            printf("Posición del entero caso k=%d: %d\n\n",a_buscar[k], BUSCA_BIN(array, a_buscar[k], false));
        }
        
        for(size_t m = 0; m < LENGHT; m++)
        {
            array[m]=0;
        }   
        fclose(file);
    }
}