/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:35:55 by subjeong          #+#    #+#             */
/*   Updated: 2024/09/27 14:36:20 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*arr;

	if (max <= min)
		return (NULL);
	size = max - min;
	arr = (int *)malloc(sizeof(int) * (size));
	if (arr == NULL)
	{
		return (NULL);
	}
	i = -1;
	while (++i < size)
		arr[i] = min + i;
	return (arr);
}
