/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:23:02 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/17 13:42:53 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_arr(char lst[], int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_putchar(lst[i++]);
	i = 0;
	while (i < n)
	{
		if (lst[i] - '0' != 9 - (n - i - 1))
		{
			ft_putchar(',');
			ft_putchar(' ');
			return ;
		}
		i++;
	}
}

void	comb(int index, char lst[], int n)
{
	int		start;

	if (index == n)
		print_arr(lst, n);
	else
	{
		if (index == 0)
			start = lst[index];
		else
			start = (lst[index - 1]) + 1;
		while (start <= 9 - (n - index - 1))
		{
			lst[index] = start++;
			comb(index + 1, lst, n);
		}
	}
}

void	ft_print_combn(int n)
{
	char	lst[10];

	lst[0] = '0';
	comb(0, lst, n);
}
