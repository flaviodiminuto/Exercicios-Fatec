/*c) Ler duas matrizes A e B do tipo vetor com 20 elementos. Construir uma matriz C, onde cada
elemento de C é a subtração do elemento correspondente de A com B. Apresentar a matriz C.*/

#include <iostream>

using namespace std;
int const tamanho= 20;

int main(){
    int matrizA[tamanho];
    int matrizB[tamanho];
    int matrizC[tamanho];
    cout << "Informe os valores da matriz A\n";
    for(int i=0; i<tamanho; i++){
        cout << i+1 << "º valor da matriz A: ";
        cin >> matrizA[i];
    }
    cout << "Informe os valores da matriz B\n";
    for(int i=0; i<tamanho; i++){
        cout << i+1 << "º valor da matriz B: ";
        cin >> matrizB[i];
    }
    //Preenchendo e exibindo a matriz C
    cout << "Imprimindo  a matriz C\n";
    for(int i=0; i<tamanho; i++){
        matrizC[i] = (matrizA[i]-matrizB[i]);
        cout << i+1 << "º valor da matriz C: " <<matrizC[i]<<endl;
    }

    return 0;
}