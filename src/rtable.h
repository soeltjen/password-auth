#include <fstream>
#include <iostream>
#include <ostream>
#include <map>
#include "md5.h"

class rtable{
public:
    rtable(int chains, int length);
    int num_chains;
    int chain_length;
    std::map<string,string> hashMap;
    char password[8];
    void write_table(std::fstream& out);
    bool searchChain(string start, string hash);
    bool searchHash(std::fstream& rt, string &hash);
    void crack(std::fstream& pw_file, std::fstream &rt, int size);
    string to_plaintext(byte* bin);
    void gen_password();

private:
    void genChain(std::fstream& out);
    static string reduce(string str);
};