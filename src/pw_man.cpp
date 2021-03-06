
#include "pw_man.h"
#include "md5.h"

pw_man::pw_man()
{
    filesize=99;
    // generate_file();
}

void pw_man::generate_file(int filesize)
{
    srand(time(NULL));
    std::ifstream source;
    std::ofstream pw_file;
    source.open("p_list");

    pw_file.open("passwords.txt");

    int salt;
    int uid;
    string password;
    string salted_password;
    string hash;

    std::stringstream stream;
    for (int i = 1; i <= filesize; i++)
    {
        salt = rand() + i;
        stream << salt;
        source >> password;

        uid = i;
        pw_file << uid << " " << salt << " ";
        salted_password = password.c_str() +stream.str();
        hash = md5::Digest(salted_password);
        pw_file << hash << "\n";
        pw_file.flush();
        stream.str(std::string());

        // cout << "User " << i << "'s password: " << password << " Salt: "<< salt << " Hash: " << MD5 << "\n";
    }
    source.close();
    pw_file.close();
}

void pw_man::verify(int uid, string password)
{
    std::ifstream pw_file;
    pw_file.open("passwords.txt");
    int id;
    string salt;
    string hash;
    string newHash;
    bool found = false;

    while(!found){
        pw_file >> id >> salt >> hash;
        if(id==uid){
            found=true;
        }
    }

    if(found)
    {
        newHash = md5::Digest(password.c_str() + salt);


        cout << hash << "\n" << newHash << "\n";
        if (!newHash.compare(hash))
        {
            cout << "User " << uid << " password is verified.\n";
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