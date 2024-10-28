/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 01:22:42 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/12 01:51:26 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_arr(int n[])
{
	char	ans[5];

	ans[0] = n[0] / 10 + '0';
	ans[1] = n[0] % 10 + '0';
	ans[2] = ' ';
	ans[3] = n[1] / 10 + '0';
	ans[4] = n[1] % 10 + '0';
	if (n[0] <= 98 && n[1] <= 99)
	{
		ft_putchar(ans[0]);
		ft_putchar(ans[1]);
		ft_putchar(ans[2]);
		ft_putchar(ans[3]);
		ft_putchar(ans[4]);
		if (n[0] != 98 || n[1] != 99)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	comb(int cnt, int n[])
{
	int	tmp;
	int	num;

	if (cnt == 2)
		ft_print_arr(n);
	else
	{
		if (cnt == 0)
			num = n[cnt];
		else
			num = (n[cnt - 1]) + 1;
		while (num <= 98 + cnt)
		{
			tmp = n[cnt];
			n[cnt] = num++;
			comb(cnt + 1, n);
			n[cnt] = tmp;
		}
	}
}

void	ft_print_comb2(void)
{
	int	n[3];

	n[0] = 0;
	comb(0, n);
}
