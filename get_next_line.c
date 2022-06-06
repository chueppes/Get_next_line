/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:56:18 by acalvo4           #+#    #+#             */
/*   Updated: 2022/06/06 16:31:59 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


char *ft_read_line_fd( char *line, int fd);

char *get_next_line(int fd)
{
	static char *line;

	line = ft_read_line_fd(line, fd);

	return (line);
}

char *ft_read_line_fd( char *line, int fd){
	
	int aux;
	char *buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	aux = 1;
	while (aux > 0 && !ft_strchr(line, '\n'))
	{
		aux = read(fd, buffer, BUFFER_SIZE);
		if (aux < 0)
			return(NULL);
		buffer[aux] = '\0';
		line  = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

/*int main (){
	
	static char *line;
	int fd;
	fd = open ("x.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
	}
	//free(line);
	close(fd);
}*/

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}

