/*Faça um programa contendo as funções de implementação de uma
pilha (LIFO) que armazene a IDADE, NOME e o SALÁRIO de uma
pessoa. O programa deverá conter as seguintes funções:
• CRIAR PILHA
• EMPILHAR
• DESENPILHAR
• PILHA_VAZIA
• PILHA_CHEIA
• EXIBIR_VALOR_EMPILHADO
• EXIBIR_VALOR_DESEMPILHADO
• EXIBIR_PILHA
• CRIE AS FUNÇÕES PARA TRATAMENTO DE MENU E
TELA*/

#include <cstdlib>
#include <string> 
#include <iostream>

using namespace std;

const int tamanho = 2;

typedef struct pess pessoa;
struct pess{
    string nome;
    int idade;
    double salario;
};

typedef struct estrutura pilha;
    struct estrutura{
        int topo;
        pessoa registro[tamanho];
    };

//• LIMPA A TELA
    void limparTela(){
        system("cls");
    }

//• PILHA_VAZIA
    bool pilhaVazia(pilha *p){
        if(p->topo <= -1)
            return true;
        else
            return false;
    }
//• PILHA_CHEIA
    bool pilhaCheia(pilha *p){
        if(p->topo >= (tamanho-1))
            return true;
        else
            return false;
    }
    void exibirValor(pilha *p,int indice){
        cout <<"\nNome:\t "<< p->registro[indice].nome<< "\nIdade:\t " <<  p->registro[indice].idade<<"\nSalario: ";
        cout << p->registro[indice].salario<<endl;
    }
//• EXIBIR_VALOR_EMPILHADO
    void valorEmpilhado(pilha *p){
        cout << "\nUltimo valor EMPILHADO foi";
        exibirValor(p,p->topo);
        system("pause");
    }
//• EXIBIR_VALOR_DESEMPILHADO
    void valorDesempilhado(pilha *p,int indice){
        cout << "\nUltimo valor DESEMPILHADO foi";
        exibirValor(p,indice);
        system("pause");
    }

//• EXIBIR_PILHA
    void exibirPilha(pilha *p){
        if(p->topo>=0){
            limparTela();
            cout << "\nITENS EMPILHAODS \n";
            for(int i=0; i<=p->topo; i++){
                cout << "\nItem "<<i+1;
                exibirValor(p,i);
            }
        }else{
            cout << "\n------------------------------------------------------";
            cout << "\nA pilha ja esta VAZIA";
            cout << "\nEmpilhe um item para poder EXIBIR";
            cout << "\n------------------------------------------------------\n";
        }
            system("pause");
    }


//• PREENCHER PESSOA
    void preencherPessoa(pilha *p){
        limparTela();
        cout << "\nInforme o nome da Pessoa: ";
        cin >> p->registro[p->topo].nome;
        cout << "\nInforme a idade do(a) "<< p->registro[p->topo].nome <<": ";
        cin >> p->registro[p->topo].idade;
        cout << "\nInforme o salario do(a) "<< p->registro[p->topo].nome<<": ";
        cin >> p->registro[p->topo].salario;
        
    }
//• EMPILHAR
    void empilhar(pilha *p){
        if(pilhaCheia(p)){
            cout << "\n------------------------------------------------------";
            cout << "\nA pilha ja esta CHEIA";
            cout << "\nDesempilhe um item para poder adicionar um novo";
            cout << "\n------------------------------------------------------\n";
            system("pause");
        }else {
            cout << "Empilhando novo registro\n";
            p->topo++;
            preencherPessoa(p);
            valorEmpilhado(p);
        }
    }
//• DESENPILHAR
    void desempilhar(pilha *p){
        if(pilhaVazia(p)){
            cout << "\n------------------------------------------------------";
            cout << "\nA pilha ja esta VAZIA";
            cout << "\nEmpilhe um item para poder remover";
            cout << "\n------------------------------------------------------\n";
            system("pause");
        }else{
            cout << "Removendo ultimo registro\n";
            p->topo--;
            valorDesempilhado(p,p->topo+1);
            
        }
    }
//• CRIE AS FUNÇÕES PARA TRATAMENTO DE MENU E TELA

//• EXIBE O MENU  
    int returnMenu(){
        int opt =-1;
        //•EXIBE O MENU COM SUAS OPÇÕES
        cout << "\nSelecione uma opcao do menu:\n";
        cout << "1- Empilhar\n";
        cout << "2- Desempilhar\n";
        cout << "3- Exibir Pilha\n";
        cout << "4- Sair\n";
        cin >> opt;
        return opt;
    }

int main(){
    
    //• INICIANDO VARIAVEIS 
    pilha pil; //• PILHA
    pil.topo =-1; //• INICIA A PILHA COMO VAZIA
    int opt = -1; //Opcao informada pelo usuario ao menu

    do{
        limparTela();
    //•APRESENTA PROGRAMA PARA MANIPULAÇÃO DE PILHA
        cout << "\nPrograma que manipula pilha";
        opt = returnMenu();
    //•PROCESSA OPCAO SELECIONADA
        switch(opt){
            case 1: //•Empilhar
                empilhar(&pil);
            break;
            case 2: //•Desempilhar
                desempilhar(&pil);
            break;
            case 3: //•Exibir Pilha
                exibirPilha(&pil);
            break;
        }
    }while(opt!= 4);
    return 0;
}
