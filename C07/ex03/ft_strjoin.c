/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:28:15 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/29 18:28:18 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	join_str(int size, char *arr, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;
	int	idx;

	i = -1;
	idx = 0;
	while (++i < size)
	{
		k = -1;
		while (strs[i][++k])
		{
			arr[idx++] = strs[i][k];
		}
		if (i < size - 1)
		{
			j = -1;
			while (sep[++j])
			{
				arr[idx++] = sep[j];
			}
		}
	}
	arr[idx] = '\0';
}

int	get_total_len(char **strs, char *sep, int size)
{
	int	i;
	int	num;

	num = 0;
	i = -1;
	while (++i < size)
	{
		num += ft_strlen(strs[i]);
		if (i < size - 1)
			num += ft_strlen(sep);
	}
	return (num);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		arr_s;

	arr_s = get_total_len(strs, sep, size);
	arr = (char *)malloc(sizeof(char) * (arr_s + 1));
	arr[arr_s] = '\0';
	join_str(size, arr, strs, sep);
	return (arr);
}
