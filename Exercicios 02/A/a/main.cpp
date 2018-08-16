/*a) Ler duas matrizes A e B de uma dimensão com 12 elementos. A matriz A deverá aceitar
apenas a entrada de valores que sejam divisíveis por 2 ou 3, enquanto a matriz B deverá
aceitar apenas a entrada de valores que não sejam múltiplos de 5. A entrada das matrizes
deverá ser validada pelo programa e não pelo usuário. Construir uma matriz C de forma que
a matriz C seja a junção das matrizes A e B, e de forma que a matriz C contenha 24
elementos. Apresentar a matriz C. */
#include <iostream>
using namespace std;

int const TAMANHO =12; // tamanho que serC! utilizado pelos vetores

int vetA[TAMANHO],vetB[TAMANHO],vetC[TAMANHO+TAMANHO];

bool validaA(int valor){
    if((valor%2)==0||(valor%3)==0)
        return true;
    else{
        cout << "Valor inválido!\n\n";
        return false;
    }
         
}
bool validaB(int valor){
       if((valor%5)!=0)
        return true;
    else{
        cout << "Valor inválido!\n\n";
        return false;
    }
    return false;
}
int lerValor(int i,char c,string regra){//utilizado tanto para vetor A quanto para o vetor B
    int valor;
    if(c=='A')
    do{
    cout <<"Digite o "<< i+1 <<"º valor para o vetor "<<c << regra;
    cin >> valor;
    }while(!validaA(valor));
    
    if(c=='B')
    do{
    cout <<"Digite o "<< i+1 <<"º valor para o vetor "<<c << regra;
    cin >> valor;
    }while(!validaB(valor));

    return valor;
}
void imprimir(){

}
int main(){
    setlocale(LC_ALL, "Portuguese");
    int opt=1;
    cout << "Preencha o vetor A: \n";
    for(int i=0; i<TAMANHO; i++){
        vetA[i]= lerValor(i,'A',"\nO valor deve ser divisível por 2: ");
    }
    cout << "Preencha o vetor B: \n";
    for(int i=0; i<TAMANHO; i++){
        vetB[i]= lerValor(i,'B',"\nO valor não deve ser divisível por 5: ");
    }
    cout << "Preenchendo o vetor C...\n";
    for (int i=0;i<(TAMANHO+TAMANHO);i++){
        if(i<TAMANHO)
            vetC[i] = vetA[i];
        else
            vetC[i]=vetB[i-TAMANHO];
    }
    cout <<"Listando os valores do vetor C..\n\n";
    for (int i=0;i<(TAMANHO+TAMANHO);i++) {
        cout <<i+1<<"º: "<< vetC[i] <<"\n";
    }
    return 0;
}