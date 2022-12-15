#include <bits/stdc++.h>
#include "functions.h"
#include <string.h>

using namespace std;

// Menu help
void help(char *program){
    PL;
    cout << "Please specify a KEY and a FILE with plain text."; PL; PL;
    cout << "   " << program << " KEY FILE"; PL; PL;
    cout << "KEY is a string in the command line."; PL; PL;
    cout << "FILE is a file with regular ASCII characters."; PL; PL;
}

// Confere se os argumentos estão de acordo com o esperado
int check_Arguments(int argc, char **argv){

    // Se o primeiro argumento é -h ou --help
    if(argc == 1){
        help(argv[0]);
        return 1;
    }
    if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
        help(argv[0]);
        return 2;
    }    

    // Verifica se o algoritmo tem 2 argumentos.
    if(argc != 3)
    {
        help(argv[0]);
        return 3;
    }

    return 0;
}

// Remove as letras repetidas da chave
string removeRepeatedChars(string str){
    
    map<char, int> repeated;
    string key;

    int i;
    for(i = 0 ; i < str.size(); i++){

        // se a letra não apareceu, incorpora na chave
        if(!repeated[str[i]]){
            key.push_back(str[i]);
        }
        // marca que a letra já apareceu
        repeated[str[i]]++;

    }

    return key;
}

// deixa o texto em lowercase
string to_Lower(string str){

    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);

    return str;
}

string create_List(string key){

    cout << "sdjfoiasdjf"; PL;

    string str = "abcdefghijklmnopqrstuvwxyz0123456789";
    cout << key; PL;

    int i;
    for(i = 0 ; i < key.size(); i++){

        str.erase(remove(str.begin(), str.end(), key[i]), str.end()); //remove key from string

    }

    cout << str; PL;
    return str;
}
