

#include "md5.h"
#include "pw_man.h"

int main(int argc, char** argv)
{
    // Main driver
    // Command-line options:
    // 
    pw_man manager = pw_man();
    if (argc > 1)
        for (int i = 1; i < argc; i++)
        {
            if (argv[i][0] == '-' && argv[i][1] == 'g')
                manager.generate_file();
        }

    string password;
    int uid;

    md5 MD5;

    cout << "Enter a user ID to verify: ";
    cin >> uid;
    cout << "Enter the password: ";
    cin >> password;
    manager.verify(uid, password);
}