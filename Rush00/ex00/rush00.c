/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:43:56 by takwak            #+#    #+#             */
/*   Updated: 2024/08/14 23:38:20 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

extern void	ft_putchar(char c);

void	print_line(int x, char first, char middle, char last)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar(first);
		else if (i == x)
			ft_putchar(last);
		else
			ft_putchar(middle);
		i++;
	}
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
	{
		write(1, "Invalid value", 13);
		return ;
	}
	i = 1;
	while (i <= y)
	{
		if (i == 1)
			print_line(x, 'o', '-', 'o');
		else if (i == y)
			print_line(x, 'o', '-', 'o');
		else
			print_line(x, '|', ' ', '|');
		ft_putchar('\n');
		i++;
	}
}
