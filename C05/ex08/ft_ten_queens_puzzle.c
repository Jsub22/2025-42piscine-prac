/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:20:49 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/25 13:20:51 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	initialize_puzzle(int v[10][10])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			v[i][j] = 0;
		}
	}
}

void	print_puzzle(int v[10][10])
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			if (v[i][j] == 1)
			{
				c = j + '0';
				write(1, &c, 1);
			}
		}
	}
	write(1, "\n", 1);
}

int	check_lines(int v[10][10], int dv[3][2], int row, int col)
{
	int	d;
	int	new_x;
	int	new_y;

	d = -1;
	while (++d < 3)
	{
		new_x = row + dv[d][0];
		new_y = col + dv[d][1];
		while (new_x >= 0 && new_x < 10 \
			&& new_y >= 0 && new_y < 10)
		{
			if (v[new_x][new_y] == 1)
				return (0);
			new_x += dv[d][0];
			new_y += dv[d][1];
		}
	}
	return (1);
}

int	recursive_puzzle(int v[10][10], int dv[3][2], int row)
{
	int	i;
	int	cnt;

	if (row == 10)
	{
		print_puzzle(v);
		return (1);
	}
	cnt = 0;
	i = -1;
	while (++i < 10)
	{
		if (check_lines(v, dv, row, i))
		{
			v[row][i] = 1;
			cnt += recursive_puzzle(v, dv, row + 1);
			v[row][i] = 0;
		}
	}
	return (cnt);
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10][10];
	int	dv[3][2];

	dv[0][0] = -1;
	dv[0][1] = 0;
	dv[1][0] = -1;
	dv[1][1] = -1;
	dv[2][0] = -1;
	dv[2][1] = 1;
	initialize_puzzle(queens);
	return (recursive_puzzle(queens, dv, 0));
}
