/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 00:44:10 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/12 01:21:56 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_arr(char n[])
{
	if (n[0] - '0' <= 7 && n[1] - '0' <= 8 && n[2] - '0' <= 9)
	{
		ft_putchar(n[0]);
		ft_putchar(n[1]);
		ft_putchar(n[2]);
		if (n[0] - '0' != 7 || n[1] - '0' != 8 || n[2] - '0' != 9)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	comb(int cnt, char n[])
{
	int		num;

	if (cnt == 3)
		ft_print_arr(n);
	else
	{
		if (cnt == 0)
			num = n[cnt] - '0';
		else
			num = (n[cnt - 1] - '0') + 1;
		while (num <= 7 + cnt)
		{
			n[cnt] = num++ + '0';
			comb(cnt + 1, n);
		}
	}
}

void	ft_print_comb(void)
{
	char	n[3];

	n[0] = '0';
	comb(0, n);
}

int main(void)
{
	ft_print_comb();
}