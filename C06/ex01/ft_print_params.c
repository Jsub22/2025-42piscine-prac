/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:49:29 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/25 22:49:31 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char *v)
{
	int	i;

	i = -1;
	while (v[++i])
		write(1, &v[i], 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		ft_putchar(argv[i]);
		ft_putchar("\n");
	}
	return (0);
}
