#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

// 8 minutos - https://www.youtube.com/watch?v=Ov-oy4wC0to&t=433s


char palavraSorte [30];
char palavraDigitada [30];
const int quantPalavras = 22; //quantidade de palavras para sorteio
char banco [quantPalavras] [30] = {
"cachorro",
"cavalo",
"escola",
"paralelepipedo",
"comida",
"banana",
"abacate",
"amarelo",
"amigo",
"amor",
"aviao",
"balao",
"branco",
"caneca",
"celular",
"doce",
"elefante",
"escola",
"faca",
"fotografia",
"garfo",
"geleia",

};

int sorteio() {
    srand(time(NULL));
    return rand() % (quantPalavras);
}


void imPalavra () {
    cout << "       Palavra com " << strlen(palavraSorte) << " letras\n\n       ";
    for (int i=0; i< strlen(palavraSorte); i++) {
        cout <<palavraDigitada [i] << " ";
    }
}

void copia (int copiaIndice) {
    for (int i=0; i<30; i++){
        palavraSorte [i] = banco [copiaIndice] [i];
    }
}

void limpa () {
        for (int i=0; i<strlen(palavraSorte); i++) {
        palavraDigitada[i] = '_';
    }
}

void imprimeForca (int letrasErro) {
    switch(letrasErro){
        case 0:
            cout << "  _______"<< endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
        break;
            
        case 1:
            cout << "  _______" << endl;
            cout << " |      O" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
        break;

        case 2:
            cout << "  _______" << endl;
            cout << " |      O" << endl;
            cout << " |      | " << endl;
            cout << " | " << endl;
            cout << " | " << endl;
        break;

        case 3:
            cout << "  _______" << endl;
            cout << " |      O" << endl;
            cout << " |     /|" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
        break;

        case 4:
            cout << "  _______" << endl;
            cout << " |      O" << endl;
            cout << " |     /|\\ " << endl;
            cout << " |" << endl;
            cout << " |" << endl;
        break;

        case 5:
            cout << "  _______" << endl;
            cout << " |      O" << endl;
            cout << " |     /|\\ " << endl;
            cout << " |     /" << endl;
            cout << " |" << endl;
        break;

        case 6:
            cout << "  _______" << endl;
            cout << " |      O" << endl;
            cout << " |     /|\\" << endl;
            cout << " |     / \\" << endl;
            cout << " |" << endl;
        break;
	}    
}

bool verificarLetra (char letra, char vetor [26]) {
	for (int i=0; i< strlen (vetor); i++) {
		if (letra == vetor [i]) {
			return true;
		}
	}
	return false;
}   

void subistitui(char letra) {
	for (int i=0; i < strlen (palavraSorte); i++){
		if (palavraSorte[i] == letra){
			palavraDigitada[i] = letra;
			}
		 }
	}

bool completo(){
	for(int i=0; i<strlen(palavraSorte); i++){
		if(palavraDigitada[i] == '_'){
			return false;
			}
		}
	return true;
	}

int main () {

    int indice = sorteio(); //Faz sorteio
    copia(indice);
    limpa (); //limpar vetor
    int contador=0; //Conta letras
    int erros = 0;
    char jaDigitadas [26]; //Verifica no alfabeto
    char letra; 

    while (erros <= 6) {
        system("clear");
        imprimeForca(erros);
        cout << "\n\n";
        imPalavra();
	//cout << "\n\n Letras já digitadas: " << jaDigitadas << endl;
	cout << "\n\n Restam " << 7-erros << " tentativas! " << endl;
        cout << "\n\n"; 
        cout << "Digite uma letra: ";
        cin >> letra; 
        letra = tolower (letra);
	if (verificarLetra(letra, jaDigitadas)) {
		cout << " Esta letra já foi digitada, escolha outra.  " << endl;
		cout << " Pressione ENTER para continuar. " << endl;
		cin.ignore();
		cin.get();
		}
       //break;

    	else {
		jaDigitadas [contador] = letra; 
		contador++;
		if(verificarLetra (letra, palavraSorte)) {
			subistitui (letra);
			}
		else {
			cout << " Você errou, tente novamente!! " << endl;
			erros++;
			
		}
	     }
	if(erros==7){
		cout << "Que pena, você perdeu! ;( " << endl;
		return 0;
		}
	if(completo()){
		cout << "MUITO BEM, VOCÊ VENCEU!!!! :D " << endl;
		cout << "A palavra sorteada era: " << palavraSorte << "!! " <<endl;
		return 0;
		}
    }
	


return 0;

}
