#include "functions.h"
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <iostream>

using namespace std;

/* menu help */
void help(char *program, char opt)
{
    PL;

    switch (opt)
    {
    // quick
    case 'q':
        cout << "Please specify a " << RED << "${KEY}" << RESET << " and a " << GREEN << "${COMMAND} " << RESET << "as the following example:";
        PL;
        PL;
        cout << "   " << program << " -k " << RED << "${KEY}" << RESET << " -c " << GREEN << "${COMMAND}" << RESET << "";
        PL;
        PL;
        cout << "To see more detailed information, use " << program << " -h.";
        PL;
        PL;
        break;
    case 'e':
        cout << "You're allowed to use the following characters to your " << RED << "${KEY}" << RESET << ":";
        PL;
        cout << " * " << RED << "alphabetic characters a-z" << RESET;
        PL;
        cout << " * " << RED << "numeric characters 0-9" << RESET;
        PL;
        PL;
        cout << "The following " << GREEN << "${COMMAND}" << RESET << "s are available:";
        PL;
        cout << " * " << GREEN << "encrypt" << RESET << "";
        PL;
        cout << " * " << GREEN << "decrypt" << RESET << "";
        PL;
        PL;
        cout << "Optional arguments:";
        PL;
        cout << " * -i, input file.";
        PL;
        cout << " * -o, output file.";
        PL;
        cout << " * -v, verbose mode.";
        PL;
        PL;
        cout << "Example of usage:";
        PL;
        PL;
        cout << "   ./encrypt -k albini2022 -c encrypt -i \"/home/user/input.txt\"";
        PL;
        PL;
        break;
    default:
        exit(1);
    }
}

/* confere se os argumentos estão de acordo com o esperado */
int check_Arguments(int argc, char **argv)
{

    // Se nenhum argumento foi informado
    if (argc == 1)
    {
        help(argv[0], 'q');
        return 1;
    }

    int option;
    int c = 0;
    int k = 0;

    while ((option = getopt(argc, argv, "k:c:i:o:hv")) != -1)
    {
        switch (option)
        {
        case 'h':
            help(argv[0], 'e');
            return 2;
            break;

        case 'k':
            k = 1;
            global_key = optarg;
            break;

        case 'c':
            c = 1;
            if (!strcmp(optarg, "encrypt"))
            {
                global_command = encrypt;
            }
            else if (!strcmp(optarg, "decrypt"))
                global_command = decrypt;
            else
            {
                help(argv[0], 'q');
                exit(1);
            }
            break;

        case 'i':
            global_input = optarg;
            break;

        case 'o':
            global_output = optarg;
            break;

        case 'v':
            global_verbose = true;
            break;

        default:
            exit(3);
            break;
        }
    }

    // Check mandatory parameters:
    if (!c || !k)
    {
        help(argv[0], 'q');
        exit(1);
    }

    return 0;
}

/* remove as letras repetidas da chave */
string remove_Repeated_Chars()
{
    map<char, int> repeated;
    string key;

    int i;
    for (i = 0; i < global_key.size(); i++)
    {

        /* se a letra não apareceu, incorpora na chave */
        if (!repeated[global_key[i]])
        {
            key.push_back(global_key[i]);
        }
        /* marca que a letra já apareceu */
        repeated[global_key[i]]++;
    }

    return key;
}

/* deixa o texto em lowercase */
string to_Lower(string str)
{
    /* percorre o texto aplicando a função de lowercase */
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);

    return str;
}

/* remove as letras da chave do alfabeto e coloca no nosso buffer */
string remove_Key(string key)
{
    /* declara uma string que contém o alfabeto */
    string str = "abcdefghijklmnopqrstuvwxyz0123456789";

    /* para cada letra da chave, remove-a do alfabeto */
    for (int i = 0; i < key.size(); i++)
    {
        str.erase(remove(str.begin(), str.end(), key[i]), str.end()); // remove key from string
    }

    /* retorna o alfabeto sem as letras da chave */
    return str;
}

