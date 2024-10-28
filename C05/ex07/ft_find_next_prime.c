/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:20:30 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/25 13:20:31 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 2147483647)
		return (1);
	i = 1;
	while (++i <= nb / 2)
		if (nb % i == 0)
			return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 0;
	while (ft_is_prime(nb + i) == 0)
		i++;
	return (nb + i);
}
#include <stdio.h>

int ft_find_next_prime(int nb);

int main()
{
    for (int i = -4; i <= 10; i++)
        printf("%d\n", ft_find_next_prime(i));
    printf("%d\n", ft_find_next_prime(2147483641));
    printf("%d\n", ft_find_next_prime(2147483643));
    printf("%d\n", ft_find_next_prime(2147483645));
    printf("%d\n", ft_find_next_prime(2147483647));
    return 0;
}