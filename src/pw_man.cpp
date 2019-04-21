
#include "pw_man.h"
#include "md5.h"

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

    int salt;
    int uid;
    string password;

    int count = 1;

    md5 MD5;
    while (!finished)
    {
        salt = rand();
        cout << "User ID: ";
        cin >> uid;
        file << uid << "," << salt << ",";
        cout << "Salt: " << salt;
        cout << "\nPassword: ";
        cin >> password;
        // cout << "String to be hashed: " << password.c_str() + std::to_string(salt) << "\n";
        MD5 = md5(password.c_str() + std::to_string(salt));
        cout << "Salted Hash: " << MD5 << "\n";
        file << MD5 << "\n";
        file.flush();
    }
    file.close();
}