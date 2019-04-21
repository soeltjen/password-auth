#include <fstream>
#include <iostream>
#include <ctime>
#include "pw_man.h"
#include "md5.h"

using std::cin;
using std::cout;
using std::string;

pw_man::pw_man()
{
    generate_file();
}

void pw_man::generate_file()
{
    srand(time(NULL));
    bool finished = false;

    std::ofstream file;
    file.open("passwords.txt", std::ios::out);

    int salt = rand();
    int uid;
    string password;

    int count = 1;

    md5 MD5;
    while (!finished)
    {
        cout << "User ID: ";
        cin >> uid;
        file << uid << "," << salt << ",";
        cout << "Salt: " << salt;
        cout << "\nPassword: ";
        cin >> password;
        MD5 = md5(password.c_str() + salt);
        cout << "Salted Hash: " << MD5 << "\n";
        file << MD5 << "\n";
    }

    file.close();
}