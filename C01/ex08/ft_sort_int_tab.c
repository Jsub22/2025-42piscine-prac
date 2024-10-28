/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:52:07 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/15 21:41:12 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *tab, int i, int j)
{
	int	tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

void	sort_bubble(int *tab, int size)
{
	int	i;
	int	j;

	i = size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] > tab[j + 1])
				swap(tab, j, j + 1);
			j++;
		}
		i--;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	sort_bubble(tab, size);
}
