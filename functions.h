#ifndef __FUNCTIONS__
#define __FUNCTIONS__

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define PL cout << "\n"

int check_Arguments(int argc, char **argv);

string remove_Repeated_Chars(string str);

string to_Lower(string str);

string remove_Key(string key);

string josephus(string alphabet, string buffer);

map<char, char> create_Hash(string buffer);

string encrypt(string text, map<char, char> m);

#endif