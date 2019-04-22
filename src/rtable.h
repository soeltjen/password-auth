#include <fstream>
#include "md5.h"

class rtable{
public:
    int num_chains;
    int chain_length;
    void write_table(std::ofstream& out);

private:
    void genChain(std::ofstream& out);
};