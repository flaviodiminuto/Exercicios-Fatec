/*b) Ler uma matriz A do tipo vetor com 15 elementos. Construir uma matriz B de mesmo tipo, sendo
que cada elemento da matriz B seja o fatorial do elemento correspondente da matriz A. Apresentar
as matrizes A e B.*/
#include <iostream>
using namespace std;


int const TAMANHO =15;
int vetorA[TAMANHO];
int vetorB[TAMANHO];


//Função fatorial recursiva
float fatorial(float valor){
    if(valor==1)
        return valor;
    else
        valor = valor*fatorial(valor-1);
    return valor;
}

int main (){

    cout << "Preenchendo a matriz A: \n";
    for(int i=0; i<TAMANHO; i++){
        cout << "Informe o valor "<<i+1<<" : ";
        cin >> vetorA[i];
    }
    cout << "\n\nPreenchendo a Matriz B: ...\n";
        for(int i=0; i<TAMANHO; i++){
        vetorB[i] = fatorial(vetorA[i]);
    }
    cout << "Apresentando os valores das duas matrizes.";
        cout << "\n\nMatriz A:| Matriz B\n";
        for(int i=0; i<TAMANHO; i++){
        cout << vetorA[i]<<"\t|\t"<<vetorB[i]<<"\n";
    }

return 0;
}