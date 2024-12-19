/*
Created by: Emily (Em_iIy) Winnink
Created on: 06/09/2024
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char *read_file(const char *file_name)
{
	int		fd;
	off_t	file_size;
	char	*ret;
	ssize_t	bytes_read;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("read_file open");
		return (NULL);
	}
	file_size = lseek(fd, 0, SEEK_END);
	ret = (char *)malloc(file_size + 1);
	if (!ret)
	{
		perror("read_file malloc");
		close(fd);
		return (NULL);
	}
	lseek(fd, 0, SEEK_SET);
	bytes_read = read(fd, ret, (size_t)file_size);
	if (bytes_read < 0)
	{
		perror("read_file read");
		free(ret);
		close(fd);
		return (NULL);
	}
	ret[bytes_read] = '\0';
	close(fd);
	return (ret);
}
