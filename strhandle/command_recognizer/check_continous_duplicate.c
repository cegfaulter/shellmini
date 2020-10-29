
#include "../../minishell.h"

static int      ft_cduplicate(char *str, char c)
{
    unsigned int    iter;

    iter = 1;
    if (!*str)
        return (0);
    if (*str==c && *(str + 1) != c)
        return (1);
    while (str[iter])
    {
        if (str[iter - 1] == str[iter] && str[iter] == c)
            return (2);
        iter++;
    }
    if (str[iter - 1] == c)
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
    if (ret == 1)
        g_data.error_detected = 8;
    else if (ret == 2)
        g_data.error_detected = 7;
    if (ret == 3)
        return (0);
    return (1);
}