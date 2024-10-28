/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 02:11:02 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/31 02:11:03 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	is_space(char c);
int	is_valid_base(char *base);
int	return_base_size(char *base);
int	is_in_base(char c, char *base);
int	return_size(int num, int base_size);

void	swap(char *tab, int i, int j)
{
	char	tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

void	ft_rev_char_tab(char *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		swap(tab, i, size - 1 - i);
		i++;
	}
}

int	convert_to_num(char *str, char *base, int size)
{
	int	i;
	int	num;
	int	sign;
	int	idx;

	i = 0;
	num = 0;
	sign = 1;
	while (is_space(str[i]))
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

void	convert_to_ascii(char *arr, int num, char *base_to, int to_size)
{
	int	i;
	int	sign;

	if (num < 0)
		sign = -1;
	else
		sign = 1;
	i = 0;
	if (num == 0)
		arr[i++] = base_to[0];
	while (num != 0)
	{
		arr[i++] = base_to[(num % to_size) * sign];
		num = num / to_size;
	}
	if (sign == -1)
	{
		arr[i++] = '-';
	}
	arr[i] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		fm_size;
	int		to_size;
	int		new_size;
	int		num;
	char	*arr;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	fm_size = return_base_size(base_from);
	to_size = return_base_size(base_to);
	num = convert_to_num(nbr, base_from, fm_size);
	new_size = return_size(num, to_size);
	arr = (char *)malloc(sizeof(char) * (new_size + 1));
	convert_to_ascii(arr, num, base_to, to_size);
	ft_rev_char_tab(arr, new_size);
	return (arr);
}
