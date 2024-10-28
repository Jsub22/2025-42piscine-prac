/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:41:58 by subjeong          #+#    #+#             */
/*   Updated: 2024/09/01 20:41:59 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	count_str(char **tab)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (tab[++i])
		count++;
	return (count);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = count_str(tab) - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i--;
	}
}
