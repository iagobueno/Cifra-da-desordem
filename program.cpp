#include <bits/stdc++.h>
#include <string.h>
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

    // abre o arquivo, pega o texto e o trata
    string plain = "MACONHA";
    plain = to_Lower(plain);

    cout << key; PL;
    cout << plain; PL;

    return 0;
}