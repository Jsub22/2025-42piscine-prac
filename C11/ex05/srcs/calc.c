/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
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

int	plus(int n1, int n2)
{
	return (n1 + n2);
}

int	minus(int n1, int n2)
{
	return (n1 - n2);
}

int	divide(int n1, int n2)
{
	return (n1 / n2);
}

int	subtract(int n1, int n2)
{
	return (n1 * n2);
}

int	remain(int n1, int n2)
{
	return (n1 % n2);
}
