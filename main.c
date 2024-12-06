#include <stdio.h>
#include <string.h>

// Seems that from the standard library I can open files
// I'll use a FILE structure to store the file returned by fopen
// It was really fun to learn about paths in linux
// There are differents modes to open a file. "r" for read
int main() {
    FILE* config_file;
    char file_content[256];

    config_file = fopen("yourpath", "r");

    if (config_file == NULL) {
        printf("The file couldn't be open\n");

        return 0;
    }

    printf("Hello from my contacts list app!\n");
    
    while(fgets(file_content, 256, config_file)) {
        size_t new_line = strlen(file_content) - 1;
        
        if(file_content[new_line] == '\n')
            file_content[new_line] = '\0';

        printf("%s\n", file_content);
    }

    fclose(config_file);

    return 0;
}
