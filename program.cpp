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

    // pega a chave, remove os caracteres repetidos e guarda o iterador
    string key(argv[1]);
    key = remove_Repeated_Chars(key);

    // remove a chave do alfabeto e cria o buffer
    string alphabet = remove_Key(key);
    string buffer = key;

    // aplica o problema de Josephus pra embaralhar o alfabeto
    buffer = josephus(alphabet, buffer);

    // cria a hash table
    map<char, char> m = create_Hash(buffer);

    // abre o arquivo, pega o texto e o trata
    std::ifstream myfile ("./texto.txt");

    string text;
    std::string myline;
    if ( myfile.is_open() ) {

        while ( myfile ) {
            std::getline (myfile, myline);
            text.append(myline);
        }

    }

    cout << text; PL;
    text = to_Lower(text);
    cout << "texto: " << text; PL;

    // criptografa o texto
    string e = encrypt(text, m);
    cout << "encry: " << e; PL;

    return 0;
}