/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:53:37 by subjeong          #+#    #+#             */
/*   Updated: 2024/09/27 15:09:35 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	isfile(char filename[])
{
	char	buf[BUF_SIZE];
	int		fd;
	long	ret;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	ret = read(fd, buf, BUF_SIZE - 1);
	if (ret < 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

void	putstr(char str[])
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		putstr("File name missing.");
	else if (argc > 2)
		putstr("Too many arguments.");
	else if (!isfile(argv[1]))
		putstr("Cannot read file.");
}
