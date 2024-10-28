/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:42:05 by subjeong          #+#    #+#             */
/*   Updated: 2024/09/01 16:42:06 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (tab < length)
	{
		if (f(tab[i]))
			count++;
	}
	return (count);
}
