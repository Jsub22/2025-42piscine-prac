/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 03:48:12 by jonghan           #+#    #+#             */
/*   Updated: 2024/08/28 18:27:33 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	**ft_creat_type2_arr(char *str)
{
	char	**arr;
	int		i;

	i = -1;
	arr = (char **)malloc(sizeof(char *) * 2);
	if (arr == NULL)
		return (NULL);
	arr[0] = (char *)malloc(sizeof(char) * 3);
	arr[1] = (char *)malloc(sizeof(char) * 2);
	while (++i < 2)
	{
		if (arr[i] == NULL)
		{
			while (i > 0)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		arr[i][0] = str[i];
	}
	arr[0][1] = '0';
	arr[0][2] = 0;
	arr[1][1] = 0;
	return (arr);
}

void	ft_type1(char *str, t_dict *dict, int zero_c, int flag)
{
	ft_print_char(str[0], dict, flag);
	ft_print_dict("100", dict, 0);
	if (ft_atoi(str + 1) > 0)
	{
		if (ft_atoi(str + 1) >= 20)
			ft_type2(str + 1, dict, 0, 0);
		else if (ft_atoi(str + 1) >= 10)
			ft_print_dict(str + 1, dict, 0);
		else
			ft_print_char(str[2], dict, 0);
	}
	ft_print_zero(zero_c, dict);
}

int	ft_type2(char *str, t_dict *dict, int zero_c, int flag)
{
	int		i;
	char	**arr;
	int		n;

	i = 0;
	n = ft_atoi(str);
	ft_itoa(n, str);
	if (n % 10 == 0)
		ft_print_dict(str, dict, flag);
	else
	{
		arr = ft_creat_type2_arr(str);
		if (arr == NULL)
			return (1);
		ft_print_dict(arr[0], dict, flag);
		ft_print_dict(arr[1], dict, 0);
		while (i < 2)
			ft_free_memory(arr[i++]);
		free(arr);
		arr = NULL;
	}
	ft_print_zero(zero_c, dict);
	return (0);
}

void	ft_type3(char *str, t_dict *dict, int zero_c, int flag)
{
	int	n;

	n = ft_atoi(str);
	ft_itoa(n, str);
	ft_print_dict(str, dict, flag);
	ft_print_zero(zero_c, dict);
}
