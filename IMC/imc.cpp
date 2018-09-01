/*Descrição da atividade proposta no rodapé deste código*/
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
const int tam=4;
typedef struct tabela classificacao;
struct tabela{
    string nome;
    double peso;
    double altura;
    double imc;
};

classificacao imc[tam];

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
    imc[i].altura=lerAltura();
    imc[i].imc = calculaIMC(imc[i].altura,imc[i].peso);
}

void exibirTabela(){
    cout <<"Lista de registros :";
    cout <<"\n-------------------------------------------------------------------------------------";
    for (int i=0;i<tam;i++){
        cout << "\n Nome: "<<imc[i].nome<<"\t\t| Peso: "<<imc[i].peso<<"\t\t| Altura: "<<imc[i].altura<<"\n";
    }
    cout <<"\n-------------------------------------------------------------------------------------";
}
string classificaIMC(double imc){
    string resposta;
    if(imc>40)
        resposta = "Obesidade Grau III";
    else
        if(imc>=35)
            resposta = "Obesidade Grau II";
        else
            if(imc>=30)
                resposta = "Obesidade Grau I";
            else
                if(imc>=25)
                    resposta = "Sobrepeso";
                else
                    if(imc >=15.5)
                        resposta = "Peso normal";
                    else
                        resposta = "Abaixo do peso";
    return resposta;
}
void pesquisarNome(){
    string nome;
    cout <<"\nInforme o nome que deseja pesquisar : ";
    cin >> nome;
    cout.precision(2);
    for(int i=0; i<tam; i++){
        if(imc[i].nome.compare(nome)==0){
            cout << "\nNome: "<<imc[i].nome<<"\t| Peso: "<<imc[i].peso<<"\t| Altura: "<<imc[i].altura<<"\t| IMC: \""<<imc[i].imc<<"\" "<<classificaIMC(imc[i].imc)<<"\n\n";
        }
    }
}

void classificarPorNome(){
    classificacao imcAux;
    for(int i=0; i<tam; i++){
        for(int j=i;j<tam; j++){
            if(imc[i].nome.compare(imc[j].nome)>0){
                imcAux = imc[i];
                imc[i] = imc[j];
                imc[j] = imcAux;
            }
        }
    }
    exibirTabela();
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
                for(int i=0; i<tam; i++){
                    lerValores(i);
                }
                break;
            case 2:
                exibirTabela();
                break;
            case 3:
                pesquisarNome();
                break;
            case 4:
                classificarPorNome();
                break;
        }
    }while(opt!=5);
    return 0;
}

/*Faça um algoritmo com struc e menu completo para ler uma lista de NOMES, PESOS, ALTURAS
e armazenar o cálculo do índice de massa corpórea, IMC. Faça um menu com a opções: 1 Ler,
processar, 2 exibir tabela, 3 pesquisar por nome, 4 Classificar por nome, 5 sair. Na opção pesquisar
por nome, faça uma pesquisa sequencial para encontrar e exibir o nome da pessoa, seu peso, sua
altura e seu IMC assim como seu status de classificação de peso. Use as mensagens de
classificação obtidas no site: http://www.calcularpesoideal.com.br/
*/

