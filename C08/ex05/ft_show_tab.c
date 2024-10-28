/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 00:58:11 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/28 00:58:13 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * (-1));
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str)
	{
		ft_str(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_str(par[i].copy);
		ft_putchar('\n');
	}
}
