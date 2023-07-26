#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t i;
	char *ptr1;
	char *ptr2;

	ptr1 = (char *)str1;
	ptr2 = (char *)str2;
	i = 0;
	if (ptr2[i] == '\0')
		return (ptr1);
	while (ptr1[i] != '\0' && i < n)
	{
		if (ptr1[i] == ptr2[0])
			return (ptr2);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char *str10 = "Hello world";
	char *str11 = "xxxxxxxxxxx";
	char *str20 = "Hello World";
	char *str21 = "";
	char *str22 = "hello world";
//	char *str23 = "world hello";
	size_t n = 11;

	printf("My test 1 = %s\n", ft_strnstr(str10, str20, n));
//	printf("C's test 1 = %s\n", strnstr(str10, str20, n));
	printf("My test 2 = %s\n", ft_strnstr(str11, str20, n));
//	printf("C's test 2 = %s\n", strnstr(str11, str20, n));
	printf("My test 3 = %s\n", ft_strnstr(str10, str21, n));
//	printf("C's test 3 = %s\n", strnstr(str10, str21, n));
	printf("My test 4 = %s\n", ft_strnstr(str10, str22, n));
//	printf("C's test 4 = %s\n", strnstr(str10, str22, n));
	return (0);
}
