/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:42:09 by subjeong          #+#    #+#             */
/*   Updated: 2024/09/01 18:42:10 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		plus(int n1, int n2);
int		minus(int n1, int n2);
int		divide(int n1, int n2);
int		subtract(int n1, int n2);
int		remain(int n1, int n2);
void	print_str(char *str);
void	print_nbr(int num, char *base_to, int to_size);
void	print_value(char *v, int num1, int num2, char *base);
int		convert_to_num(char *str, char *base, int size);
int		is_in_base(char c, char *base);
int		is_space(char c);
int		is_calc(char *v);

int	is_in_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
	|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	is_calc(char *v)
{
	if (v[0] == '+' || v[0] == '-' || v[0] == '/' \
	|| v[0] == '%' || v[0] == '*')
		return (1);
	else
		return (0);
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
