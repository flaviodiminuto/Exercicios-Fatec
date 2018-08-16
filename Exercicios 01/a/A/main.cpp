//a) Ler 10 elementos de uma matriz tipo vetor e apresentá-los. 
#include <iostream>

using namespace std;
int const tamanho = 10;


int main(){
    int vetor[tamanho];
    cout << "Leitura de Matriz\n";
    //Leitura dos dados da matria
     for (int i=0; i<tamanho;i++){
        cout << "Digite o "<<i+1<< "º valor: ";
        cin >> vetor[i];
    }
    cout << "\nImprimindo os valores\n";
    for(int i=0;i<tamanho;i++){
    cout << "\n 1: "<<vetor[i];
    }
    return 0;
}