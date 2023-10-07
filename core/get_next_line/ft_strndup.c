#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

char	*ft_strndup(char const *src, unsigned int n)
{
	char			*scopy;
	unsigned int	i;

	i = 0;
	scopy = malloc((n + 1) * sizeof(*scopy));
	if (!scopy)
		return (NULL);
	while (src[i] && i < n)
	{
		scopy[i] = src[i];
	}
	while (i < n) //or <=
	{
		scopy[i] = '\0';//[i++]
    }
	return (scopy);
}

int	main(void)
{
	char	*s = "hello world";
	unsigned int	n = 6;

	printf("%s\n", ft_strndup(s, n));
	return (0);
}
