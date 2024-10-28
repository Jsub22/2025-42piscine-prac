/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:15:58 by jonghan           #+#    #+#             */
/*   Updated: 2024/08/28 17:17:01 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_free_memory(char *str)
{
	free(str);
	str = NULL;
}

void	ft_free_dict(t_dict *dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(dict[i].key);
		free(dict[i].value);
		dict[i].key = NULL;
		dict[i].value = NULL;
		i++;
	}
	free(dict);
	dict = NULL;
}
