#include <iostream>
#include <string>
using namespace std;
int main(){
    string nome;
    cout << "Informe o seu nome!" << endl;
    cin >> nome;
    cout << "Ola Mundo!" << " " << nome << endl;
    //Declaração de um ponteiro tipo * nome_variavel
    int * pint = nullptr;
    int vint;
    //Atribuição de um ponteiro; variavel ponteiro = &variável_alvo
    pint = &vint;

    vint = 10;
    //escrevendo na variável vint por meio do pint.
    *pint = 20;

    delete pint;

    int vetor[10];
    
    int contador = 0;
    while (contador < 10){
        vetor[contador] = contador;
        contador++;
    }
    cout << *pint << endl;
    for (int i = 0; i < 10; i++){
        cout << i << endl;    
        if(i % 2 == 0)
        { 
            cout << i << " é par" << endl;
        }
        else 
            cout << i << "é impar" << endl;
    }

       
    
    return 0;
}