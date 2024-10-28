/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 09:07:38 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/25 09:07:40 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int	is_in_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
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
		|| base[i] == ' ' || base[i] == '\n' || base[i] == '\t' \
		|| base[i] == '\v' || base[i] == '\f' || base[i] == '\r')
			return (0);
		j = i;
		while (base[++j])
		{
			if (base[j] == '+' || base[j] == '-' \
			|| base[j] == ' ' || base[j] == '\n' || base[j] == '\t' \
			|| base[j] == '\v' || base[j] == '\f' || base[j] == '\r')
				return (0);
			else if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

int	char_to_base(char *str, char *base, int size)
{
	int	i;
	int	num;
	int	sign;
	int	idx;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (1)
	{
		idx = is_in_base(str[i], base);
		if (idx == -1)
			break ;
		num = (num * size) + (sign * idx);
		i++;
	}
	return (num);
}

int	size_of_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	size;
	int	num;

	if (!is_valid_base(base))
		return (0);
	size = size_of_base(base);
	num = char_to_base(str, base, size);
	return (num);
}
