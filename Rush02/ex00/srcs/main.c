/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:08:23 by jonghan           #+#    #+#             */
/*   Updated: 2024/08/28 18:33:08 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_error_check(char *target, char *file, t_dict *dict, int max_len)
{
	if (file == NULL || target == NULL)
	{
		ft_error_print("Error\n");
		return (1);
	}
	else if (dict == NULL || ft_num_check(target))
	{
		ft_error_print("Error\n");
		return (1);
	}
	if (ft_dict_set(file, ft_colon_get(file), dict, &max_len) || \
			ft_convert_num(target, dict, max_len) || !ft_colon_get(file))
	{
		ft_error_print("Dict Error\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_dict	*dict;
	char	*file;
	char	*target;
	int		max_len;

	max_len = 0;
	if (argc <= 1 || argc >= 4)
	{
		ft_error_print("Error\n");
		return (1);
	}
	file = ft_set_file(argc, argv);
	target = ft_set_target(argc, argv);
	dict = (t_dict *)malloc(sizeof(t_dict) * (ft_colon_get(file) + 1));
	if (ft_error_check(target, file, dict, max_len))
		return (1);
	ft_free_dict(dict, ft_colon_get(file));
	ft_free_memory(file);
	ft_free_memory(target);
	write(1, "\n", 1);
	return (0);
}
