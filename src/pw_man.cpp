
#include "pw_man.h"
#include "md5.h"

pw_man::pw_man()
{
    // generate_file();
    // pw_file.open("passwords.txt", std::ios::in || std::ios::out);
}

void pw_man::generate_file()
{
    srand(time(NULL));
    bool finished = false;

    pw_file.open("passwords.txt", std::ios::out);

    int salt;
    int uid;
    string password;

    int count = 1;

    md5 MD5;
    std::stringstream stream;
    for (int i = 0; i < 2; i++)
    {
        salt = rand();
        cout << "User ID: ";
        cin >> uid;
        pw_file << uid << " " << salt << " ";
        cout << "Salt: " << salt;
        cout << "\nPassword: ";
        cin >> password;
        // cout << "String to be hashed: " << password.c_str() + std::to_string(salt) << "\n";
        stream << salt;
        MD5 = md5(password.c_str() + stream.str());
        cout << "Salted Hash: " << MD5 << "\n";
        pw_file << MD5 << "\n";
        pw_file.flush();
    }
    pw_file.close();
}

void pw_man::verify(int uid, string password)
{
    pw_file.open("passwords.txt", std::ios::in);
    int id;
    string salt;
    string hash;
    string newHash;
    md5 MD5;
    bool found = false;
    int i;
    pw_file >> id >> salt >> hash;
    // cout << "here\n";
    while (i < 5)
    {
        // cout << "ID: " << id << "salt: " << salt << "hash: " << hash << '\n';
        // cout << "in while\n";
        MD5 = md5(password.c_str() + salt);
        newHash = MD5.Print();

        //check if generated hash matches file hash.
        // cout << newHash << " = " << hash << "\n";
        if (!newHash.compare(hash))
        {
            std::cout << "User " << uid << " password is verified.";
        }
        found = (id == uid);
        pw_file >> id;
        pw_file >> salt;
        pw_file >> hash;
        i++;
    }
}