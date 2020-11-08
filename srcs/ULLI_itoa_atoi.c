#include "../minishell.h"



static void	filltheplaces_ULLI(ULLI number, int n, char *ptr, long int han)
{
	int		i;

	i = 0;
	if (n < 0)
		ptr[i++] = '-';
	if (n == 0)
		ptr[i++] = 48;
	while (han)
	{
		ptr[i++] = (number / han) + 48;
		number = number - ((number / han) * han);
		han /= 10;
	}
	ptr[i] = '\0';
}

char		*ft_itoa_ULLI(ULLI n)
{
	ULLI	i;
	ULLI	number;
	ULLI	c;
	char		*ptr;

	c = 0;
	i = 1;
	if (n < 0)
		number = -n;
	else
		number = n;
	while (number / i)
	{
		i *= 10;
		c++;
	}
	if (!(ptr = (char*)malloc(sizeof(char) * (c + 2))))
		return (0);
	filltheplaces_ULLI(number, n, ptr, i / 10);
	return (ptr);
}


static int		white_digit_ULLI(int c, int d)
{
	if (d == 0)
	{
		if (c == '\n' || c == '\t' || c == '\v' || c == ' '
		|| c == '\f' || c == '\r')
			return (1);
		return (0);
	}
	return (-1);
}

long long int	ft_atoi_ULLI(const char *str)
{
	ULLI	number;
	int		c;

	number = 0;
	c = 0;
	if (*str == '\0')
		return (0);
	while (white_digit_ULLI(*str, 0) == 1)
		str++;
	if (*str == '-')
		c = 2;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && *str <= '9' && *str >= '0')
	{
		number += *str - '0';
		if (*(str + 1) != '\0')
			number *= 10;
		if ((number > 9223372036854775807 && c == 0) || (number > 9223372036854775808ULL && c == 2))
			return (255);
		str++;
	}
	return (c == 2 ? number * -1 : number);
}
