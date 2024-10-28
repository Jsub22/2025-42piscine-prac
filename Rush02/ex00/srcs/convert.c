/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 03:51:54 by jonghan           #+#    #+#             */
/*   Updated: 2024/08/28 18:27:02 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_other_convert(char *av, t_dict *dict, int zero_c, int i)
{
	char	*str;

	while (zero_c >= 0)
	{
		str = ft_strncpy(&av[i], 3);
		if (str == NULL)
			return (1);
		if (ft_atoi(str))
		{
			if (ft_atoi(str) >= 100)
				ft_type1(str, dict, zero_c, (zero_c == ft_strlen(av) - 3));
			else if (ft_atoi(str) >= 20)
			{
				if (ft_type2(str, dict, zero_c, (zero_c == ft_strlen(av) - 3)))
					return (1);
			}
			else
				ft_type3(str, dict, zero_c, (zero_c == ft_strlen(av) - 3));
		}
		ft_free_memory(str);
		i += 3;
		zero_c -= 3;
	}
	return (0);
}

int	ft_first_convert(char *av, t_dict *dict, int *zero_c, int *i)
{
	int		av_len;
	char	*str;

	av_len = ft_strlen(av);
	if (av_len % 3 != 0)
	{
		str = ft_strncpy(av, av_len % 3);
		if (str == NULL)
			return (1);
		if (ft_atoi(str) >= 100)
			ft_type1(str, dict, *zero_c, 1);
		else if (ft_atoi(str) >= 20)
			ft_type2(str, dict, *zero_c, 1);
		else
			ft_type3(str, dict, *zero_c, 1);
		ft_free_memory(str);
		*zero_c -= 3;
		*i += av_len % 3;
	}
	return (0);
}

int	ft_convert_num(char *av, t_dict *dict, int max_len)
{
	int	i;
	int	zero_c;
	int	av_len;

	i = 0;
	if (!ft_atoi(av))
	{
		ft_print_char('0', dict, 1);
		return (0);
	}
	av = av + ft_first_zero(av);
	av_len = ft_strlen(av);
	if (av_len > max_len + 2)
		return (1);
	zero_c = av_len - (av_len % 3);
	if (!(av_len % 3))
		zero_c -= 3;
	if (ft_first_convert(av, dict, &zero_c, &i))
		return (1);
	if (ft_other_convert(av, dict, zero_c, i))
		return (1);
	return (0);
}
