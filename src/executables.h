#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;

typedef int (*CommandFunction)(vector<string>&);

unordered_map<string, CommandFunction> command_functions;

int pwd(vector<string> &input) {
    char buf[256];
    getcwd(buf, 256);
    cout << buf << endl;

    return 1;
}

int cd(vector<string> &input) {
    if (input.size() != 2) {
        cout << "Usage: cd <DIRECTORY>" << endl;
        return 1;
    }

    if (chdir(input[1].c_str()) != 0) {
        cout << "Unexpected error occurred in cd" << endl;
    }
    return 1;
}

int exit(vector<string> &input) {
    cout << "Exiting sakanaSh" << endl;
    return 0;
}


void setup_commands() {
    command_functions["cd"] = cd;
    command_functions["pwd"] = pwd;
    command_functions["exit"] = exit;
}