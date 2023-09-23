#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef int (*CommandFunction)(vector<string>&);

unordered_map<string, CommandFunction> command_functions;

int ls(vector<string> &input) {
    // TODO
    cout << "ls called" << endl;
    return 1;
}

int cd(vector<string> &input) {
    // TODO
    cout << "cd called" << endl;
    return 1;
}

int exit(vector<string> &input) {
    cout << "Exiting sakanaSh" << endl;
    return 0;
}


void setup_commands() {
    command_functions["cd"] = cd;
    command_functions["ls"] = ls;
    command_functions["exit"] = exit;
}