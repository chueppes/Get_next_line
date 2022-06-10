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

static char	*ft_read(char *line, int fd);
static char	*ft_oneline(char *buffer);
static char	*ft_overwrite(char *line);

char	*get_next_line(int fd)
{
	static char		*line;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line)
	{
		line = malloc(1 * sizeof(char));
		line[0] = '\0';
	}
	line = ft_read(line, fd);
	if (!line)
		return (NULL);
	result = ft_oneline(line);
	line = ft_overwrite(line);
	return (result);
}

static char	*ft_read(char *line, int fd)
{
	int		aux;
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
			free (line);
			return (NULL);
		}
		buffer[aux] = '\0';
		temp = line;
		line = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (line);
}

static char	*ft_oneline(char *line)
{
	char	*str2;
	size_t	i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str2 = malloc((i + 2) * sizeof(char));
	if (!str2)
		return (NULL);
	ft_strlcpy(str2, line, i + 1);
	if (line[i] == '\n')
		str2[i ++] = '\n';
	str2[i] = '\0';
	return (str2);
}

static char	*ft_overwrite( char *line)
{
	char	*str3;	
	size_t	i;
	size_t	j;
	int		newsize;

	i = 0;
	j = 0;
	newsize = (ft_strlen(line) - i + 1);
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free (line);
		return (NULL);
	}
	str3 = malloc(newsize * sizeof(char));
	if (!str3)
		return (NULL);
	while (line[i])
		str3[j++] = line[++i];
	str3[j++] = '\0';
	free (line);
	return (str3);
}
