/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:44:21 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/25 02:44:22 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (base[++j])
		{
			if (base[j] == '+' || base[j] == '-')
				return (0);
			else if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

int	nbr_to_base(int nbr, char *base, int size, char *buf)
{
	int	i;
	int	sign;

	if (nbr < 0)
		sign = -1;
	else
		sign = 1;
	i = 0;
	if (nbr == 0)
		buf[i++] = base[0];
	while (nbr != 0)
	{
		buf[i++] = base[(nbr % size) * sign];
		nbr = nbr / size;
	}
	buf[i] = '\0';
	return (sign);
}

int	size_of_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	print_base(char *buf, int sign)
{
	int		i;
	char	prt;

	if (sign == -1)
		write(1, "-", 1);
	i = 0;
	while (buf[i])
		i++;
	i--;
	while (i >= 0)
	{
		prt = buf[i];
		write(1, &prt, 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	int		sign;
	char	b[33];
	char	*buf;

	buf = b;
	if (!is_valid_base(base))
		return ;
	size = size_of_base(base);
	sign = nbr_to_base(nbr, base, size, buf);
	print_base(buf, sign);
}
