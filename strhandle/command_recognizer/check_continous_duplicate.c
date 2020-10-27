int ft_cduplicate(char *str, char c)
{
    unsigned int    iter;

    iter = 1;
    if (!*str)
        return (0);
    if (*str==c)
        return (1);
    while (str[iter])
    {
        if (str[iter - 1] == str[iter] && str[iter] == c)
            return (1);
        iter++;
    }
    if (str[iter - 1] == c)
        return (1);
    return (0);
}
