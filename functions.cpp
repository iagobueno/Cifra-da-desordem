#include <bits/stdc++.h>
#include "functions.h"
#include <string.h>
using namespace std;

// menu help
void help(char *program_Name){
    PL;
    cout << "Please specify KEY and FILE with plain text."; PL; PL;
    cout << "   " << program_Name << " KEY FILE"; PL; PL;
}

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