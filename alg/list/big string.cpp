#include <stdio.h>
#include <string.h>


struct BigString {
	char *conteudoString;
	struct BigString *prox;
};

typedef struct BigString BS;




void liberar(BS *string1){
	BS *seletorDeNoh = string1;
	BS *aLiberar;
	
	while (seletorDeNoh != NULL){  // nao passa pelo loop depois depois de virar o prox (NULL) do ultimo noh
		aLiberar = seletorDeNoh;
		seletorDeNoh = seletorDeNoh->prox;
		free(aLiberar->conteudoString);
		free(aLiberar);
	}
}





void charAleatorio(BS *string1, int posicao){
	
	char stringEmAnalise[];
	strcpy(stringEmAnalise, string1->conteudoString); 
	
	
	int i = 0;
	while(i <= posicao){
		if (stringEmAnalise[i] == '\0'){
			i--;
			strcpy(stringEmAnalise, string1->prox->conteudoString); //conteudoString de string2 vai pra analise
			
			posicao = posicao - strlen(string1->conteudoString) + 1;
			i = i - strlen(string1->conteudoString) + 1;
		}
		
		i++;
	}
	
	printf("%s\n", stringEmAnalise[i]);
	
}






int main (){
	
	char input1[] = "blablabla";
	char input2[] = "oioioi";
	
	BS *string1 = (BS*)malloc(sizeof(BS)); // bs no malloc ou bigstring????
	string1->conteudoString = (char*)malloc(strlen(input1) +1);    // +1 pro \0 , e sem sizeof porque nao precisa aqui
	strcpy(string1->conteudoString, input1); //popula o espaco de memoria reservado pela linha acima com string literal, pelo que eu enttendi
	
	BS *string2 = (BS*)malloc(sizeof(BS));
	string2->conteudoString = (char*)malloc(strlen(input2) +1);
	strcpy(string2->conteudoString, input2);
	
	string1->prox = string2;
	
	
	
	
	charAleatorio(&string1, 10);
	
	liberar(&string1);
	
	return 0;
}









