/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:56:18 by acalvo4           #+#    #+#             */
/*   Updated: 2022/06/07 11:43:17 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


//char *ft_read_line_fd( char *line, int fd);

char *get_next_line(int fd)
{
	static char *line;
	int aux;
	char *buffer;
	char *temp;

	// the following line shows me the possible entry errors that may occur
	// if i don't have a file, if the file is bigger than OPEN_MAX which id the max value of open()
	// or if I have a negative BUFFER_SIZE
	// according to the rules, it showld return -1 if an error has occured
	// but i still don't know how to do it. 
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);//-1
	// line = ft_read_line_fd(line, fd);
	// if everything is ok with the entry values it mallocates my buffer 
	// with the BUFFER_SIZE + 1 (the null byte) and then i check if the malloc occured fine 
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	aux = 1;
	// temp = buffer;
	//checks if line[fd] has \n in it
	// so, while line doesn't shows me a '\n' i keep on reading the file
	// if the read command fails it returns the function
	// else, it puts a line break at the buffer at aux position
	// after that, it joins the temporary variable which holds the buffer old value
	// if frees the temporary variable 
	// the it checks if the line contains a '\n'
	// i tried on using this comparation first, as a condition to my 'while'
	// as if if its not a \n i follow the code, but it didn't worked. i dont know why
	/*while (aux > 0)
	{
		aux = read(fd, buffer, BUFFER_SIZE);
		if (aux < 0)
			return(NULL);//-1
		buffer[aux] = '\0';
		temp = line;
		line  = ft_strjoin(temp, buffer);
		//free(temp);
		if (ft_strchr(line, '\n'))
			break;
	}*/

	while (aux > 0)
	{
		aux = read(fd, buffer, BUFFER_SIZE);
		if (aux < 0)
			return (NULL);
		buffer[aux]
		temp = line;
		line = ft_strjoin(temp + fd, buffer);
		if (ft_strchr(line + fd, '\n'))
			break ;	
	}
	// i'm trying to find out how to read one line.
	// at this point my code shows me the value if i retur the buffer
	free(buffer);
	

	return (line);
}

//char *ft_read_line_fd( char *line, int fd){
//}

int main (){
	
	static char *line;
	int fd;
	fd = open ("x.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		//line = get_next_line(fd);
		printf("%s", line);
	}
	//free(line);
	close(fd);
}

/*int	main(void)
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
}*/

