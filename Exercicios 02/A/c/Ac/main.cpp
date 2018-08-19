/*c) Ler 5 elementos (valores reais) para temperaturas em graus Celsius em uma matriz A de uma
dimensão do tipo vetor. Construir uma matriz B de mesmo tipo e dimensão, em que cada elemento
da matriz B deverá ser a conversão da temperatura em graus Fahrenheit do elemento
correspondente da matriz A. Apresentar as matrizes A e B lado a lado. A fórmula de conversão é
F= (9C+160)/5 , sendo F a temperatura em Fahrenheit e C a temperatura em Celsius. */
#include <cstdlib>
#include <iostream>

using namespace std;
int const TAMANHO = 5;                                                                            
float vetA[TAMANHO];
float vetB[TAMANHO];

float lerValor(int i){
    float valor;
    cout << "\nInforme o "<<i+1<<"º valor a ser convertido: ";
    cin >> valor;
    return valor;
}
float converteCtoF(float valor){
    valor = ((9*valor)+160)/5;
    return valor;
}
int main(int argc, char** argv) {
    //Apresentação do programa
    cout << "Bem vindo!\nPrograma de conversao de Celsius para Fahrenheit.";
    //Leitura dos valores em Celsius e conversão para fahrenheit
    for(int i =0; i<TAMANHO; i++){
        vetA[i] = lerValor(i);
        vetB[i] = converteCtoF(vetA[i]);
    }
    //Exibição dos valores dos dois vetores A e B
    cout << "Valores convertidos de Celsius para Fahrenheit\n";
    for(int i =0; i<TAMANHO; i++){
        cout << vetA[i] <<"Cº\t"<<vetB[i]<<"Fº\n";
    }
    return 0;//Fim do programa
}

