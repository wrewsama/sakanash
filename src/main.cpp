#include<iostream>
#include<vector>
#include<sstream>
#include <sys/wait.h>
#include<cstring>
#include "executables.h"

using namespace std;

string read_line(void) {
    string s;
    getline(cin, s);
    return s;
}

vector<string> split_line(string line) {
    stringstream ss(line);
    vector<string> res;
    string buf;
    while (getline(ss, buf, ' ')) {
        res.push_back(buf);
    }

    return res;
}

int launch(vector<string> &args) {
    if (fork() == 0) {
        char *arr[args.size() + 1];
        for (int i; i < args.size(); i++) {
            strcpy(arr[i], args[i].c_str());
        }
        arr[args.size()] = NULL;
        execvp(args[0].c_str(), arr);
        return 0;
    } else {
        int status;
        wait(&status);
        if (status != 0) {
            cout << "Error: " << status << endl;
            return 0;
        }
        return 1;
    }
}

int execute(vector<string> &args) {
    string cmd = args[0];
    if (command_functions.find(cmd) == command_functions.end()) {
        return launch(args);
    }
    int res = command_functions[cmd](args);
    return res;
}

void shell_loop(void) {
    string line;
    vector<string> args;
    int status;

    do {
        cout << "><> ";
        line = read_line();
        args = split_line(line);
        status = execute(args);
    } while (status);
}

int main() {
    // set up executables
    setup_commands();

    // run command loop
    shell_loop();
    
    return EXIT_SUCCESS;
}