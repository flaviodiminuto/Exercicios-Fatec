/*b) Fazer o DBE e o APFE: Faça o algoritmo para calcular o valor de uma prestação
em atraso com base na multa de 2% e também do juros mensal de 1% sobre o
valor principal. Declare vetores explícitos para entrada do valor da prestação,
valorprincipal [ ] e da quantidade de dias em atraso: dias [ ]. Armazene os
resultados no vetor ValorPagar [ 5 ]. Ao final imprima a tabela com os vetores
valorPrincipal [], dias [] e valorpagar[] . 
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
int const TAMANHO = 2;

float calculaDias(int dias,float valor){
    float inicial = valor;
    double atraso = rint(dias/30);

        for(int i=0; i<=atraso; i++){
        valor*=1.01;
        }
            valor-=inicial;

    return valor;
}
int main(int argc, char** argv) {
    setlocale(LC_ALL,"Portuguese");
    float valorPrincipal[TAMANHO];
    int quantidadeDiasAtraso[TAMANHO];
    float valorPagar[TAMANHO];
    
//Apresentação do programa
    cout << "Bem vindo!\nCalcule o valor a pagar nas contas em atraso.\n";
//Leitura do valor a ser calculado (Principal)
    for(int i=0; i<TAMANHO; i++){
    //Leitura do valor principal
        //printf("\nDigite o valor da %dº conta (utilize ponto e não virgula para centavos): ",i+1);//teste
        cout << "\nDigite o valor da "<<i+1<<"º conta (utilize ponto e não virgula para centavos): ";
        cin >> valorPrincipal[i];
    //Leitura da quantidade de dias em atraso
        cout << "\nDigite a quantidade de dias que a "<<i+1<<" está em atraso: ";
        cin >> quantidadeDiasAtraso[i];
    }
//Calculo do valor a ser pago
    for(int i=0; i<TAMANHO; i++){
        if(quantidadeDiasAtraso[i]>0){
        valorPagar[i] = valorPrincipal[i]*1.02+calculaDias(quantidadeDiasAtraso[i],valorPrincipal[i]);
        }else
            valorPagar[i] = valorPrincipal[i];
    }
//Apresenta os valores
    cout << "\n\nApresentando valores a serem pagos...\n";

    for(int i=0; i<TAMANHO; i++){
            cout <<i+1<<": "<< "Valor inicial: R$ "<< valorPrincipal[i]<<"\n"<<i+1<<": "<<"Dias em atraso: "<<quantidadeDiasAtraso[i]<<"\n"<<i+1<<": "<<"Valor recalculado: R$ "<<valorPagar[i]<<"\n\n";
    }
    system("PAUSE");
    return 0;
}

