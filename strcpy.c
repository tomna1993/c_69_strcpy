#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DESTINATION_SIZE 10 // bytes

int string_copy(char *dest, char *src, int dest_size_in_bytes);

int main(void)
{
    // Allocate memory for string
    char *string = malloc(100 * sizeof(char));

    if (string == NULL)
    {
        printf ("Failed to allocate memory for string!\n");
        return EXIT_FAILURE;
    }

    strcpy(string, "Hello, world! This string will be copied!");

    printf ("%s\n", string);

    // Allocate memory for destination string
    char *destination = malloc(MAX_DESTINATION_SIZE * sizeof(char));

    if (destination == NULL)
    {
        printf ("Failed to allocate memory for destination!\n");
        return EXIT_FAILURE;
    }

    // My own failsafe strcpy function
    int is_faliure = string_copy(destination, string, MAX_DESTINATION_SIZE);

    // If there is a problem during copying then exit the program
    if (is_faliure == EXIT_FAILURE)
    {
        printf ("String cannot be copied!\n");
        return EXIT_FAILURE;
    }

    printf ("%s\n", destination);

    free(string);
    free(destination);

    return EXIT_SUCCESS;
}

int string_copy(char *dest, char *src, int dest_size_in_bytes)
{
    // If destination doesn't have enough space return failure
    // If its value is zero then we have to terminate the copy because there
    // is no place for any characters
    // If its value is one then there is just one byte place for the terminator character (\0 - nul)
    if (dest_size_in_bytes <= 1)
    {
        return EXIT_FAILURE;
    }

    // If destination does not exist return failure
    if (dest == NULL)
    {
        return EXIT_FAILURE;
    }

    int count = 0;

    // Copy characters from source to destination until we reach nul or destination size - 1
    while (count < (dest_size_in_bytes - 1) && src[count] != '\0')
    {
        dest[count] = src[count];
        
        count++;
    }
    
    // Place nul at the end of the string
    dest[count] = '\0';

    return EXIT_SUCCESS;
}