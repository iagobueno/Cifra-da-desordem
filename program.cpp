#include <bits/stdc++.h>
#include <string.h>
#include <iostream> 
#include <fstream>
#include "functions.h"

using namespace std;

int main(int argc, char **argv)
{
    // checa se os argumentos estão corretos
    if(check_Arguments(argc, argv))
        return 1;

    // remove os caracteres repetidos da chave
    string key = remove_Repeated_Chars();

    // remove a chave do alfabeto e cria o buffer
    string alphabet = remove_Key(key);
    string buffer = key;

    // aplica o problema de Josephus pra embaralhar o alfabeto
    buffer = josephus(alphabet, buffer);

    // cria a hash table
    map<char, char> m = create_Hash(buffer);

    // abre o arquivo, pega o texto e o trata
    string text = read_Input();

    // transforma os caracteres em uppercase em lowercase
    text = to_Lower(text);

    // substitui os caracteres de acordo com a tabela Hash criada.
    string e = replace_Char(text, m);
    
    write_Output(e);

    return 0;
}