/*--------------- File: Select_Sort.c  -------------------+
|Implementacao do Algoritmo Select_Sort 						|
|					      									|
|					      									|
| Implementado por Luigi Miranda e Tiemy Shibuya 		    |
|   em 06/10/2018     									   |
+-------------------------------------------------------+ */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void selection_sort(int* elements,int tam){
           int i,j,k;
           int min;
           for(i=0;i<tam;i++)
           {
               min = i;
           for(j= i+1;j<=tam-1;j++)
           {
              if(elements[min] > elements[j])
              {
                  min = j;
              }
           }

           int temp = elements[i];
           elements[i] = elements[min];
           elements[min] = temp;
           //printf("%i\n",elements[i]);
           }
}

void vetor(int x,int y, int v[]){
	FILE *file;
	int a;
	if(x==10 && y==7)
	{ 
		
		file = fopen("Aleatorio10.txt","r");
		
	}
	else if(x==1000 && y==7)
	{
		file = fopen("Aleatorio1000.txt","r");

	}
	else if(x==10000 && y==7)
	{
		file = fopen("Aleatorio10000.txt","r");

	}
	else if(x==100000 && y==7)
	{
		file = fopen("Aleatorio100000.txt","r");

	}
	else if(x==1000000 && y==7)
	{
		file = fopen("Aleatorio1000000.txt","r");

	}
	else if(x==10 && y==8)
	{
		file = fopen("Crescente10.txt","r");
		
	}
	else if(x==1000 && y==8)
	{
		file = fopen("Crescente1000.txt","r");

	}
	else if(x==10000 && y==8)
	{
		file = fopen("Crescente10000.txt","r");

	}
	else if(x==100000 && y==8)
	{
		file = fopen("Crescente100000.txt","r");

	}
	else if(x==1000000 && y==8)
	{
		file = fopen("Crescente1000000.txt","r");

	}
	else if(x==10 && y==9)
	{
		file = fopen("Decrescente10.txt","r");
		
	}
	else if(x==1000 && y==9)
	{
		file = fopen("Decrescente1000.txt","r");

	}
	else if(x==10000 && y==9)
	{
		file = fopen("Decrescente10000.txt","r");

	}
	else if(x==100000 && y==9)
	{
		file = fopen("Decrescente100000.txt","r");

	}
	else if(x==1000000 && y==9)
	{
		file = fopen("Decrescente1000000.txt","r");

	}
	
	int n = 0;
    if(file==NULL)
	{
        printf("Erro ao abrir o arquivo.\n");
        
    } 
   
    for (n = 0; n < x; n++){
			fscanf(file,"%d\n", &a);
			v[n]=a;
		}
	
    fclose(file);

}

int main(){
	FILE *select;
	clock_t tempo;
	float dura;
	char string[20];
	select = fopen("Select_Sort_Final.txt", "w");
	int i = 10, k = 7;
	//int j = 0;
	for(k = 7; k < 1000000; k++){
		printf("Com %d: ", k);
		for(i = 10; i <= 1000; i=i*10){
			if(i == 100){
				i = i*10;
			}
			int *prt;	
			prt = (int*)malloc(i*sizeof(int));
			tempo = clock();
			vetor(i, k, prt);
			selection_sort(prt, i);
			/*for(j = 0; j < i; j++){
				printf("%d ", prt[j]);
			}
			printf("\n");*/
			if(k == 7){
		   		strcpy(string, "Aleatorio");
			}else if(k == 8){
		   		strcpy(string, "Crescente");
			}else if(k == 9){
		   		strcpy(string, "Decrescente");
			}
			dura = (clock() - tempo) / (double)CLOCKS_PER_SEC;
			fprintf(select, "Tempo do %s com %d: %f\n", string, i, dura);
			free(prt);
		}
		printf("Sucesso!\n");
	}
	fclose(select);	
	return 0;
}
