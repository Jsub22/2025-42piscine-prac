/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:56:50 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/19 00:56:53 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print(char c)
{
	write(1, &c, 1);
}

void	ft_print_addr(unsigned long long addr)
{
	char	*hex;
	char	buf[16];
	int		i;

	hex = "0123456789abcdef";
	i = 16;
	while (--i >= 0)
	{
		buf[i] = hex[addr % 16];
		addr = addr / 16;
	}
	while (++i < 16)
		ft_print(buf[i]);
}

void	ft_print_hex(unsigned char *addr, unsigned int num, unsigned int size)
{
	char			*hex;
	unsigned int	i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		ft_print(hex[addr[num + i] / 16]);
		ft_print(hex[addr[num + i] % 16]);
		if (i % 2 == 1 && i != 0)
			ft_print(' ');
		i++;
	}
	ft_print(' ');
}

void	ft_print_dot(unsigned char *addr, unsigned int num, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size && addr[num + i] != '\0')
	{
		if (!((int)addr[num + i] >= 32 && (int)addr[num + i] <= 126))
			ft_print('.');
		else
			ft_print(addr[num + i]);
		i++;
	}
	if (addr[num + i] == '\0')
		ft_print('.');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	j = 16;
	s = (int)size;
	while (i * 16 < s)
	{
		if (s - i * 16 < 16)
			j = s - i * 16;
		ft_print_addr((unsigned long long)addr + i * 16);
		ft_print(':');
		ft_print(' ');
		ft_print_hex((unsigned char *)addr, i * 16, j);
		ft_print(' ');
		ft_print_dot((unsigned char *)addr, i * 16, j);
		ft_print('\n');
		i++;
	}
	return (0);
}
