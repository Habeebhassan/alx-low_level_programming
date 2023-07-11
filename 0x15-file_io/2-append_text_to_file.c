#include "main.h"

/**
 * append_text_to_file - text
 * @filename: Pointer
 * @text_content: String
 *
 * Return: 1 if succeeded or -1 if failed or NULL
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int op, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content)
	{
		for (len = 0; text_content[len]; len++)
		;
		op = open(filename, O_WRONLY | O_APPEND);
		w = write(op, text_content, len);

		if (op == -1 || w == -1)
			return (-1);
	}

	close(op);

	return (1);
}
