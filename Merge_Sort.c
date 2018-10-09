/*--------------- File: Merge_Sort.c  -------------------+
|Implementacao do Algoritmo Merge_Sort 						|
|					      									|
|					      									|
| Implementado por Luigi Miranda e Tiemy Shibuya 		    |
|   em 06/10/2018     									   |
+-------------------------------------------------------+ */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

//Função com intuito de preencher o vetor com o tamanho necessário
//7 = Aleatorio; 8 = Crescente; 9 = Decrescente
void vetor(int x,int y, int v[]){
	FILE *file;
	int a;
	//Abre o arquivo aleatorio com 10 elementos
	if(x==10 && y==7){		
		file = fopen("Aleatorio10.txt","r");
	}
	//Abre o arquivo aleatorio com 1000 elementos
	else if(x==1000 && y==7){
		file = fopen("Aleatorio1000.txt","r");
	}
	//Abre o arquivo aleatorio com 10000 elementos
	else if(x==10000 && y==7){
		file = fopen("Aleatorio10000.txt","r");
	}
	//Abre o arquivo aleatorio com 100000 elementos
	else if(x==100000 && y==7){
		file = fopen("Aleatorio100000.txt","r");
	}
	//Abre o arquivo aleatorio com 1000000 elementos
	else if(x==1000000 && y==7){
		file = fopen("Aleatorio1000000.txt","r");
	}
	//Abre o arquivo crescente com 10 elementos
	else if(x==10 && y==8){
		file = fopen("Crescente10.txt","r");
	}
	//Abre o arquivo crescente com 1000 elementos
	else if(x==1000 && y==8){
		file = fopen("Crescente1000.txt","r");
	}
	//Abre o arquivo crescente com 10000 elementos
	else if(x==10000 && y==8){
		file = fopen("Crescente10000.txt","r");
	}
	//Abre o arquivo crescente com 100000 elementos
	else if(x==100000 && y==8){
		file = fopen("Crescente100000.txt","r");
	}
	//Abre o arquivo crescente com 1000000 elementos
	else if(x==1000000 && y==8){
		file = fopen("Crescente1000000.txt","r")
	}
	//Abre o arquivo decrescente com 10 elementos
	else if(x==10 && y==9){
		file = fopen("Decrescente10.txt","r");
	}
	//Abre o arquivo decrescente com 1000 elementos
	else if(x==1000 && y==9){
		file = fopen("Decrescente1000.txt","r");
	}
	//Abre o arquivo decrescente com 10000 elementos
	else if(x==10000 && y==9){
		file = fopen("Decrescente10000.txt","r");
	}
	//Abre o arquivo decrescente com 100000 elementos
	else if(x==100000 && y==9){
		file = fopen("Decrescente100000.txt","r");
	}
	//Abre o arquivo decrescente com 1000000 elementos
	else if(x==1000000 && y==9){
		file = fopen("Decrescente1000000.txt","r");
	}
	
	int n = 0;
	//Caso nao tenha espaço para armazenar
	if(file==NULL){
        	printf("Erro ao abrir o arquivo.\n");
	} 
	//Lê o arquivo e armazena no vetor
   	for (n = 0; n < x; n++){
		fscanf(file,"%d\n", &a);
		v[n]=a;
	}
	fclose(file);
}

int main(){
	FILE *merge;
	clock_t tempo;
	float dura;
	char string[20];
	merge = fopen("Merge_Sort_Final.txt", "w");
	int i = 10, k = 7;
	//int j = 0;
	//Vai executar cada entrada e armazenar o tempo em segundos num arquivo txt
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
			mergeSort(prt, 0, i-1);
			/*for(j = 0; j < i; j++){
	       		printf("%d ", prt[j]);
		   	}
			printf("\n ");*/
			if(k == 7){
		   		strcpy(string, "Aleatorio");
			}else if(k == 8){
		   		strcpy(string, "Crescente");
			}else if(k == 9){
		   		strcpy(string, "Decrescente");
			}
			dura = (clock() - tempo) / (double)CLOCKS_PER_SEC;
			fprintf(merge, "Tempo do %s com %d: %f\n", string, i, dura);
			free(prt);
		}
		printf("Sucesso! \n");
	}		
	fclose(merge);
	return 0;
}
