/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 01:52:00 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/16 18:59:35 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	v[10];
	int	i;
	int	flag;

	v[9] = 0;
	i = 9;
	flag = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
			nb += ++flag;
		nb *= -1;
		ft_putchar('-');
	}
	while (nb > 0)
	{
		v[i--] = nb % 10;
		nb = nb / 10;
	}
	while (++i <= 8)
		ft_putchar(v[i] + '0');
	ft_putchar(v[9] + flag + '0');
}
