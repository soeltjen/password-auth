#include <fstream>
#include <iostream>
#include <sys/random.h>
#include <chrono>
#include <ctime>
#include "pw_man.h"
#include "md5.h"


using std::string;
using std::cout;
using std::cin;
using std::chrono::system_clock;

pw_man::pw_man(){
    generate_file();
}

void pw_man::generate_file(){
    bool finished = false;

    std::ofstream file;
    std::ifstream rand;
    file.open("passwords.txt", std::ios::out);

    int salt, uid;
    string password;

    int count = 1;

    md5 MD5;
    while(!finished){
        auto time = system_clock::now();
        salt = system_clock::to_time_t(time) + count++;
        cout<<"User ID: ";
        cin >> uid;
        file << uid << "," << salt << ",";
        cout << "Salt: " << salt;
        cout << "\nPassword: ";
        cin >> password;
        MD5 = md5(password.c_str()+salt);
        cout << "Salted Hash: " << MD5 << "\n";
        file << MD5 << "\n";
    }

    file.close();
    rand.close();

}