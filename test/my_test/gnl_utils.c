#include "main.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	while (s1[i])
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (0);
	j = 0;
	while (j < i)
	{
		ptr[j] = s1[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	count = 0;
	if (!dst && !src)
		return (0);
	while (src[count])
		count++;
	if (dstsize == 0)
		return (count);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	while (src[i] && dstlen + i + 1 < dstsize)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (dstlen < dstsize)
	{
		dst[dstlen + i] = '\0';
		return (dstlen + srclen);
	}
	return (dstsize + srclen);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char		*ptr;
	size_t		i;
	size_t		j;

	j = 0;
	if (!str1 && !str2)
		return (0);
	else if (!str1 || !str2)
	{
		if (!str1)
			return (ft_strdup(str2));
		return (ft_strdup(str1));
	}
	i = ft_strlen(str1);
	j = ft_strlen(str2);
	ptr = (char *)malloc((i + j + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, str1, i + 1);
	free(str1);
	ft_strlcat(ptr + i, str2, j + 1);
	return (ptr);
}
