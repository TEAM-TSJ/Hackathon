#include "main.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstlen;
	size_t srclen;
	size_t i;

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

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	count = 0;
	if (!dst && !src)
		return (0);
	while (src[count])
	{
		count++;
	}
	if (dstsize)
	{
		i = (count >= dstsize) ? dstsize - 1 : count;
		ft_memcpy(dst, src, i);
		dst[i] = '\0';
	}
	return (count);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	i = ft_strlen(s1);
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

char	*ft_strjoin(char const *str1, char const *str2)
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
	if (!(ptr = (char *)malloc((i + j + 1) * sizeof(char))))
		return (0);
	ft_strlcpy(ptr, str1, i + 1);
	ft_strlcat(ptr + i, str2, j + 1);
	return (ptr);
}

static long long			check(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static long long			n_size(long long n)
{
	int	i;

	i = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char						*ft_itoa(int n)
{
	char	*ptr;
	int		sign;
	int		i;

	sign = 1;
	if (n < 0)
		sign = -1;
	i = n_size(n);
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ptr[i] = '\0';
	i--;
	while (i >= 0)
	{
		ptr[i] = '0' + check(n % 10);
		n = check(n / 10);
		i--;
	}
	if (sign < 0)
		ptr[0] = '-';
	return (ptr);
}