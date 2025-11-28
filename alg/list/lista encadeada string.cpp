#include <stdio.h>
#include <stdlib.h>
#include <string.h>







// montagem do struct tendo o conteudo de cada nó
struct nohConteudo {
	char *conteudoString; // precisa ser ponteiro pq o tamanho da string varia e o ponteiro aponta para conteudoString que varia por string separadamente
	struct nohConteudo *prox; //um ponteiro chamado prox que guarda uma (outra) struct nohConteudo
};

//criar "noh" para ser um tipo que significa o struct nohConteudo
typedef struct nohConteudo noh;

void novoNoh (noh *inicio, char *conteudoString);
void liberar (noh *inicio);










int main(){
	
				// declarar inicio como um nó usando o data type noh que é o struct nohConteudo, ou seja, inicio guarda um valor e ponteiro prox NA STACK
	noh inicio; // sem malloc e o * antes do inicio, o tipo de memoria eh stack e eh eliminada rapidamente. Serve para o nó inicio porque ele é temporario e ela so termina quando o main terminar, no fim do programa
	
	inicio.prox = NULL; // ja que existe só o nó inicio, NULL quer dizer que nao tem prox ainda
	
	
	novoNoh(&inicio, "blablabla");
	liberar(&inicio);
	
	
	return 0;
}












void novoNoh (noh *inicio, char *conteudoString){ // recebe 
	
	// memory allocation NAO USA A STACK, NAO SOME DEPOIS DA CONCLUSAO DESSA FUNCAO
	noh *nohEmCriacao = (noh*)malloc(sizeof(noh)); //ponteiro pro espaco aberto na memoria HEAP (nao temporaria, ao contrario da stack) pela funcao malloc do tamanho do noh, ou seja, do tamanho do struct nohConteudo que vai ser preenchido por uma variavel do tipo noh
	
	
	
	nohEmCriacao->prox = NULL; //ja q nao tem um nó seguinte ainda
	nohEmCriacao->conteudoString = (char*)malloc(strlen(conteudoString) + 1); // precisa declarar o espaco de memoria pra string separada ja que varia e o +1 para o caracter \0
	strcpy(nohEmCriacao->conteudoString, conteudoString); //copia o conteudo da string pra dentro do espaco de memoria conteudoString na struct
	
	
	
	
	noh *nohEmAnalise = inicio; /// volta pro inicio da lista por causa do loop
	
	while(nohEmAnalise->prox != NULL){ // =NULL é o último
		nohEmAnalise = nohEmAnalise->prox;
	}
	
	nohEmAnalise->prox = nohEmCriacao; //ponteiro do nó antes do em criacao sendo ligado ao proprio em criacao
}












void liberar (noh *inicio){
	noh *nohEmAnalise = inicio->prox; //primeiro nó da memoria heap
	noh *aDescartar;
	
	while (nohEmAnalise != NULL){
		aDescartar = nohEmAnalise; //passa pra aDescartar ja que nohEmAnalise nao pode ser pq controla a ordem
		nohEmAnalise = nohEmAnalise->prox;
		free(aDescartar->conteudoString); //elimina o espaco de memoria pra string
		free(aDescartar); //elimina o espaco pra struct
	}
}
