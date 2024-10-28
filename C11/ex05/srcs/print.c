/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:44:02 by subjeong          #+#    #+#             */
/*   Updated: 2024/09/01 20:44:05 by subjeong         ###   ########.fr       */
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

void	print_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	print_nbr(int num, char *base_to, int to_size)
{
	int		i;
	int		sign;
	char	*arr;

	arr = (char *)malloc(sizeof(char) * 11);
	i = 10;
	if (num < 0)
		sign = -1;
	else
		sign = 1;
	i = 0;
	if (num == 0)
		arr[i--] = base_to[0];
	while (num != 0)
	{
		arr[i--] = base_to[(num % to_size) * sign];
		num = num / to_size;
	}
	if (sign == -1)
		arr[i--] = '-';
	while (++i < 11)
		write(1, &arr[i], 1);
}

void	print_value(char *v, int num1, int num2, char *base)
{
	if (v[0] == '+')
		print_nbr(plus(num1, num2), base, 10);
	else if (v[0] == '-')
		print_nbr(minus(num1, num2), base, 10);
	else if (v[0] == '/')
	{
		if (num2 == 0)
			print_str("Stop : division by zero\n");
		else
			print_nbr(divide(num1, num2), base, 10);
	}
	else if (v[0] == '%')
	{
		if (num2 == 0)
			print_str("Stop : modulo by zero\n");
		else
			print_nbr(remain(num1, num2), base, 10);
	}
	else if (v[0] == '*')
		print_nbr(subtract(num1, num2), base, 10);
}
