#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print to STDOUT.
 * @filename: Text file being read
 * @letters: Number of letters to be read
 * Return: w - Actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    char *buffer;
    ssize_t file_descriptor;
    ssize_t written_bytes;
    ssize_t total_bytes;

    // Open the file for reading
    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
        return (0);

    // Allocate memory for a buffer to store the content of the file
    buffer = malloc(sizeof(char) * letters);

    // Read content from the file into the buffer
    total_bytes = read(file_descriptor, buffer, letters);

    // Write the content of the buffer to STDOUT
    written_bytes = write(STDOUT_FILENO, buffer, total_bytes);

    // Free the allocated buffer
    free(buffer);

    // Close the file
    close(file_descriptor);

    // Return the actual number of bytes read and printed
    return (written_bytes);
}

