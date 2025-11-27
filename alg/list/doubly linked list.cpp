#include <stdio.h>
#include <stdlib.h>



struct nohStruct {
	int valor;
	struct nohStruct *prox;
	struct nohStruct *prev;
};

typedef struct nohStruct noh;




void novoNoh(noh *inicio, int valor){
	noh *nohEmCriacao = (noh*)malloc(sizeof(noh));
	
	nohEmCriacao->prox = NULL;
	nohEmCriacao->valor = valor;
	
	
	
	noh *ateUltimoNoh = inicio;
	
	while (ateUltimoNoh->prox != NULL){   // busca ultimo noh para organizar os ponteiros da struct
		ateUltimoNoh = ateUltimoNoh->prox;
	} 
	
	
	ateUltimoNoh->prox = nohEmCriacao;
	nohEmCriacao->prev = ateUltimoNoh;
}




void liberar(noh *inicio){
	noh *seletorDeNoh = inicio->prox; // primeiro da heap
	noh *aLiberar; 
	
	while (seletorDeNoh != NULL){
		aLiberar = seletorDeNoh;
		seletorDeNoh = seletorDeNoh->prox;
		free(aLiberar);  
	}
	
}





int main(){
	noh *inicio;  //stack
	inicio.prev = NULL;
	inicio.prox = NULL;
	
	novoNoh(&inicio, int 1);
	liberar(&inicio);
	
	return 0;	
}
