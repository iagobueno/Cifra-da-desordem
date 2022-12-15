#include <bits/stdc++.h>
#include <string.h>
#include <iostream> 
#include <fstream>
#include "functions.h"

using namespace std;

int main(int argc, char **argv)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // checa se os argumentos estão corretos
    if(check_Arguments(argc, argv))
        return 1;

    // pega a chave e remove os caracteres repetidos
    string b(argv[1]);
    string key = removeRepeatedChars(b);
    int iterador = key.size();

    // cria a lista
    string create_List(key);

    // abre o arquivo, pega o texto e o trata
    std::ifstream myfile ("./texto.txt");
    string text;

    if ( myfile.is_open() ) {
        string buffer;
        while ( myfile ){
            myfile >> buffer;
            text.append(buffer); 
        }
    }
    
    // cout << text; PL;

    return 0;
}