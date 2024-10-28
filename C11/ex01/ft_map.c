/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:40:43 by subjeong          #+#    #+#             */
/*   Updated: 2024/09/01 16:40:44 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * (length));
	if (arr == NULL)
		return (NULL);
	arr[length] = '\0';
	i = -1;
	while (++i < length)
	{
		arr[i] = f(tab[i]);
	}
	return (arr);
}