/* usa a função de josephus remover as letras do alfabeto e colocar no buffer */
string josephus(string alphabet, string buffer)
{

    int k = buffer.size();
    int n = alphabet.size();

    /* Cria um Lista e Preenche a lista com o Alfabeto Já sem a chave */
    list<char> l;
    for (int i = 0; i < n; i++)
    {
        l.push_back(alphabet[i]);
    }

    /* Coloca o Ponteiro da lista no início */
    list<char>::iterator it = l.begin();

    /* Enquanto existir elemento na lista... */
    /* a cada K intervalo, tira uma letra da lista e adiciona ao Buffer */
    while (!l.empty())
    {

        /* Anda o intervalo k */
        for (int j = 0; j < k - 1; j++)
        {
            /* Se a lista chegou ao fim, precisa atualizar o ponteiro para o início */
            it++;
            if (it == l.end())
            {
                it = l.begin();
            }
        }

        /* adiciona o elemento ao buffer */
        buffer.push_back(*it);

        /* cout << *it << "\n"; DEBUG */
        /* deleta o elemento da lista */
        it = l.erase(it);

        /* Se a lista chegou ao fim, precisa atualizar o ponteiro para o início */
        if (it == l.end())
        {
            it = l.begin();
        }
    }

    if (global_verbose)
    {
        PL;
        cout << "buffer: " << buffer;
        PL;
    }

    return buffer;
}

string transposition(string text, int k)
{
    /* Se tiver char \n no fim da string, é removido */
    if (text[text.size() - 1] == '\n')
    {
        text.pop_back();
    }

    /* Se o texto não for divisível pelo tamanho da chave, preenche com lixo */
    for (; (text.size() % k) != 0;)
    {
        text.push_back(k + '0');
    }

    int n = text.size();
    string buffer;

    if (global_verbose)
    {
        PL;
        cout << "text: " << text;
        PL;
    }

    /* a cada K intervalo, tira uma letra da lista e adiciona ao Buffer */
    if (global_command == encrypt)
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n / k; j++)
                buffer.push_back(text[j * k + i]);
        }
    }
    else
    {
        for (int i = 0; i < n / k; i++)
        {
            for (int j = 0; j < k; j++)
                buffer.push_back(text[j * (n / k) + i]);
        }
    }

    if (global_verbose)
    {
        PL;
        cout << "buffer: " << buffer;
        PL;
    }

    if (global_command == decrypt)
    {
        n = buffer.size();
        for (; buffer[n - 1] == (k + '0'); n--)
        {
            buffer.pop_back();
        }
    }

    return buffer;
}

map<char, char> create_Hash(string buffer)
{

    int i, offset;
    map<char, char> m;

    if (global_command == encrypt)
    {
        i = 0;
        m[buffer[buffer.size() - 1]] = buffer[0];
        offset = 1;
    }
    else
    {
        m[buffer[0]] = buffer[buffer.size() - 1];
        m[buffer[buffer.size() - 1]] = buffer[buffer.size() - 2];
        i = 1;
        offset = -1;
    }

    for (; i < buffer.size() - 1; i++)
    {
        m[buffer[i]] = buffer[i + offset];
    }

    return m;
}

string read_Input()
{

    string text;

    std::ifstream myfile(global_input);
    if (global_input)
    {

        std::stringstream buffer;
        buffer << myfile.rdbuf();

        return (string)(buffer.str());
    }
    else
    {
        cout << "Entre com o texto a ser encryptado:";
        PL;
        PL;
        getline(cin, text);
        return text;
    }
}

void write_Output(string e)
{

    string text;

    if (global_output)
    {
        ofstream myfile(global_output);

        if (myfile.is_open())
        {
            myfile << e << endl;
        }
        else
        {
            cout << "Could not open output file.";
            PL;
        }
    }
    else
    {
        if (global_command == encrypt)
            cout << "Encrypted: ";
        else
            cout << "Decrypted: ";
        cout << e;
        PL;
    }
}

string replace_Char(string text, map<char, char> m)
{

    string e;
    int i;
    for (i = 0; i < text.size(); i++)
    {
        // if ( (text[i] >= '0' && text[i] <= '9') || (text[i] >='a' && text[i] <= 'z') || (text[i] == ',') )
        if ((text[i] >= '0' && text[i] <= '9') || (text[i] >= 'a' && text[i] <= 'z'))
            e.push_back(m[text[i]]);
        else
            e.push_back(text[i]);
    }

    return e;
}