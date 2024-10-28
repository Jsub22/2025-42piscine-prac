/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:42:30 by subjeong          #+#    #+#             */
/*   Updated: 2024/09/01 18:42:31 by subjeong         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	char	*base;
	int		num1;
	int		num2;

	base = "0123456789";
	if (argc != 4)
		return (0);
	num1 = convert_to_num(argv[1], base, 10);
	num2 = convert_to_num(argv[3], base, 10);
	if (!is_calc(argv[2]))
		print_str("0\n");
	else
		print_value(argv[2], num1, num2, base);
	return (0);
}
