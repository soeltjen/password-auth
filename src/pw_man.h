#ifndef PW_MAN
#define PW_MAN

#include <fstream>
#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::string;

class pw_man
{
public:
    int filesize;
    pw_man();
    static void generate_file(int filesize);
    static void verify(int uid, string password);

private:
};

#endif