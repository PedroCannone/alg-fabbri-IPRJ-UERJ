#include <stdio.h>
#include <stdlib.h>



struct nohStruct {
	int valor;
	struct nohStruct *prox;
};

typedef struct nohStruct noh;





void criarNoh(noh *inicio, int valor){
	noh *novoNoh = (noh*)malloc(sizeof(noh));
	
	novoNoh->prox = inicio;  //circular
	novoNoh->valor = valor;
	
	
	
	noh *ateUltimoNoh = inicio;
	while (ateUltimoNoh->prox != NULL){
		ateUltimoNoh = ateUltimoNoh->prox;
		
	}
	
	ateUltimoNoh->prox = novoNoh;
}






void liberar(noh *inicio){
	noh *seletorDeNoh = inicio->prox;
	noh *aLiberar;                      //os dois pra stack	
	
	while(seletorDeNoh != NULL){
		aLiberar = seletorDeNoh;
		seletorDeNoh = seletorDeNoh->prox;
		free(aLiberar);
	}
}







int main(){
	noh *inicio;
	inicio.prox = NULL;
	
	
	criarNoh(&inicio, 1);
	liberar(&inicio);
}
