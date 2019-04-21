

#include <iostream>
#include "md5.h"
#include "pw_man.h"

int main()
{
    // if (argc > 1)
    //     for (int i = 1; i < argc; i++)
    //     {
    //         if (argv[i][0] == '-' && argv[i][1] == 's')
    //     }
    string password;
    int uid;
    // std::cout << "MD5 input: ";
    // std::cin >> password;

    // md5 MD5 = md5(password);
    // std::cout << MD5 << "\n";

    pw_man manager = pw_man();

    manager.generate_file();
    cout << "Enter a user ID to verify: ";
    cin >> uid;
    cout << "Enter the password: ";
    cin >> password;

    manager.verify(uid, password);
}