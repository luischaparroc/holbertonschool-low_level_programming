#include "holberton.h"

/**
 * create_file - creates a file
 * @filename: filename.
 * @text_content: content writed in the file.
 *
 * Return: 1 if it success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int nletters;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY, 0600);

	if (fd == -1)
		return (-1);

	for (nletters = 0; text_content[nletters]; nletters++)
		;

	write(fd, text_content, nletters);

	close(fd);

	return (1);
}
