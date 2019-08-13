#include "holberton.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nletters;
	char *buf;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters + 1));
	if (!buf)
		return (0);

	read(fd, buf, letters + 1);

	buf[letters] = '\0';

	for (nletters = 0; buf[nletters] != '\0'; nletters++)
		;

	write(STDOUT_FILENO, buf, nletters);

	close(fd);

	free(buf);

	return (nletters);
}
