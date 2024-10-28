/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 05:34:44 by jonghan           #+#    #+#             */
/*   Updated: 2024/08/28 17:15:42 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*ft_dict_str(char *file)
{
	long	ret;
	int		fd;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * B_SIZE);
	fd = open(file, O_RDONLY);
	if (fd < 0 || buf == NULL)
		return (NULL);
	ret = read(fd, buf, B_SIZE - 1);
	if (ret < 0)
	{
		close(fd);
		write(2, "Dict Error\n", 11);
		return (NULL);
	}
	buf[ret] = 0;
	close(fd);
	return (buf);
}

void	ft_get_count(char *buf, int *buf_idx, int flag, int *count)
{
	if (flag == 1)
	{
		while (buf[*buf_idx] != ':')
		{
			if (buf[*buf_idx] >= '0' && buf[*buf_idx] <= '9')
				*count += 1;
			else if (!(buf[*buf_idx] == ' '))
				return ;
			*buf_idx += 1;
		}
	}
	else
	{
		while (buf[*buf_idx] != '\n')
		{
			if (buf[*buf_idx] >= 32 && buf[*buf_idx] <= 126)
				*count += 1;
			else
				return ;
			*buf_idx += 1;
		}
	}
}

char	*ft_get_key(char *buf, int *buf_idx)
{
	int		start;
	int		count;
	char	*dest;
	int		d_idx;

	count = 0;
	start = *buf_idx - 1;
	d_idx = 0;
	while (buf[*buf_idx] == '\n')
		*buf_idx += 1;
	ft_get_count(buf, buf_idx, 1, &count);
	dest = (char *)malloc(sizeof(char) * (count + 1));
	if (!count || dest == NULL)
		return (NULL);
	while (++start < *buf_idx)
	{
		if (buf[start] >= '0' && buf[start] <= '9')
			dest[d_idx++] = buf[start];
	}
	dest[count] = 0;
	return (dest);
}

void	ft_after_space_del(char *dest, int count)
{
	if (dest[count - 1] == ' ')
	{
		while (dest[count - 1] == ' ')
		{
			dest[count - 1] = 0;
			count--;
		}
	}
}

char	*ft_get_value(char *buf, int *buf_idx)
{
	int		start;
	int		count;
	char	*dest;
	int		d_idx;

	count = 0;
	d_idx = 0;
	while (buf[*buf_idx] == ' ')
		*buf_idx += 1;
	start = *buf_idx - 1;
	ft_get_count(buf, buf_idx, 0, &count);
	dest = (char *)malloc(sizeof(char) * (count + 1));
	if (!count || dest == NULL)
		return (NULL);
	while (++start <= *buf_idx)
	{
		if (buf[start] >= 32 && buf[start] <= 126)
			dest[d_idx++] = buf[start];
	}
	dest[count] = 0;
	ft_after_space_del(dest, count);
	return (dest);
}
