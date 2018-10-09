/*--------------- File: Heap_Sort.c  -------------------+
|Implementacao do Algoritmo Heap_Sort 						|
|					      									|
|					      									|
| Implementado por Luigi Miranda e Tiemy Shibuya 		    |
|   em 06/10/2018     									   |
+-------------------------------------------------------+ */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//HeapFy que executara a heap maxima do vetor
void heapfy(int *elements, int n, int i){
    int maior = i,temp;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    if(esquerda < n && elements[esquerda] > elements[maior] ){
         maior = esquerda;
    }
    if(direita < n && elements[direita] > elements[maior]){
        maior = direita;
    }
    if(maior != i)
    {
        temp = elements[i];
        elements[i] = elements[maior];
        elements[maior] = temp;

        heapfy(elements,n,maior);
    }
}
//algoritmo heapsort de ordenação em ordem crescente
void heapsort(int *elements,int n){
    int i,temp;
    for(i = n/2-1;i >= 0;i--){
        heapfy(elements,n,i);
    }
    for(i = n-1;i>=0;i--){
        temp = elements[0];
        elements[0] = elements[i];
        elements[i] = temp; 

        heapfy(elements,i,0);
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
	FILE *heap;
	clock_t tempo;
	float dura;
	char string[20];
	heap = fopen("Heap_Sort_Final.txt", "w");
	int i = 10, j = 0, k = 7;
	//int j = 0;
	//vai executar todas as entradas e armazenar o tempo em segundos num arquivo txt
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
			heapsort(prt, i);
			/*for(j = 0; j < i; j++){
	       		printf("%d ", prt[j]);
		   	}*/
		   	//printf("\n ");
		   	if(k == 7){
		   		strcpy(string, "Aleatorio");
			}else if(k == 8){
		   		strcpy(string, "Crescente");
			}else if(k == 9){
		   		strcpy(string, "Decrescente");
			}
			dura = (clock() - tempo) / (double)CLOCKS_PER_SEC;
			fprintf(heap, "Tempo do %s com %d: %f\n", string, i, dura);
			free(prt);
		}
		printf("Sucesso! \n");
	}		
	fclose(heap);
	return 0;
}
