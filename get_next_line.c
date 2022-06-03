/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:56:18 by acalvo4           #+#    #+#             */
/*   Updated: 2022/06/03 15:27:24 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line"

char *get_next_line(int fd)
{
	static char *temp;
	char	*line;
	char	*buffer;
	int		*aux;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	aux = read(fd, buffer, BUFFER_SIZE)
	if (aux == NULL || *aux == '\0')
	{
		free(aux);
		return(NULL);
	}
	line = ft_line_read_line(aux);

	 
	
	
}

char ft_read_line(char *aux)
{
	char *line;
	while (*aux != '\n')
	{
		*line = *aux;
		line ++;
		aux ++;
	I}
