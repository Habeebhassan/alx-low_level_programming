#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - text file and print
 * @filename: A pointer
 * @letters: The numbe
 *
 * Return: If the function fails or filename is NUL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, rd, w;
	char *buffer;

	if (!filename)
		return (0);

	buffer = malloc(letters * sizeof(char));
	if (!buffer)
		return (0);

	o = open(filename, O_RDONLY);
	rd = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, rd);

	if (o == -1 || rd == -1 || w == -1 || w != rd)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
}
