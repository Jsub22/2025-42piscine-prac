/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:57:35 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/23 02:57:37 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	save_i;

	i = 0;
	j = 0;
	save_i = 0;
	while (str[i] && to_find[j])
	{
		if (str[i] == to_find[j])
		{
			if (j++ == 0)
				save_i = i;
		}
		else if (j > 0)
		{
			i = save_i;
			j = 0;
		}
		i++;
	}
	if (!to_find[j])
		return (&str[save_i]);
	else
		return (NULL);
}
