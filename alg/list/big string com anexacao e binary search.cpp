#include <stdio.h>
#include <string.h>


struct BigString {
	char *conteudoString;
	struct BigString *prox;
};

struct index_table_struct {
	char *letra;
	int *posicao;
};


typedef struct BigString BS;




void liberar(BigString *string1){
	noh *seletorDeNoh = string1;
	noh *aLiberar;
	
	while (seletorDeNoh != NULL){  // nao passa pelo loop depois depois de virar o prox (NULL) do ultimo noh
		aLiberar = seletorDeNoh;
		seletorDeNoh = seletorDeNoh->prox;
		free(aLiberar->conteudoString);
		free(aLiberar);
	}
}





char criar_index_table(BS *string1) {
	BS *BS_em_analise = string1;
	char index_table = '';
	
	while (BS_em_analise->prox != NULL){
		strcat(index_table, BS_em_analise->conteudoString);
		BS_em_analise = BS_em_analise->prox;
	}
	strcat(index_table, BS_em_analise->conteudoString);
	
	
	return index_table;
}






void anexar_string(BS *string1, char input3_anexar) { 
	BS *string_nova = (BS*)malloc(sizeof(BS));
	string_nova->conteudoString = (char*)malloc(sizeof(strlen(input3_anexar)));
	string_nova->conteudoString = input3_anexar;
	
	BS *ate_ultimo_noh = string1;   // primeiro noh
	while (ate_ultimo_noh->prox != NULL) {
		ate_ultimo_noh = ate_ultimo_noh->prox;
	}
	
	ate_ultimo_noh->prox = string_nova; // ate_ultimo_noh ta dividindo o endereco com o ultimo noh de fato ???????????????????????
}








char BS_busca_binaria(char index_table, int posicao_desejada) {
	int low = 0;
	int high = strlen(index_table) - 1;
	int mid;
	
	while (low <= high)	{
		mid = (low + high) / 2;
		
		if (index_table == posicao_desejada) {
			return index_table[mid];
		}
		
		if (index_table < posicao_desejada) {
			low = mid + 1;
		}
		
		if (index_table > posicao_desejada) {
			high = mid - 1;
		}		
	}
}









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
	
	
	
	charAleatorio(&string1, 10);
	
	anexar_string(&string1, 'hehehe');
	
	char index_table = criar_index_table(&string1);
	
	printf(%s, BS_busca_binaria(index_table, 17) );
	
	
	return 0;
}

