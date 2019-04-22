
#include "pw_man.h"
#include "md5.h"

pw_man::pw_man()
{
    filesize=99;
    // generate_file();
}

void pw_man::generate_file()
{
    srand(time(NULL));
    std::ifstream source;
    source.open("p_list");

    pw_file.open("passwords.txt");

    int salt;
    int uid;
    string password;

    int count = 1;

    md5 MD5;
    std::stringstream stream;
    for (int i = 1; i < filesize; i++)
    {
        salt = rand() + (count++);
        stream << salt;
        source >> password;

        uid = i;
        pw_file << uid << " " << salt << " ";
        MD5 = md5(password.c_str() + stream.str());
        pw_file << MD5 << "\n";
        pw_file.flush();
        cout << "User " << i << "'s password: " << password << " Salt: "<< salt << " Hash: " << MD5 << "\n";
    }
    source.close();
    pw_file.close();
}

void pw_man::verify(int uid, string password)
{
    pw_file.open("passwords.txt");
    // std::stringstream stream;
    int id;
    string salt;
    string hash;
    string newHash;
    md5 MD5;
    bool found = false;

    while(!found){
        pw_file >> id >> salt >> hash;
        if(id==uid){
            found=true;
            cout << "found user " << uid << " in file.\n";
        }
    }

    if(found)
    {
        // cout << "ID: " << id << "salt: " << salt << "hash: " << hash << '\n';
        MD5 = md5(password.c_str() + salt);
        newHash = MD5.Print();

        //check if generated hash matches file hash.
        // cout << newHash << " = " << hash << "\n";

        cout << id  << " " << salt  << " " << hash << "\n";
        // cout << hash << "\n" << newHash << "\n";
        cout << "Hashing " << password << "+" << salt << ": " << newHash << "\n";
        if (!newHash.compare(hash))
        {
            // cout << hash << "\n" << newHash << "\n";
            cout << "\nUser " << uid << " password is verified.\n";
        }
        else
        {
            cout << "User was not verified\n";
        }
        
    }
    else
    {
        cout << "User was not found\n";
    }
    pw_file.close();

}