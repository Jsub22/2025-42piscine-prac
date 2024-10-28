/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:59:20 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/23 15:59:21 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d_len;
	unsigned int	s_len;

	d_len = 0;
	s_len = 0;
	while (dest[d_len])
		d_len++;
	while (src[s_len])
		s_len++;
	i = d_len;
	j = 0;
	while (src[j] && d_len + j + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (d_len < size)
		return (s_len + d_len);
	else
		return (s_len + size);
}
