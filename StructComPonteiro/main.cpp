//Ponteiro para Struct

/**Fa�a um programa com menu de tr�s op��es (1-ler linha, 2- mostrar e 3- sair), contendo um
STRUCT para cadastrar o nome, a idade, o sexo e o sal�rio de pelo menos duas pessoas. Crie um
ponteiro para manipular o STRUCT. O programa dever� conter as seguintes fun��es para o
STRUCT: (use switch case )
a) void armazenarlinhastruct ( )
b) void mostrardadosstruct ( )
c) ler_idade ( )
d) ler_sexo ( )
e) ler_nome ( )
f) ler_salario ( )*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
const int tam = 2;

typedef struct estrutura pessoa;
struct estrutura{
    string nome;
    int idade;
    char sexo;
    double salario;
};


int ler_idade ( ){
    int idade;
	cout << "Digite a idade: ";
	cin >> idade;
    return idade;
}
char ler_sexo ( ){ //M�todo que  retorna o sexo
    char sexo;
    cout << "Digite o sexo(M ou F): ";
    cin >> sexo;
    return sexo;
}
string ler_nome ( ){ //M�todo que  retorna o nome
    string nome;
    cout << "\nDigite o nome: ";
    cin >> nome;
   // getline(cin,nome);
    return nome;
}
double ler_salario ( ){ //M�todo que retorna o salario
    float salario;
    cout << "Digite o salario: ";
    cin >> salario;
    return salario;
}
void armazenarlinhastruct ( pessoa *pes){
        pes->nome = ler_nome();
        pes->idade = ler_idade();
        pes->sexo = ler_sexo();
        pes->salario = ler_salario();
}
void mostrardadosstruct (pessoa *pes ){
	cout << "Nome: "<<pes->nome;
	cout << "\nIdade: "<<pes->idade ;
	cout << "\nSexo: "<<pes->sexo;
	cout << "\nSalario R$: "<<pes->salario <<"\n\n";
}

int main (){
    int opt =0; //Utilizado para identificar opera��es do menu
    pessoa pessoas[tam];


    do{
        //Apresentando o programa
        cout << "\nPrograma utilizando ponteiro para struct";

        //Menu apresentando as opera��es realizadas pelo programa
        cout << "\nSelecione uma das opcoes a seguir:";
        cout << "\n1 - Ler linha";
        cout << "\n2 - Mostrar";
        cout << "\n3 - Sair \n";

        //Leitura da opera��o desejada (Ler, mostrar ou sair)
        cin >> opt;

        switch(opt){
            case 1:
            for(int i=0; i<tam; i++){
                armazenarlinhastruct(&pessoas[i]);
            }
                break;
            case 2:
            	cout << "\nListando pessoas\n\n";
            	for(int i=0; i<tam; i++){
                	mostrardadosstruct(&pessoas[i]);
                }
                break;
            case 3:
                cout << "\nSaindo do programa\n";
           

        }
    }while (opt!=3);


    return 0;
}
