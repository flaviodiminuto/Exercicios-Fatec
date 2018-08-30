#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

typedef struct tabela classificacao;
struct tabela{
    string nome;
    double peso;
    double altura;
    double imc;
};

classificacao imc[5];

string lerNome(){
    string nome;
    cout << "\nInforme o nome : ";
    cin >> nome;
    return nome;
}
double lerPeso(){
    double peso;
    cout << "Informe o peso :";
    cin >> peso;
    return peso;
}
double lerAltura(){
    double altura;
    cout << "Informe a altura : ";
    cin >> altura;
    return altura;
}
double calculaIMC(double altura, double peso){
    return peso/(altura*altura);
}
void lerValores(int i){
    cout << "\nInforme os dados do candidato "<<(i+1)<<" : ";
    imc[i].nome=lerNome();
    imc[i].peso=lerPeso();
    imc[i].peso=lerAltura();
    imc[i].imc = calculaIMC(imc[i].altura,imc[i].peso);
}
int main(int argc, char** argv) {
    int opt;
    do{
    cout << "\nPrograma para calcular IMC";
    cout << "\n1 - Ler";
    cout << "\n2 - Exibir tabela";
    cout << "\n3 - Pesquisar por nome";
    cout << "\n4 - Classificar por nome";
    cout << "\n5 - Sair\n";
    cin >> opt;
    
    switch(opt){
        case 1:
            for(int i=0; i<5; i++){
                lerValores(i);
            }
            break;
    }
    
        
    }while(opt!=5);
    return 0;
}

