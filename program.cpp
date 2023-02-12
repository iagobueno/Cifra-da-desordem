#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

int main(int argc, char **argv)
{
    /* checa se os argumentos estão corretos */
    if (check_Arguments(argc, argv))
        return 1;

    /* remove os caracteres repetidos da chave */
    string key = remove_Repeated_Chars();

    /* remove a chave do alfabeto e cria o buffer */
    string alphabet = remove_Key(key);
    string buffer = key;

    /* aplica o problema de Josephus pra embaralhar o alfabeto */
    buffer = josephus(alphabet, buffer);

    /* cria a hash table */
    map<char, char> m = create_Hash(buffer);

    /* abre o arquivo, pega o texto */
    string text = read_Input();

    /* transforma os caracteres em uppercase em lowercase */
    text = to_Lower(text);

    string pre_cipher, cipher;
    if (global_command == encrypt)
    {
        /* chama a função de transposição */
        pre_cipher = transposition(text, key.size());
        /* substitui os caracteres de acordo com a tabela Hash criada. */
        cipher = replace_Char(pre_cipher, m);
    }
    else
    {
        /* substitui os caracteres de acordo com a tabela Hash criada. */
        pre_cipher = replace_Char(text, m);
        /* chama a função de transposição */
        cipher = transposition(pre_cipher, key.size());
    }

    /* escreve o output na tela ou no arquivo destino específicado */
    write_Output(cipher);

    return 0;
}