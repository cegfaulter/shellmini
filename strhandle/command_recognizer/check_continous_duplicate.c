
#include "../../minishell.h"

static int		ft_ccheck_nexts(char *str, char c)
{
	unsigned int	iter;

	iter = 0;
	while (str[iter] && str[iter] == ' ')
		iter++;
	if (str[iter] == c)
		return (1);
	return (0);
}

static int      ft_cduplicate(char *str, char c)
{
    unsigned int    iter;
    int             back;
    unsigned int    length;

    iter = 0;
    back =  0;
    length = strlen(str);
    if (!length)
        return (0);
    if (*str==c && *(str + 1) != c)
        return (1);
    while (iter + 1 < length)
    {
        if (str[iter + 1] == str[iter] && str[iter] == c && back % 2 == 0)
            return (2);
		if (back % 2 == 0 && str[iter] == c && ft_ccheck_nexts(str + iter + 1, c))
		{
			iter += 1;
			break ;
		}
        if (str[iter] == '\\')
            back++;
        else if (iter + 1 < length)
            back = 0;
        iter++;
    }

    if (back % 2 == 0 && str[iter] == c)
        return (3);
    return (0);
}

int            ft_cduplicate_or(char *str)
{
    int     ret;

    if (!(ret = ft_cduplicate(str, '|')))
        return (ret);
    if (ret == 1 || ret == 3)
        g_data.error_detected = 5;
    if (ret == 2)
        g_data.error_detected = 6;
    return (1);
}

int             ft_cduplicate_semi(char *str)
{
    int     ret;

    if (!(ret = ft_cduplicate(str, ';')))
        return (ret);
    if (ret == 1 || ret == 3)
        g_data.error_detected = 8;
    else if (ret == 2)
        g_data.error_detected = 7;
    // if (ret == 3)
    //     return (0);
    return (1);
}