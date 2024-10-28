/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 05:34:52 by jonghan           #+#    #+#             */
/*   Updated: 2024/08/28 17:47:54 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			result = result * 10 + (str[i] - '0');
		else
			return (-1);
		if (result >= 100)
			return (100);
		i++;
	}
	return (result);
}

void	ft_itoa(int n, char *str)
{
	int	i;
	int	len;
	int	nb;

	len = 0;
	nb = n;
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	i = len - 1;
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	str[len] = 0;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *str, int size)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	while (str[i] && i < size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
