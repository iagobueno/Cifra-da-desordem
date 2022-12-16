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
string remove_Repeated_Chars(string str){
    
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

string remove_Key(string key){

    string str = "abcdefghijklmnopqrstuvwxyz0123456789";

    int i;
    for(i = 0 ; i < key.size(); i++){

        str.erase(remove(str.begin(), str.end(), key[i]), str.end()); //remove key from string

    }

    return str;
}

string josephus(string alphabet, string buffer){

    int k = buffer.size();
    int n = alphabet.size();

    list<char> l;

    for (int i = 0; i < n; i++) {
        l.push_back(alphabet[i]);
    }

    list<char>::iterator it = l.begin();

    while (!l.empty()) {

        for (int j = 0; j < k-1; j++) {
            it++;
            if (it == l.end()) {it = l.begin(); }
        }

        buffer.push_back(*it);

        // cout << *it << "\n";
        it = l.erase(it);

        if (it == l.end()){
            it = l.begin();
        }
    }

    return buffer;
}

map<char, char> create_Hash(string buffer){

    int i;
    map<char,char> m;
    for(i = 0 ; i < buffer.size() - 1; i++){
        m[buffer[i]] = buffer[i+1];
    }
    m[buffer[i]] = buffer[0];

    // map<char, char>::iterator it;

    // for( it = m.begin(); it !=m.end(); ++it){
    //     cout << it->first << " => " << it->second << '\n';
    // }

    // string str = "0123456789abcdefghijklmnopqrstuvwxyz";
    // for( int j=1, i=0, k=0; j<=36; j++){
    //     cout << "| " << str[i] << " | " << m[str[i]] << " |     ";
        
    //     i+=6;
    //     if(j%6 == 0){
    //         PL;
    //         i = ++k;
    //     }
    // }

    return m;
}

string encrypt(string text, map<char, char> m){

    string e;
    int i;
    for(i = 0 ; i < text.size(); i++){
        if ( (text[i] >= '0' && text[i] <= '9') || (text[i] >='a' && text[i] <= 'z') )
            e.push_back(m[text[i]]);
        else
            e.push_back(text[i]);
    }

    return e;
}