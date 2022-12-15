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

    // pega a chave da stdin
    string key(argv[1]);

    map<char, int> repeated;
    string str;
   
    str.

    int i;
    for(i = 0 ; i < key.size(); i++){
        // se a letra não apareceu
        if(!repeated[key[i]]){
            str.append(key[i]);
        }
        repeated[key[i]]++;

        // cout<< repeated[key[i]]; PL;
    }

    cout << str; PL;

    return 0;
}