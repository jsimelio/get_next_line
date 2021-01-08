/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 12:42:43 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/08 17:52:01 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr_int(const char *s, int c)
{
	int		counter;

	counter = 1;
	while (*s)
	{
		if (*s == c)
			return (counter);
		s++;
		counter++;
	}
	return (-1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_2;
	char	*src_2;

	dst_2 = (char*)dst;
	src_2 = (char*)src;
	if (n == 0 || dst == src)
		return (dst);
	while ((int)n)
	{
		*dst_2 = *src_2;
		dst_2++;
		src_2++;
		n--;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *s2;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		s2 = malloc(sizeof(char*));
		if (!s2)
			return (NULL);
		*s2 = 0;
		return (s2);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, (s + start), len);
	s2[len] = 0;
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *buff_static, char const *buff_read)
{
	size_t		strlen;
	char	*s3;

	if (!buff_static && !buff_read)
		return (NULL);
	strlen = ft_strlen(buff_static) + ft_strlen(buff_read);
	s3 = malloc((strlen + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, buff_static, ft_strlen(buff_static) + 1);
	ft_strlcat(s3, buff_read, strlen + 1);
	free(buff_static);
	return (s3);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	src_len;
	unsigned long	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (!dstsize)
		return (src_len);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	if (src_len < dstsize - dst_len)
	{
		ft_memcpy(dst + dst_len, src, src_len + 1);
	}
	else
	{
		ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
		dst[dstsize - 1] = 0;
	}
	return (dst_len + src_len);
}

size_t	ft_strlcpy(char *dst, const char *src,
		size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	void	*memory;
	int		strlen;

	strlen = ft_strlen(s1) + 1;
	memory = malloc(strlen * sizeof(char));
	if (!memory)
		return (NULL);
	ft_memcpy(memory, s1, strlen);
	return (memory);
}