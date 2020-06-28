#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// 15 minutos - https://www.youtube.com/watch?v=tfIUk_-ix6Y


char palavraSorte [30];
char palavraDigitada [30];
char jaDigitadas [26];
int contador=0;
const int quantPalavras = 11;
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

void imPalavra (int palavra) {
    for (int i=0; i<30; i++ ) {
        cout << banco [palavra] [i];
    }
}

void copia (int copiaIndice) {
    for (int i=0; i<30; i++ ){
        palavraSorte [i] = banco [copiaIndice] [i];
    }
}

int main () {

int indice = sorteio();




return 0;

}