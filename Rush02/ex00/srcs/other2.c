/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 05:34:57 by jonghan           #+#    #+#             */
/*   Updated: 2024/08/28 17:50:06 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL || !len)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_num_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_first_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == '0')
		i++;
	return (i);
}
