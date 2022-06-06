/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:36:08 by acalvo4           #+#    #+#             */
/*   Updated: 2022/06/06 14:29:01 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	strlen;
	size_t	p2;

	p2 = ft_strlen(s1);
	strlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(strlen);
	ft_strlcpy(&str[0], s1, ft_strlen(s1) + 1);
	ft_strlcpy(&str[p2], s2, ft_strlen(s2) + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src) + 1;
	i = dstsize - 1;
	if (j < dstsize)
		ft_memcpy (dst, src, j);
	else if (dstsize > 0)
		ft_memcpy (dst, src, i);
	dst[i] = '\0';
	return (j - 1);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tdest;
	const char	*tsrc;

	tsrc = (char *)src;
	tdest = (char *)dest;
	if (tdest == tsrc || n == 0)
		return (dest);
	while (n-- > 0)
	{
		tdest[n] = tsrc[n];
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0' && (char)c != '\0')
			return (0);
		i++;
	}
	return ((char *) s + i);
}
