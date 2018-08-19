/*d) Solicitar 20 nomes quaisquer que serão armazenados em uma matriz do tipo vetor. Ordene
este vetor em ordem alfabética. Exiba na tela os 20 nomes na ordem. Em seguida solicite um
nome para pesquisa. Caso o nome fornecido exista no vetor, informar a sua localização (seu
índice). */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


int const TAMANHO=20;
string vetor[TAMANHO];

//Ordenar o vetor
void ordenar(){
    //if cstring strcmp > 0 then the first character that does not match has a lower value in ptr1 than in ptr2 (http://www.cplusplus.com/reference/cstring/strcmp/)
    for(int i=0; i<TAMANHO; i++){
        for(int j=i; j<TAMANHO; j++){
            if(vetor[i].compare(vetor[j])>0){
                string temp = vetor[i];
                vetor[i]=vetor[j];
                vetor[j] = temp;
            }
        }
    }
}
int main(int argc, char** argv) {
    string consultada;
    int ocorrencia=0;
    //Apresentação e início do programa
    cout << "Bem vindo!\nPrograma para ordenar Nomes (Strings)\n";
    
    //Leitura dos nomes (Strings)
    for(int i=0; i<TAMANHO; i++){
        cout <<"\nInforme o "<<i+1<<"º nome sem espaço (somente uma palavra): ";
        cin >> vetor[i];
    }
    // Ordenando os nomes em ordem alfabetica no vetor
    ordenar();
    //Apresentando os nomes
    for(int i=0; i<TAMANHO; i++){
        cout <<i+1<<": "<< vetor[i]<<"\n";
    }
    //Ler palavra a ser consultada
    cout << "\nConsultar nome existente na lista.";
    cout << "\nInforme o nome que deseja consultar: ";
    cin >> consultada;
    //Realizar consulta e indicar a posição da palavra
    for(int i=0; i<TAMANHO; i++){
        if(vetor[i].compare(consultada)==0){
            cout << "\nA palavra "<<consultada<<" ocorre nas posiçção: ";
            cout << i+1;
            ocorrencia++;
        }
    }
    if(ocorrencia>0){
        cout << "\n\nA palavra " << consultada << " ocorre "<<ocorrencia<<" vez(es)!\n";
    }else{
        cout << "\n\nA palavra " << consultada << " não existe na lista.\n";
    }
    return 0;
}

