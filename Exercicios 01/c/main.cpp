/*c)  Fazer o APFE: faça um algoritmo que busca e retorna quantas vezes uma palavra
específica aparece dentro de um texto digitado. Leia e armazene a palavra dentro
da variável PALAVRA é busque no texto quantas vezes esta palavra aparece.
(Busca dentro de um string)*/
#include "iostream"
#include  "string"
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    //Preparação da variáveis utilizadas
    string texto="Bem vindo a disciplina de estrutura de dados ministrada na Fatec zona sul.\nNesta disciplina você aprederá as principais estruturas de dados utulizadas na programação e como manipular estes dados com algorítimos adequados";
    string palavra;
    int contador=0;
    int tamanhoTexto=0;
    bool igual;

    //Exibir um texto no topo da tela com o conteúdo da String 'texto' onde o usuario realizará a consulta.
    cout << texto;

    //Instrução para inserir palavra a ser consultada
    cout << "\nInforme a palavra que deseja consultar no texto acima: ";

    //Armazena a  'palavra' a ser consultada no texto
    cin >> palavra;

    //Localiza e conta quanta vezes a 'palavra' ocorre no texto.
    for(int i=0; i<=(texto.size()-palavra.size()+1); i++){
        igual=true;
        if(texto.substr(i,palavra.size()).compare(palavra)==0){
           contador++;
        }
    }
    cout << "\nA palavra "<<palavra<<" ocorre "<< contador << " vezes!";

    //Informa ao usuário quantas vezes a 'palavra' ocorre no texto.


    //FIM DO PROGRAMA
    return 0;
}