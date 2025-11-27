#include <stdio.h>
#include <string.h>


struct BigString {
	char *conteudoString;
	struct BigString *prox;
};

typedef struct BigString BS;




void charAleatorio(BS *string1, int posicao){
	char stringEmAnalise = string1->conteudoString;
	
	
	int i = 0;
	while(i <= posicao){
		if (stringEmAnalise[i] == '/0'){
			i--;
			stringEmAnalise = string1->prox;
			
			posicao = posicao - strlen(string1->conteudoString) + 1;
			i = i - strlen(string1->conteudoString) + 1;
		}
		
		i++;
	}
	
	cout << stringEmAnalise[i] << endl;
	
}






int main (){
	
	char input1 = "blablabla";
	char input2 = "oioioi";
	
	BS *string1 = (BS*)malloc(sizeof(BS)); // bs no malloc ou bigstring????
	string1->conteudoString = (char*)malloc(sizeof(strlen(input1)));
	string1->conteudoString = input1;
	
	BS *string2 = (BS*)malloc(sizeof(BS));
	string2->conteudoString = (char*)malloc(sizeof(strlen(input2)));
	string2->conteudoString = input2;
	
	string1->prox = string2;
	
	
	
	
	charAleatorio(string1, 10);
	
	return 0;
}









