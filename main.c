#include <stdio.h>
#include <string.h>

struct contact {
    char name[256];
    char last_name[256];
    char phone_number[100];
};

// Seems that from the standard library I can open files
// I'll use a FILE structure to store the file returned by fopen
// It was really fun to learn about paths in linux
// There are differents modes to open a file. "r" for read
// "r+" To read a file and also be able to write
// Cheking how to parse a json in c
// Continue reviewing
// I'm sick
// I'm still sick
// A fucking week, man
// well...
int main() {
    FILE* config_file;
    char file_content[256];

    config_file = fopen("yourpath", "r+");

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
    
    // Process to insert a line in the file.
    char user_message[256];
    struct contact user_contact;

    printf("Insert the contact first name:\n");
    fgets(user_contact.name, 256, stdin);

    printf("Insert the contact last name:\n");
    fgets(user_contact.last_name, 256, stdin);

    printf("Insert the contact phone number:\n");
    fgets(user_contact.phone_number, 100, stdin);

    printf("Contact first name: %s\n", user_contact.name);
    //fputs(user_message, config_file);
    //fputs("\0", config_file);
    printf("The file has been written\n");
    fclose(config_file);

    return 0;
}
