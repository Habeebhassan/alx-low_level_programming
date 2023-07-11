#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * leave - error messages
 * @err: number is either
 * @filename: name representing either both file names
 * @fd: file identifier
 * Return: 0 on success
 **/
int leave(int err, char *filename, int fd)
{
	switch (err)
	{
	case 98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(err);
	case 99:
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(err);
	case 100:
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(err);
	default:
		return (0);
	}
}

/**
 * main - copy file
 * @argc: expecting 3 parameters
 * @argv: expected parameters
 * Return: 0 for success 97-100 failure
 */
int main(int argc, char *argv[])
{
	int src, dest, rd, w;
	char *buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	dest = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (dest == -1)
		leave(99, argv[2], 0);

	src = open(argv[1], O_RDONLY);
	if (src == -1)
		leave(98, argv[1], 0);

	while ((rd = read(src, buffer, 1024)) != 0)
	{
		if (rd == -1)
		{
			leave(98, argv[1], 0);
		}
		w = write(dest, buffer, rd);
		if (w == -1)
		{
			leave(99, argv[2], 0);
		}
	}

	close(dest) == -1 ? (leave(100, NULL, dest)) : close(dest);
	close(src) == -1 ? (leave(100, NULL, src)) : close(src);
	return (0);
}
