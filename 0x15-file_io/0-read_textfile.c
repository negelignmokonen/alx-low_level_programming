#include "main.h"

/**
 * read_textfile - a function that reads a text file and prints it
 *                to POSIX standard output.
 *
 * @filename: is the file to read
 * @letters: number of letters to read and print from file
 *
 * Return: 0 if it fails or actual number of letters it could
 *         read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_desc;
	ssize_t read_check, wcount;
	char *buff;

	if (filename == NULL) /*check if file is present*/
		return (0);

	file_desc = open(filename, O_RDONLY); /*open file*/

	if (file_desc == -1)
		return (0);

	/*get the size of buffer from number of letters*/
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		free(buff);
		return (0);
	}

	read_check = read(file_desc, buff, letters); /*read file*/
	if (read_check == -1) /*check if read failed*/
		return (0);

	wcount = write(STDOUT_FILENO, buff, read_check); /*write to POSIX*/
	if (wcount == -1 || read_check != wcount) /*check if write failed*/
		return (0);

	free(buff);

	close(file_desc); /*close file*/

	return (wcount);
}

