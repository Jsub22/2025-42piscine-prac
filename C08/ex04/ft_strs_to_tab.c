/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 00:58:01 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/30 15:21:37 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		size;
	char	*arr;

	size = 0;
	while (src[size])
		size++;
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (arr == NULL)
		return (NULL);
	ft_strcpy(arr, src);
	return (arr);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*obs;
	int			i;
	int			j;

	if (ac < 0 || av == NULL)
		return (NULL);
	obs = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (obs == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		obs[i].size = j;
		obs[i].str = av[i];
		obs[i].copy = ft_strdup(av[i]);
		i++;
	}
	obs[i].str = NULL;
	return (obs);
}
