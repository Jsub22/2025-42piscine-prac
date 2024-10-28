/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:35:55 by subjeong          #+#    #+#             */
/*   Updated: 2024/09/27 14:36:20 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (tab[++i])
	{
		if (f(tab[i]))
			count++;
	}
	return (count);
}
