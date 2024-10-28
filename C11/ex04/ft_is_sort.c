/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:42:41 by subjeong          #+#    #+#             */
/*   Updated: 2024/09/01 16:42:42 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (++i < length)
	{
		if (i == 1)
			tmp = f(tab[i - 1], tab[i]);
		else if (!(f(tab[i - 1], tab[i]) >= 0 && tmp >= 0) \
		|| !(f(tab[i - 1], tab[i] <= 0 && tmp <= 0)))
			return (0);
	}
	return (1);
}
