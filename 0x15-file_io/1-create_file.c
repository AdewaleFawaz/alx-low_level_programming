#include "main.h"

/**
 * create_file - Creates a file with specified permissions and writes content.
 * @filename: Name of the file to create.
 * @text_content: NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
    int fd, write_status, close_status;
    mode_t permissions = S_IRUSR | S_IWUSR; // rw-------

    if (filename == NULL)
        return -1;

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, permissions);
    if (fd == -1)
        return -1;

    if (text_content != NULL)
    {
        write_status = write(fd, text_content, strlen(text_content));
        if (write_status == -1)
        {
            close(fd);
            return -1;
        }
    }

    close_status = close(fd);
    if (close_status == -1)
        return -1;

    return 1;
}

