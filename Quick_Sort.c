/*--------------- File: Quick_Sort.c  -------------------+
|Implementacao do Algoritmo Quick_Sort 						|
|					      									|
|					      									|
| Implementado por Luigi Miranda e Tiemy Shibuya 		    |
|   em 06/10/2018     									   |
+-------------------------------------------------------+ */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void particao(int* elements, int esq, int dir, int *i, int *j){
	int x, w;
	*i = esq;
	*j = dir;
	x = elements[(*i + *j)/2];//pivõ
	do{
		while(x > elements[*i]){
			(*i)++;
		}
		while(x < elements[*j]){
			(*j)--;
		}
		if(*i <= *j){
			w = elements[*i];
			elements[*i] = elements[*j];
			elements[*j] = w;
			(*i)++;
			(*j)--;
		}
	}while(*i <= *j);
}

void ordena(int* elements, int esq, int dir){
	int i, j;
	particao(elements, esq, dir, &i, &j);
	if(esq < j){
		ordena(elements, esq, j);
	}
	if (i < dir){
		ordena(elements, i, dir);
	}
}

void Quick_sort(int *elements, int n){
	ordena(elements, 0, n-1);
}

void vetor(int x,int y, int v[]){
	FILE *file;
	int a;
	if(x==10 && y==7){ 
		
		file = fopen("Aleatorio10.txt","r");
		
	}
	else if(x==1000 && y==7){
		file = fopen("Aleatorio1000.txt","r");

	}
	else if(x==10000 && y==7){
		file = fopen("Aleatorio10000.txt","r");

	}
	else if(x==100000 && y==7){
		file = fopen("Aleatorio100000.txt","r");

	}
	else if(x==1000000 && y==7){
		file = fopen("Aleatorio1000000.txt","r");

	}
	else if(x==10 && y==8){
		file = fopen("Crescente10.txt","r");
		
	}
	else if(x==1000 && y==8){
		file = fopen("Crescente1000.txt","r");

	}
	else if(x==10000 && y==8){
		file = fopen("Crescente10000.txt","r");

	}
	else if(x==100000 && y==8){
		file = fopen("Crescente100000.txt","r");

	}
	else if(x==1000000 && y==8){
		file = fopen("Crescente1000000.txt","r");

	}
	else if(x==10 && y==9){
		file = fopen("Decrescente10.txt","r");
		
	}
	else if(x==1000 && y==9){
		file = fopen("Decrescente1000.txt","r");

	}
	else if(x==10000 && y==9){
		file = fopen("Decrescente10000.txt","r");

	}
	else if(x==100000 && y==9){
		file = fopen("Decrescente100000.txt","r");

	}
	else if(x==1000000 && y==9){
		file = fopen("Decrescente1000000.txt","r");

	}
	
	int n = 0;
    if(file==NULL){
        printf("Erro ao abrir o arquivo.\n");
        
    } 
   
    for (n = 0; n < x; n++){
			fscanf(file,"%d\n", &a);
			v[n]=a;
		}
	
    fclose(file);

}

int main(){
	FILE *quick;
	clock_t tempo;
	float dura;
	char string[20];
	quick = fopen("Quick_Sort_Final.txt", "w");
	int i = 10, k = 7;
	//int j = 0;
	for(k = 7; k < 10; k++){
		printf("Com %d: ", k);
		for(i = 10; i <= 1000000; i=i*10){
			if(i == 100){
				i = i*10;
			}
			int *prt;	
			prt = (int*)malloc(i*sizeof(int));
			tempo = clock();
			vetor(i, k, prt);
			Quick_sort(prt, i);
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
			fprintf(quick, "Tempo do %s com %d: %f\n", string, i, dura);
			free(prt);
		}
		printf("Sucesso! \n");
	}
	fclose(quick);	
	return 0;
}
