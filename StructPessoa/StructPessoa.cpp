#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

typedef struct composta classificacao;
struct composta{
    string nome="";
    int idade=0;
};
int const n = 4;
classificacao pessoa[n];

string retornaRegistro(int i){
    string texto= "\nNome: " + pessoa[i].nome + "\t\t| Idade: " + std::to_string(pessoa[i].idade) + "\n";
    return texto;
}
void lerValores(int i){//Input de nome e idade
    cout << "\nInforme o nome: ";
    cin >> pessoa[i].nome;
    cout << "\nInforme a idade do(a) " << pessoa[i].nome<<": ";
    cin >> pessoa[i].idade;
}
void exibirTabela(){
    cout <<"Lista de registros :";
    cout <<"\n-------------------------------------------------------------------------------------";
    for (int i=0;i<n;i++){
        cout << retornaRegistro(i);
        cout <<"-------------------------------------------------------------------------------------\n";
    }
}
void classificarPorNome(){
    classificacao pessoaAux;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(pessoa[i].nome.compare(pessoa[j].nome)<0){
                pessoaAux = pessoa[i];
                pessoa[i]=pessoa[j];
                pessoa[j] = pessoaAux;
            }
        }
    }
}
void classificarPorIdade(){
    classificacao pessoaAux;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(pessoa[i].idade < pessoa[j].idade){
                pessoaAux = pessoa[i];
                pessoa[i]=pessoa[j];
                pessoa[j] = pessoaAux;
                }
        }
    }
}

/*OBS este modelo permite apresentar mais de um registro com determinada idade*/
void buscaPorIdade(){ //Busca sequencial
    int idade;
    cout << "\nInforme a idade da(s) pessoa(s) que deseja pesquisar: ";
    cin >> idade;
    for(int i=0; i<n; i++){
        if(pessoa[i].idade==idade){
            cout << retornaRegistro(i);
        }
    }
}

/*OBS: Este modelo encerra a busca assim que encontra a primeira ocorrencia
presumindo que cada registro seja único e não seriam encontrados novos registros com
a mesma ocorrência */
void buscaPorNome(){ //Busca binária
    string nome;
    int esquerda;
    int direita;
    int meio =0;

    cout << "\nInforme o nome da(s) pessoa(s) que deseja pesquisar: ";
    cin >> nome;
    esquerda =0;
    direita =n;
    classificarPorNome();

    for(int i=0; i<n; i++){
        meio = esquerda+((direita+1)%2);//posição do valor que estamos procurando
        if(pessoa[meio].nome.compare(nome)==0){
           cout << "Indice: "<<meio <<" "<<retornaRegistro(meio) ;
           break;
        }
        else{
            if(pessoa[meio].nome.compare(nome)<0)
                esquerda = meio;
                else
                direita = meio;
            }
    }
}

int main() {
    int opt;
        do{
        cout << "\nPrograma de ordenacao";
        cout << "\n1 - Ler nome e idade";
        cout << "\n2 - Exibir tabela";
        cout << "\n3 - Classificar por idade";
        cout << "\n4 - Classificar por nome";
        cout << "\n5 - Busca  por idade";
        cout << "\n6 - Busca por nome";
        cout << "\n7 - Sair\n";
        cin >> opt;

            switch(opt){
                case 1:
                    for(int i=0; i<n; i++){
                        lerValores(i);
                    }
                    break;
                case 2:
                    exibirTabela();
                    break;
                case 3:
                    classificarPorIdade();
                    exibirTabela();
                    break;
                case 4:
                    classificarPorNome();      //Sequencial
                    exibirTabela();
                    break;
                case 5:
                    buscaPorIdade();        //Busca binária
                    break;
                case 6:
                    buscaPorNome();
                    break;
            }
        }while(opt!=7);
        return 0;
}

/*a) Faça o diagrama de blocos e também o código fonte que contenha uma estrutura
(STRUCT) chamada PESSOA criada para armazenar até 10 elementos, com os atributos int
IDADE e string NOME. O programa será comandado por um menu com select case com as
seguintes opções: no Case 1 Ler Nome e Idade, case 2 Exibir tabela, case 3 classificar por
Idade, case 4 classificar por nome, case 5 busca sequencial por idade, case 6 busca binária
por nome e case 7 sair;*/
