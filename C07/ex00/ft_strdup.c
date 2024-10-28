/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:29:04 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/30 12:21:38 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

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
