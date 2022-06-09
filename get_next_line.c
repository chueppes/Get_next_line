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

static char *ft_read(char *line, int fd);
static char *ft_oneline(char *buffer);
static char *ft_overwrite(char *line);


char *get_next_line(int fd)
{
	static char		*line;
	char			*result;

	if (!line)
		line = malloc(1 * sizeof(char));
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read(line, fd);
	result = ft_oneline(line);
	if (ft_strlen(result) < ft_strlen(line))
		line = ft_overwrite(line);
	return (result); 
}


static char *ft_read(char *line, int fd)
{
	int aux;
	char	*buffer;
	char	*temp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	aux = 1;
	while (aux != 0 && !(ft_strchr(line, '\n')))
	{
		aux = read(fd, buffer, BUFFER_SIZE);
		if (aux == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[aux] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
	}
	free(buffer);
	return (line);
}

static char *ft_oneline(char *line)
{
	
	char	*str2;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	str2 = malloc((i + 1) * sizeof(char));
	if (!str2)
		return (NULL);
	ft_strlcpy(str2, line, i + 1);
	//if (line[i] == '\n')
		//str2[i ++] = '\n';
	str2[i] = '\0';
	return (str2);
}

static char *ft_overwrite( char *line)
{
  
	//if (line == NULL && aux == 0)
	//	return (NULL);
	char *str3;	
	size_t j;
	size_t i;

	i = 0;
	str3 = NULL;
	if (!line)
	{
		free (line);
		return("erro1");
	}
	while (line[i] && line[i] != '\n')
		i++;
	j = 0;
	str3 = malloc((ft_strlen(line) - (i + 1)) * sizeof(char));
	if(!str3)
		return("erro2");
	i++;
	while (line[i])
		str3[j++] = line[i++];
	str3[j++] = '\0';
	return (str3);
}

// at this point i´ve changed so many different things in my code that i can´t even document it all
// apparently my mistake was in my retur of my function ft_read, i've change my past usages of 'buffer'
// to use my static variable 'line' in all of my functions. 
// i have also set a condition to my overwrite function to check wether  i am in the end of my function or
// i have a perfect size read. i have also changed my ft_join so it considers some specific cases.
// my gnl works with my tests, but not with the gnltester.
// i cant even count how many leaks i have, tomorrow i'll try to fix that.

int main ()
{	
static char *line;
int fd;
int i = 5;
fd = open ("x.txt", O_RDONLY);
	while (i--)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		printf("---------\n");
	}
 	free(line);
 	close(fd);
 }