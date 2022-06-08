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

char *get_next_line(int fd)
{
	static char *line;
	int aux;
	char *buffer;
	char *str2;
	char *str3;

	// the following line shows me the possible entry errors that may occur
	// if i don't have a file, if the file is bigger than OPEN_MAX which id the max value of open()
	// or if I have a negative BUFFER_SIZE
	// according to the rules, it showld return -1 if an error has occured
	// but i still don't know how to do it. 
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return ("erro1");//-1
	// if everything is ok with the entry values it mallocates my buffer 
	// with the BUFFER_SIZE + 1 (the null byte) and then i check if the malloc occured fine 
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ("erro2");
	aux = 1;
	if (!line)
		line = malloc(1 * sizeof(char));
	// while i dont have a bad response from aux or found \n in my string
	// i keep on reading it, then i set buffer at aux size as \0
	// then i join what the buffer read in the last loop with what it is reading now
	// this part returns an odd result. if i set BUFFER_SIZE as 1 it returns me 
	// the first string, if i set it as 6, it returns the first one and a part of the second line too
	// but if i set as 10 it returns only the first line.
	// that happens because the read function reads BUFFER_SIZE bytes per time untill it finds a \n in itself
	// so it keeps more than it should. 
	while (aux != 0 && !(ft_strchr(line, '\n')))
	{
		aux = read(fd, buffer, BUFFER_SIZE);
		if (aux == -1)
		{
			free (buffer);
			return ("erro3");
		}
		buffer[aux] = '\0';
		line = ft_strjoin(line, buffer);
	}
	// i'm gonna try to make it return ONLY the first line.
	// for that i'm gonna mesure the size of my buffer until \n 
	// and then allocate that size of memory in another string
	// after that i will call strlcpy to copy everything to my return string  
	// and lastly set \n and \0.

	size_t i;
	i = 0;

	while (buffer[i] && buffer[i] != '\n')
		i++;
	str2 = malloc((i + 2) * sizeof(char));
	if (!str2)
		return ("erro4");
	ft_strlcpy(str2, buffer, i + 1);
	str2[i ++] = '\n';
	str2[i] = '\0';
	// it worked! now i have to overwrite my static variable with itself after 
	// the first occurence of '\n' notice that at this point i could've 
	// used strdup, but since my own strdup made in libft contains too many functions
	// i will try on doing it by a different way. 
	// for that i will allocate a str3 with the total length of my buffer minus the
	// size of my line which is contained in i, then i will copy my buffer content 
	// in str3 until i find the end of my buffer. after that i will set \0 and put _this
	// into my static variable line, and then return it.
	// if (line == NULL && aux == 0)
	//		return (NULL);
	if (ft_strlen(buffer) > (i + 2))
	{
		int j;
		j = 0;

		str3 = malloc((ft_strlen(buffer) - (i + 1)) * sizeof(char));
		if(!str3)
			return("erro5");
		while (buffer[i])
			str3[j++] = buffer[i++];
		str3[j++] = '\0';
		i = 0;
		while (str3[i]){
			line[i] = str3[i];
			i++;
		}
	}
	free (buffer);
	return (str2);
	// it did not worked. i dont know where or how to use the static variable.
	// the problem was that i wasn't allocating my line variable with no value 
}


static char ft_read(char *line, char *buffer)
{
	int aux;
	aux = 1;
	
}

int main ()
{	
static char *line;
int fd;
int i = 5;
fd = open ("x.txt", O_RDONLY);
	while (i--)
	{
		line = get_next_line(fd);
 		printf("%s", line);
		
	}
 	free(line);
 	close(fd);
 }