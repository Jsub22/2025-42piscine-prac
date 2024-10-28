/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:28:54 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/29 18:32:14 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;
	int	*arr;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	arr = (int *)malloc(sizeof(int) * (size));
	if (arr == 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (size);
}
