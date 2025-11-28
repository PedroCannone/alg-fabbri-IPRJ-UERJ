#include <stdio.h>
#include <string.h>

// esse codigo faz mais sentido com o mapa dado em aula como referencia

struct casa {
	char *nome;
	casa *esquerda;
	casa *direita;
	casa *cima;
	casa *baixo;
	bool visitado;
};




void liberar(casa *inicial){   // essa funcao podia ser automatizada lendo o resultado da funcao buscaDoCaminho e seguindo os 2 caminhos enquanto libera. Eu nao fiz pq o labirinto é fixo e tambem porque o exercicio nao pedia
	
	free(inicial);
	
	free(inicial->direita); // bifurcacao
	
	free(inicial->direita->cima); // moedas
	free(inicial->direita->cima->nome); // char nome em moedas
	
	free(inicial->direita->baixo); //vazia
	
	free(inicial->direita->baixo->direita); // boss
	
	free(inicial->direita->baixo->direita->direita); //fim
	free(inicial->direita->baixo->direita->direita->nome); // char nome em fim
}




void buscaDoCaminho(char *nome_desejado, casa *inicial, casa *moedas){     // ja que tem 2 caminhos sem repeticoes possiveis, criei caminho 1 e 2
	casa *em_analise = inicial;
	char caminho1[] = '';
	char caminho2[] = '';
	bool loop_restart;
	buscando_caminho2 = false;
	
	
	
	
	while() {
		
		
		
		while (em_analise->direita != fim){
			
			loop_restart = false;
			
			
			
			if (em_analise->direita != NULL && em_analise->direita->visitado != true && loop_restart = false) {
			}
				em_analise = em_analise->direita;
				
				if (buscando_caminho2 == true) {
					caminho2 = strcat(caminho2, 'direita, ');
				}
				else {
					caminho1 = strcat(caminho1, 'direita, ');
				}
				
				loop_restart = true;
			}
			
			
			
			if (em_analise->cima != NULL && em_analise->cima->visitado != true && loop_restart = false) {
				em_analise = em_analise->cima;
				
				if (buscando_caminho2 == true) {
					caminho2 = strcat(caminho2, 'direita, ');
				}
				else {
					caminho1 = strcat(caminho1, 'direita, ');
				}
				
				loop_restart = true;
			}
			
			
			
			if(em_analise->baixo != NULL && em_analise->baixo->visitado != true && loop_restart = false) {
				em_analise = em_analise->baixo;
				
				if (buscando_caminho2 == true) {
					caminho2 = strcat(caminho2, 'direita, ');
				}
				else {
					caminho1 = strcat(caminho1, 'direita, ');
				}
				
				loop_restart = true;
			}
			
			
			
		
			if (em_analise->esquerda != NULL && em_analise->esquerda->visitado != true && loop_restart = false) {
				em_analise = em_analise->esquerda;
				
				if (buscando_caminho2 == true) {
					caminho2 = strcat(caminho2, 'direita, ');
				}
				else {
					caminho1 = strcat(caminho1, 'direita, ');
				}
				
				loop_restart = true;
			}
			
		}
		
		strcat(caminho, 'direita');
		
		em_analise = inicial;
		
		if (buscando_caminho2 == true){
			break;
		}
		buscando_caminho2 = true;
		
		moedas->visitado = true;    // loop tem preferencia pra cima, isso manda o prox loop por baixo
	}
	
	//cout << caminho1 << endl;
	//cout << caminho2 << endl;
	printf("%s\n", caminho1);
	printf("%s\n", caminho2);
}





int main() {
	casa *inicial = (casa*)malloc(sizeof(casa));
	casa *bifurcacao = (casa*)malloc(sizeof(casa));
	casa *moedas = (casa*)malloc(sizeof(casa));
	casa *vazia = (casa*)malloc(sizeof(casa));
	casa *boss = (casa*)malloc(sizeof(casa));
	casa *fim = (casa*)malloc(sizeof(casa));
	
	moedas->nome = (char*)malloc(sizeof(strlen('moedas')));
	moedas->nome = 'moedas';
	
	fim->nome = (char*)malloc(sizeof(strlen('game over')));
	fim->nome = 'game over';
	
	inicial->direita = bifurcacao;
	
	bifurcacao->cima = moedas;
	bifurcacao->baixo = vazia;
	bifurcacao->esquerda = inicial;
	
	moedas->baixo = vazia;
	moedas->esquerda = bifurcacao;
	moedas->direita = boss;
	
	vazia->cima = moedas;
	vazia->esquerda = bifurcacao;
	vazia->direita = boss;
	
	boss->cima = moedas;
	boss->baixo = vazia;
	boss->direita = fim;
	
	inicial->visitado = false;
	bifurcacao->visitado = false;
	moedas->visitado = false;
	vazia->visitado = false;
	boss->visitado = false;
	fim->visitado = false;
	
	
	buscaDosCaminhos("game over", &inicial, &moedas);  // printa os dois caminho possiveis no console
	
	liberar();
}
