/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 02:11:08 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/31 02:11:09 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
	|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' \
		|| is_space(base[i]))
			return (0);
		j = i;
		while (base[++j])
		{
			if (base[i] == '+' || base[i] == '-' \
			|| is_space(base[j]))
				return (0);
			else if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

int	return_base_size(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	is_in_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
}

int	return_size(int num, int base_size)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (num < 0)
		count++;
	while (num != 0)
	{
		num = num / base_size;
		count++;
	}
	return (count);
}
