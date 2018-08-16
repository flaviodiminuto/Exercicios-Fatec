    /*b) Fazer o APFE: faça um algoritmo para exibir os vetores: string nome [] = {“Sara
    Lemes”,”Ricardo Jafé”} , double salario [] = {12000, 10243.20} e int idade[]={30, 45};
    O salário deverá ser exibido com 10% de aumento.*/
    #include <iostream>
    #include <string>

    using namespace std;

    // Recebe o campo, valor, formata o testo e imprime
    void imprimir(string campo, string valor ){
        cout << campo <<": "<< valor<<"\n";
    }

    int main(){
        string nome [] = {"Sara Lemes","Ricardo JafC)"};
        double salario [] = {12000, 10243.20};
        int idade[]={30, 45};
        int max = sizeof(idade)/sizeof(int);

        for(int i=0; i< max; i++){
            imprimir("\nnome",nome[i]);
            imprimir("idade",to_string(idade[i]));
            imprimir("salario",to_string(salario[i]));
            
        }
        return 0;
    }