/*2. Melhore o programa 4, faÃ§a um menu para operar o programa4, crie notas funÃ§Ãµes:
a. Crie uma funÃ§Ã£o que busque e exclua um dos nÃ³dulos da estrutura mantendo a
integridade, isto Ã©, o nÃ³dulo anterior ao que for excluÃ­do deverÃ¡ apontar para o nÃ³
posterior ao que foi excluÃ­do. Se o nÃ³ excluÃ­do for o primeiro entÃ£o o prÃ³ximo nÃ³
deverÃ¡ se tornar o primeiroNo. Se o nÃ³ excluÃ­do for o Ãºltimo nÃ³ entÃ£o o nÃ³ anterior ao
Ãºltimo deverÃ¡ ser o novo ultimoNo.
b. Crie funÃ§Ã£o que informe se a estrutura estÃ¡ vazia.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct me cad;
int cont=0;
struct me { int pos; cad * liga; };

cad * ultimoNo; cad * primeiroNO;

int exibir_menu(){
    int opt;
    opt =-1;
    cout<<"1- Alocar\n";
    cout<<"2- Exibir\n";
    cout<<"3- Excluir\n";
    cout<<"4- Exibir tudo\n";
    cout<<"5- Excluir tudo\n";
    cout<<"6- Sair\n";
    cin >> opt;
    return opt;
}
bool vazia(){
    if(cont==0){
        cout <<"A estrutura esta vazia! \n\n";
        return true;
    }else{
        return false;
    }
}

void alocar () { 
    cont ++;
    cad * newcad = (cad*) malloc ( sizeof ( cad ) );
    if ( cont == 1 ) { newcad->liga = NULL;
        newcad->pos=cont;
        primeiroNO=newcad;
        ultimoNo = newcad;
    }else{ 
        ultimoNo->liga = newcad;
        newcad->liga=NULL;
        newcad->pos=cont; 
    }
    ultimoNo=newcad; 
 }
 
void exibir_tudo() { 
    cad * temp; 
    int itera = 0;
    temp = primeiroNO;
    while ( temp != NULL) { 
        itera+=1;
        cout << "posicao: "<< temp->pos << " esta no endereco " << temp << " na memoria\n";
        temp = temp->liga;
    }
    if(itera ==0){
        cout << "\nEstrutura nao pode ser exibida pois esta vazia\n";
    }
    cout << "\nForam listados "<< itera << " itens\n";
 }
void reordenar(){
    cad * temp;
    temp = primeiroNO;
    int indice =1;
    while ( temp != NULL){
        temp->pos = indice;
        indice++;
        temp= temp->liga;
    }
    cout << "\nReordenando itens\n";
    cout << "Primeira posicao: "<<primeiroNO->pos;
    cout << "\nUltima posicao: "<<ultimoNo->pos<<"\n";
    exibir_tudo();
}
void destruir_tudo() { 
    cad * temp; 
    cad * temp_aux;
    temp = primeiroNO;
    while ( temp != NULL){
        temp_aux = temp->liga;
        free(temp); 
        delete temp;
        temp = temp_aux;
    }
    free (primeiroNO); free (ultimoNo);
    primeiroNO = NULL; ultimoNo = NULL;
    cont = 0;
}
int seleciona_posicao(){
    int pos= -1;
    bool opt_valida=false;
    if(cont >= 2){
        do{
            cout << "Selecione uma estrutura entre "<< primeiroNO->pos << " e " << ultimoNo->pos<<"\n";
            cin >> pos;
            if((int)pos >= primeiroNO->pos && (int)pos <= ultimoNo->pos){
                opt_valida = true;
                return pos;
                }
        }while(!opt_valida);
    }else{
        cout << "Unica posicao cadastrada eh a posicao "<< primeiroNO->pos << "\n";
        return 1;
    }
}

cad* buscar(int pos){
        cad * temp; 
        temp = primeiroNO;
        for(int i = 1; i<= cont; i++){
            if(temp->pos==pos){
            return temp;
            }else{
            temp = temp->liga;
            }
        }
        return NULL;
}


void exibir(){
    cad * temp;
    if(!vazia()){
    int pos=seleciona_posicao();
    temp = buscar(pos);
    cout << "posicao: "<<
    temp->pos << " esta na posicao " << temp << " memoria\n"<< endl;
    }
}
void destruir_item(){
    cad * temp;
    if(vazia()){
        cout << "A lista precisa ter itens para poder remover\n";
    }else{
        int opt = seleciona_posicao();
        if(opt==1){
            if(opt == cont){
                free(primeiroNO);free(ultimoNo);
                primeiroNO = NULL;ultimoNo = NULL;
                cont = 0;
            }else{
                temp = primeiroNO;
                primeiroNO = primeiroNO->liga;
                free(temp); temp = NULL;
                cont--;
                reordenar();
            }
        }else{
            cad * pos_anterior;
            pos_anterior= buscar(opt-1);
            temp = pos_anterior->liga;
            pos_anterior->liga = pos_anterior->liga->liga;
            if(temp == ultimoNo)
                ultimoNo = pos_anterior;
            free(temp); temp = NULL;
            reordenar();
        }
        cout << "\nDestruindo um item da estrutura na posicao "<<opt<<"\n";
    }
}


void operacao(int opt){
    switch(opt){
        case 1:
            alocar();
            cout << "\nNovo valor alocado\n";
            break;
        case 2:
            exibir();
            break;
        case 3:
            destruir_item();
            break;
        case 4:
            exibir_tudo();
            break;
        case 5:
            destruir_tudo();
            cout << "\nEstrutura zerada e memoria liberada\n";
            break;
        case 6:
        	destruir_tudo();
            break;
        default:
            cout << "\nSELECIONE UMA ALTERNATIVA NUMERADA NO MENU\n";
            system("pause");
    }
    system("pause");
}
int main() { 
    int opt =-1;
    do{
        opt = exibir_menu();
        operacao(opt);
    }while(opt!=6);
}
