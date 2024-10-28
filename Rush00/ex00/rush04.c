/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:41:00 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/14 23:40:21 by takwak           ###   ########.fr       */
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
			print_line(x, 'A', 'B', 'C');
		else if (i == y)
			print_line(x, 'C', 'B', 'A');
		else
			print_line(x, 'B', ' ', 'B');
		ft_putchar('\n');
		i++;
	}
}
