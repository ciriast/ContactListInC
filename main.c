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
// Tomorrow will be the day
// I'm back baby
// Seems that I can't parse a json natively with C, so, I'll search for a different format
// I'll work with a csv file
int main() {
    FILE* config_file;
    char file_content[256];

    config_file = fopen("yourpath.csv", "r+");

    if (config_file == NULL) {
        printf("The file couldn't be open\n");

        return 0;
    }

    printf("Contacts list app!\n");
    
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
   
    // Make sure to remove the \n of the strings
    size_t user_name_size = strlen(user_contact.name) - 1;
    size_t user_last_name_size = strlen(user_contact.last_name) - 1;
    size_t user_phone_number_size = strlen(user_contact.phone_number) - 1;

    if (user_contact.name[user_name_size] == '\n')
        user_contact.name[user_name_size] = '\0';

    if (user_contact.last_name[user_last_name_size] == '\n')
        user_contact.last_name[user_last_name_size] = '\0';

    if (user_contact.phone_number[user_phone_number_size] == '\n')
        user_contact.phone_number[user_phone_number_size] = '\0';

    strcat(user_contact.name, ",");
    strcat(user_contact.name, user_contact.last_name);
    strcat(user_contact.name, ",");
    strcat(user_contact.name, user_contact.phone_number);

    fputs(user_contact.name, config_file);
    fputs("\0", config_file);
    printf("A contact has been written\n");
    fclose(config_file);

    return 0;
}
