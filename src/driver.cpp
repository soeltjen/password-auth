

#include "md5.h"
#include "pw_man.h"
#include "rtable.h"
void help(){
    cout <<"\nCommand-Line Options\n\
              ====================\n\
              g : Generate password file\n\
              v : Verify user password\n\
              r : Generate rainbow table\n\
              c : Try to crack hashes\n";
};

int main(int argc, char** argv)
{
    // Main driver
    // Command-line options:
    // 
    // pw_man manager = pw_man();
    char mode;
    int filesize = 99;
    int num_chains = 5000;
    int chain_length = 1000;
    rtable rt(num_chains,chain_length);
    std::fstream p_list;
    p_list.open("p_list");

    std::fstream hash_list;
    hash_list.open("passwords.txt");

    std::fstream rainbow_table;
    rainbow_table.open("rainbow_table");

    if(argc>=1){
        mode = argv[1][1];
        if (mode == 'g'){
            cout << "Generating password file\n";
            pw_man::generate_file(filesize);
        }
        else if(mode=='v'){
            int uid;
            string password;
            cout << "Enter a user ID to verify: ";
            cin >> uid;
            cout << "Enter the password: ";
            cin >> password;
            pw_man::verify(uid, password);
        }
        else if(mode=='r'){
            cout <<"Generating rainbow table\n";

            rt.write_table(rainbow_table);
            cout <<"Finished writing table\n";
 
        }
        else if(mode=='c')
        {
            cout << "Trying to crack hashes\n";
            rt.crack(hash_list,rainbow_table,filesize);
            p_list.close();
            rainbow_table.close();
            hash_list.close();


        }
        else{
            cout <<"\nCommand-Line Options\n\
              ====================\n\
              g : Generate password file\n\
              v : Verify user password\n\
              r : Generate rainbow table\n\
              c : Try to crack hashes\n";
        }
    }
    else{
        cout <<"\nCommand-Line Options\n\
          ====================\n\
          g : Generate password file\n\
          v : Verify user password\n\
          r : Generate rainbow table\n\
          c : Try to crack hashes\n";
    }

    //List of passwords

    p_list.close();
    hash_list.close();
    rainbow_table.close();

}