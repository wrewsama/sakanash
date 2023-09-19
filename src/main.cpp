#include<iostream>

using namespace std;

string read_line(void) {
    string s;
    cin >> s; 
    return s;
}

string *split_line(string line) {
    // TODO
    string temp1 = "";
    string *temp2 = &temp1;
    return temp2;
}

int execute(string *args) {
    // TODO
    return 1;
}

void shell_loop(void) {
    string line;
    string *args;
    int status;

    do {
        cout << "><> " << endl;
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