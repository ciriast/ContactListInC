#include <stdio.h>

// Seems that from the standard library I can open files
// I'll use a FILE structure to store the file returned by fopen
// It was really fun to learn about paths in linux
int main() {
    FILE* config_file;

    config_file = fopen("your path", "r");

    if (config_file == NULL)
        printf("The file couldn't be open\n");

    printf("Hello from my contacts list app!\n");
    
    return 0;
}
