#include <stdio.h>
#include <stdlib.h>








// montagem do struct tendo o conteudo de cada nó
struct nohConteudo {
	int valor;
	struct nohConteudo *prox; //um ponteiro chamado prox que guarda uma outra struct nohConteudo
};

//criar "noh" para ser um tipo que significa o struct nohConteudo
typedef struct nohConteudo noh;

void novoNoh (noh *inicio, int valor);
void liberar (noh *inicio);










int main(){
	
				// declarar inicio como um nó usando o data type noh que é o struct nohConteudo, ou seja, inicio guarda um valor e ponteiro prox NA STACK
	noh inicio; // sem malloc e sem o * antes do inicio, o tipo de memoria eh stack e eh eliminada rapidamente. Serve para o nó inicio porque ele é temporario e ela so termina quando o main terminar, no fim do programa
	
	inicio.prox = NULL; // ja que existe só o nó inicio, NULL quer dizer que nao tem prox ainda
	
	
	novoNoh(&inicio, 1);
	liberar(&inicio);
	
	
	return 0;
}












void novoNoh (noh *inicio, int valor){ // recebe inicio soh pra comecar do primeiro no while
	
	// memory allocation NAO USA A STACK, NAO SOME DEPOIS DA CONCLUSAO DESSA FUNCAO
	noh *nohEmCriacao = (noh*)malloc(sizeof(noh)); //ponteiro pro espaco aberto na memoria HEAP (nao temporaria, ao contrario da stack) pela funcao malloc do tamanho do noh, ou seja do tamanho do struct nohConteudo que vai ser preenchido por uma variavel do tipo noh
	
	
	nohEmCriacao->prox = NULL; //ja q nao tem um nó seguinte ainda
	nohEmCriacao->valor = valor; //a variavel valor do nohEmCriacao apenas foi criada e nao preenchida. igualar a valor passo o valor int 1 da main
	
	
	
	
	
	noh *nohEmAnalise = inicio; /// volta pro inicio da lista por causa do loop
	
	while(nohEmAnalise->prox != NULL){ // =NULL é o último
		nohEmAnalise = nohEmAnalise->prox;
	}
	
	nohEmAnalise->prox = nohEmCriacao; //ponteiro do nó antes do em criacao sendo ligado ao proprio em criacao
}












void liberar (noh *inicio){
	noh *nohEmAnalise = inicio->prox; //primeiro nó da memoria heap    //talbez   // o * faz ser um ponteiro, diferente da linha 35
	noh *aDescartar; 
	
	while (nohEmAnalise != NULL){
		aDescartar = nohEmAnalise; //passa pra aDescartar ja que nohEmAnalise nao pode ser pq controla a ordem
		nohEmAnalise = nohEmAnalise->prox;
		free(aDescartar); //elimina
	}
}
