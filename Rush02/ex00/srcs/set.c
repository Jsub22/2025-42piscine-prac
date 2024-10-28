/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 05:35:04 by jonghan           #+#    #+#             */
/*   Updated: 2024/08/28 19:22:14 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*ft_set_file(int argc, char **argv)
{
	if (argc == 2)
		return (ft_strdup("numbers.dict"));
	else
		return (ft_strdup(argv[1]));
}

char	*ft_set_target(int argc, char **argv)
{
	if (argc == 2)
		return (ft_strdup(argv[1]));
	else
		return (ft_strdup(argv[2]));
}

int	ft_dict_set(char *file, int line_len, t_dict *dict, int *max_len)
{
	int		i;
	char	*buf;
	int		buf_idx;

	i = 0;
	buf_idx = 0;
	buf = ft_dict_str(file);
	if (buf == NULL)
		return (1);
	while (i < line_len)
	{
		dict[i].key = ft_get_key(buf, &buf_idx);
		buf_idx++;
		dict[i].value = ft_get_value(buf, &buf_idx);
		if (*max_len < ft_strlen(dict[i].key))
			*max_len = ft_strlen(dict[i].key);
		buf_idx++;
		if (dict[i].key == NULL || dict[i].value == NULL)
			return (1);
		i++;
	}
	dict[i].key = NULL;
	dict[i].value = NULL;
	ft_free_memory(buf);
	return (0);
}

int	ft_colon_count(int fd, char *buf)
{
	int		count;
	long	ret;

	count = 0;
	ret = read(fd, buf, 1);
	if (ret < 0)
	{
		close(fd);
		ft_free_memory(buf);
		write(2, "Dict Error\n", 11);
		return (0);
	}
	while (ret)
	{
		buf[1] = 0;
		if (buf[0] == ':')
			count++;
		ret = read(fd, buf, 1);
	}
	return (count);
}

int	ft_colon_get(char *file)
{
	int		count;
	int		fd;
	char	*buf;

	fd = open(file, O_RDONLY);
	buf = (char *)malloc(sizeof(char) * 2);
	if (fd < 0 || buf == NULL)
	{
		ft_free_memory(buf);
		close(fd);
		return (0);
	}
	count = ft_colon_count(fd, buf);
	ft_free_memory(buf);
	close(fd);
	return (count);
}
