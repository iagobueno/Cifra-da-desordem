#ifndef __FUNCTIONS__
#define __FUNCTIONS__

/*----------------------------------------- INCLUDES */

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

/*----------------------------------------- DEFINES */

enum command
{
    encrypt,
    decrypt
};

#define PL cout << "\n"   /* PL = pula linha*/
#define RESET "\033[0m"   /* reseta a cor */
#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define BLUE "\033[34m"   /* Blue */

/*----------------------------------------- GLOBAL */

inline string global_key;
inline command global_command;
inline bool global_verbose = false;
inline char *global_input;
inline char *global_output;

/*----------------------------------------- FUNCTIONS */

int check_Arguments(int argc, char **argv);

string remove_Repeated_Chars();

string to_Lower(string str);

string remove_Key(string key);

string josephus(string alphabet, string buffer);

string transposition(string text, int k);

map<char, char> create_Hash(string buffer);

string read_Input();

void write_Output(string e);

string replace_Char(string text, map<char, char> m);

#endif