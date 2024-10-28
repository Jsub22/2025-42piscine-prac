/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 05:34:26 by jonghan           #+#    #+#             */
/*   Updated: 2024/08/28 18:11:49 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_str_print(char *str, int flag)
{
	int	i;

	i = 0;
	if (!flag)
		write(1, " ", 1);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_error_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_dict(char *str, t_dict *dict, int flag)
{
	int	i;

	i = 0;
	while (dict[i].key)
	{
		if (ft_strcmp(str, dict[i].key))
		{
			ft_str_print(dict[i].value, flag);
			break ;
		}
		i++;
	}
}

void	ft_print_char(char c, t_dict *dict, int flag)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = 0;
	while (dict[i].key)
	{
		if (ft_strcmp(str, dict[i].key))
		{
			ft_str_print(dict[i].value, flag);
			break ;
		}
		i++;
	}
	ft_free_memory(str);
}

void	ft_print_zero(int zero_c, t_dict *dict)
{
	int		i;
	char	*arr;

	i = 1;
	arr = (char *)malloc(sizeof(char) * (zero_c + 2));
	if (arr == NULL)
		return ;
	if (zero_c > 2)
	{
		arr[0] = '1';
		while (i <= zero_c)
			arr[i++] = '0';
		arr[i] = 0;
		ft_print_dict(arr, dict, 0);
	}
	free(arr);
	arr = NULL;
}
