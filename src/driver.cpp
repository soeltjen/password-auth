#ifndef MD
#define MD MD5
#endif

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "md5.h"

#define TEST_BLOCK_LEN 1000
#define TEST_BLOCK_COUNT 1000

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