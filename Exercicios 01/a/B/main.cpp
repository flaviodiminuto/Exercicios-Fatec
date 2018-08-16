/*b) Ler 8 elementos em uma matriz A tipo vetor. Construir uma matriz B de mesma dimensão com os
elementos da matriz A multiplicados por 3. O elemento B[i] deverá ser implicado pelo elemento
A[i]*3, o elemento B[2] implicado pelo elemento A[2]*3 e assim por diante, até 8. Apresentar o vetor
B. */

#include <iostream>
using namespace std;
int const tamanho = 8;

int main(){
    int matrizA[tamanho];
    int matrizB[tamanho];
    cout << "Preenchendo a Matriz A:\n";
    for(int i=0 ; i<tamanho ; i++){
        cout << "Digite o "<< i+1<< "º valor ";
        cin >> matrizA[i];
        matrizB[i] = (matrizA[i]*3);
    }

    cout << "\nImprimindo a Matriz A:\n";
    for(int i=0 ; i<tamanho ; i++){
        cout << i+1 <<"º valor: "<< matrizA[i]<< endl;
    }
    cout << "\nImprimindo a Matriz B:\n";
    for(int i=0 ; i<tamanho ; i++){
        cout << i+1 <<"º valor: "<< matrizB[i]<< endl;
    }

    return 0;
}