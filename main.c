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
// A little break today
// Another break
// I don't know if I'll program today
// Last day of the year
// I'll be programming each day of the 2025!
int main() {
    FILE* config_file;
    char file_content[256];

    config_file = fopen("yourpath.csv", "r+");

    if (config_file == NULL) {
        printf("The file couldn't be open\n");

        return 0;
    }

    printf("Contacts list app!\n");
    printf("Contacts:\n");

    // Let's start the search process
    char search_input[256] = "";

    printf("Insert the contact name or contact last name\n");
    fgets(search_input, 256, stdin);

    printf("You searched: %s\n", search_input);

    while(fgets(file_content, 256, config_file)) {
        size_t new_line = strlen(file_content) - 1;
        
        if(file_content[new_line] == '\n')
            file_content[new_line] = '\0';

        int first_comma = 0;
        int second_comma = 0;

        for(int i = 0; i < new_line; ++i) {

            if (file_content[i] == ',') {
                if (first_comma != 0 && second_comma == 0)
                    second_comma = i;

                if (first_comma == 0)
                    first_comma = i;
            }
        }
        
        char list_first_name [256] = "";
        char list_last_name [256] = "";
        char list_phone_number [100] = "";
        char complete_contact_info [612] = "";

        int result = second_comma - first_comma;
        strncpy(list_first_name, file_content, first_comma);
        strncpy(list_last_name, file_content + first_comma + 1, result - 1);
        strncpy(list_phone_number, file_content + second_comma + 1, new_line);

        strcat(complete_contact_info, list_first_name);
        strcat(complete_contact_info, " ");
        strcat(complete_contact_info, list_last_name);
        strcat(complete_contact_info, " - ");
        strcat(complete_contact_info, list_phone_number);

        printf("%s\n", complete_contact_info);
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
