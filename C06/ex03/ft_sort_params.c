/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:53:25 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/25 22:53:26 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char *v)
{
	int	i;

	i = -1;
	while (v[++i])
		write(1, &v[i], 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	swap(char **argv, int i, int j)
{
	char	*tmp;

	tmp = argv[i];
	argv[i] = argv[j];
	argv[j] = tmp;
}

void	sort_bubble(char **argv, int size)
{
	int	i;
	int	j;

	i = size - 1;
	while (i > 1)
	{
		j = 1;
		while (j < i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				swap(argv, j, j + 1);
			j++;
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	sort_bubble(argv, argc);
	while (++i < argc)
	{
		ft_putchar(argv[i]);
		ft_putchar("\n");
	}
	return (0);
}
