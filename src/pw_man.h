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
    void generate_file();
    void verify(int uid, string password);
    std::fstream pw_file;
    std::ifstream source;

private:
    // std::fstream pw_file;
    // std::ifstream source;
};

#endif