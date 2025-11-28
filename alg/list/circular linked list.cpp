#include <stdio.h>
#include <stdlib.h>



struct nohStruct {
	int valor;
	struct nohStruct *prox;
};

typedef struct nohStruct noh;





void criarNoh(noh *inicio, int valor){
	noh *novoNoh = (noh*)malloc(sizeof(noh));  // com *
	
	novoNoh->prox = inicio;  //circular
	novoNoh->valor = valor;
	
	
	
	noh *ateUltimoNoh = inicio;
	while (ateUltimoNoh->prox != inicio){
		ateUltimoNoh = ateUltimoNoh->prox;
		
	}
	
	ateUltimoNoh->prox = novoNoh;
}






void liberar(noh *inicio){
	noh *seletorDeNoh = inicio->prox;   // com *
	noh *aLiberar;                      //os dois pra stack	
	
	while(seletorDeNoh->prox != inicio){
		aLiberar = seletorDeNoh;
		seletorDeNoh = seletorDeNoh->prox;
		free(aLiberar);
	}
	
	
	aLiberar = seletorDeNoh;  //soh pra liberar o ultimo noh
	free(aLiberar);
}







int main(){
	noh inicio;   // sem *
	inicio.prox = NULL;
	
	
	criarNoh(&inicio, 1);
	liberar(&inicio);
}
