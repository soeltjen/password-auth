

#include <iostream>
#include "md5.h"

int main()
{
    // if (argc > 1)
    //     for (int i = 1; i < argc; i++)
    //     {
    //         if (argv[i][0] == '-' && argv[i][1] == 's')
    //     }
    string password;
    std::cout << "MD5 input: ";
    std::cin >> password;

    md5 MD5 = md5();
    MD5.Digest(password);
}