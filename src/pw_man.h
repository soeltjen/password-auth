#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

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

private:
    std::fstream pw_file;
};