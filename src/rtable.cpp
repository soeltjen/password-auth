#include "rtable.h"

byte* reduce(string output, string hash){
    byte digest[16];
    md5 MD5 = md5(hash.c_str());
}

void rtable::write_table(std::ofstream& out){
    for(int i =0; i<num_chains; i++){
        genChain(out);
    }
}

void rtable::genChain(std::ofstream& out){
    string init_pass;
    string hash;
    out << init_pass;
    string plaintext = init_pass;
    md5 MD5;
    for(int i = 0; i <=chain_length; i++){
        MD5.md5(plaintext);
    }

}