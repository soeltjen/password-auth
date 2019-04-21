
#include <iostream>
#include "md5.h"

int main()
{
    // if (argc > 1)
    //     for (int i = 1; i < argc; i++)
    //     {
    //         if (argv[i][0] == '-' && argv[i][1] == 's')
    //     }
    string message;
    std::cout << "MD5 input: \n";
    std::cin >> message;

    md5 MD5 = md5(message);
}