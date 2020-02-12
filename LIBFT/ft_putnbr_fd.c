/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:20:28 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/16 20:56:25 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	printnumber(long int nb, long int root, int n_p, int fd)
{
	int			single;

	if (n_p == 2)
	{
		ft_putchar_fd('-', fd);
	}
	if (root <= 1)
	{
		ft_putchar_fd(nb + 48, fd);
	}
	else
	{
		while (root / 10 != 0)
		{
			single = nb / root;
			ft_putchar_fd(single + 48, fd);
			nb = nb - (single * root);
			if (root / 100 == 0)
				ft_putchar_fd(nb + 48, fd);
			root /= 10;
		}
	}
}

static void	ft_putnbr(int nb, int fd)
{
	long int	root;
	long int	n_positive;
	int			n_p;

	n_p = 0;
	if (nb < 0)
	{
		n_positive = (long int)nb * -1;
		n_p = 2;
	}
	else
		n_positive = nb;
	root = 1;
	while (n_positive / root != 0)
		root *= 10;
	root /= 10;
	printnumber(n_positive, root, n_p, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
