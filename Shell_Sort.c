/*--------------- File: Shell_Sort.c  -------------------+
|Implementacao do Algoritmo Shell_Sort 						|
|					      									|
|					      									|
| Implementado por Luigi Miranda e Tiemy Shibuya 		    |
|   em 06/10/2018     									   |
+-------------------------------------------------------+ */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shell_sort(int *elements, int tam){
	int i , j , valor;
	int a = 1;
  	do{
		a = 3*a+1;
	}while(a < tam);
  	do{
  		a /= 3;
  		for(i = a; i < tam; i++){
   			valor = elements[i];
   			j = i - a;
    		while (j >= 0 && valor < elements[j]) {
				elements[j + a] = elements[j];
				j -= a;
			}
			elements[j + a] = valor;
   		}
  	}while(a > 1);
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
	FILE *shell;
	clock_t tempo;
	float dura;
	char string[20];
	shell = fopen("Shell_Sort_Final.txt", "w");
	int i = 10, k = 7;
	//int j = 0;
	//Vai executar cada entrada e armazenar o tempo em segundos em um arquivo txt
	for(k = 7; k < 10; k++){
		printf("Com %d: \n", k);
		for(i = 10; i <= 1000000; i=i*10){
			if(i == 100){
				i = i*10;
			}
			int *prt;	
			prt = (int*)malloc(i*sizeof(int));
			tempo = clock();
			vetor(i, k, prt);
			shell_sort(prt, i);
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
			fprintf(shell, "Tempo do %s com %d: %f\n", string, i, dura);
			free(prt);
		}
	}
	fclose(shell);	
	return 0;
}
