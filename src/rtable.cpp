#include "rtable.h"


rtable::rtable(int chains, int length){
    num_chains = chains;
    chain_length = length;
}
string rtable::reduce( string hash){
    string digest;
    digest = md5::Digest(hash);
    // std::cout << hash << " -> " << digest << "\n";
    return digest.c_str();
}

// Generates a rainbow table
// input is a filestream of passwords
// out is a filestream for the rainbow table to be generated
void rtable::write_table(std::fstream& out){
    string pass;
    for(int i =0; i<num_chains; i++){
        // std::cout <<"Generating  chain " << i << "\n";
        genChain(out);
        out << "\n";
    }
}
void rtable::gen_password(){
    for(int i = 0; i < 8; i++){
        password[i]= '0'+(rand()%64);
    }
}

void rtable::genChain(std::fstream& out){
    // std::cout << "Generating chain: \n";
    gen_password();
    string init_pass = password;
    // std::cout << init_pass << std::endl;
    string hash;
    out << init_pass << " ";
    string plaintext = init_pass;
    for(int i = 0; i <=chain_length; i++){
        hash = md5::Digest(plaintext);
        // std::cout << plaintext << "-> "<< hash << " -> ";
        plaintext = reduce(hash);
    }
    hash = md5::Digest(plaintext);
    // std::cout << plaintext << " -> " << hash << "\n";

    out << plaintext;

}

bool rtable::searchChain(string start, string hash){
    bool found = false;
    string out;
    int i =0;
    while(!found && i < chain_length){
        out = md5::Digest(start);
        if(!hash.compare(out)){
            found = true;
            std::cout << "Hash: " << hash << " Password: " << out << "\n";
            return found;
        }
        out = reduce(out);
        i++;
    }
    return found;
}

bool rtable::searchHash(std::fstream& rt, string& hash){

    // std::map<string,string> hashTable;
    std::map<string,string>::iterator it;
    string password;
    while(!rt.eof()){ 
        rt >> password >> hash;
        std::cout <<"Trying to insert (" << password << "," << hash << ")\n";
        hashMap.insert(std::pair<string,string>(hash,password));
    }
    // std::cout << "Hashmap built\n";

    bool found = false;
    int i = 0;


    while(!found && i < chain_length){
        std::cout << "i=" << i << "\n";
        if((it = hashMap.find(hash))!=hashMap.end()){
            string password = it->second;
            if(searchChain(password,hash)){
                hash = password;
                found = true;
                std::cout << "Found password: " << hash <<"\n";
            }
            else{
                std::cout <<"Password not found in chain\n";
                for(int j =0; j < i; j++){
                    password = reduce(hash);
                    hash = md5::Digest(password);
                }
            }
        }
        else{
            std::cout << "Password not found in map\n";
            for(int j = 0; j < i; j++){
                password = reduce(hash);
                hash = md5::Digest(password);
            }
        }
        i++;
    }
    return found;
}
void rtable::crack(std::fstream& pw_file, std::fstream& rt,int size){
    int uid;
    string salt, hash;
    for(int i=0; i < size; i++){
        pw_file >> uid >> salt >> hash;
        std::cout << "Trying to crack user " << uid << "'s password. Hash: " << hash << "\n";
        if(searchHash(rt,hash)){
            std::cout << "Password for user " <<uid<<": "<< hash<<"\n";
        }
    }
}