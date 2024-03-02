#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	char	*s;
	int		len;
	int		temp;
	int		i;
	int		sign;

	len = 0;
	i = 0;
	sign = 1;
	temp = nbr;
	if (nbr < 0)
	{
		sign = -1;
		len++;
		nbr = nbr * sign;
		temp = temp * sign;
	}
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	s = malloc(sizeof(s) * len + 1);
	if (sign == -1)
	{
		s[i] =  '-';
		i++;
	}
	s[len] = '\0';
	while(len)
	{
		s[len] = nbr % 10 + 48;
		nbr /= 10;
		len--;
	}
	return (s);
}

int main(void)
{
	printf("result = %s\n", ft_itoa(100012));
	return (0);
}

