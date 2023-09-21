#include<iostream>
#include<vector>
#include<sstream>

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

int execute(vector<string> &args) {
    // TODO
    return 1;
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
    // run command loop
    shell_loop();
    
    return EXIT_SUCCESS;
}