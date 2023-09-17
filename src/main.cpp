#include<iostream>

char *read_line(void) {
    // TODO
    return "";
}

char **split_line(char* line) {
    // TODO
    char *temp1 = "";
    char **temp2 = &temp1;
    return temp2;
}

int execute(char **args) {
    // TODO
    return 0;
}

void shell_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        std::cout << "> " << std::endl;
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