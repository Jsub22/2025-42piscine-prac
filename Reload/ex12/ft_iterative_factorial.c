/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:35:55 by subjeong          #+#    #+#             */
/*   Updated: 2024/09/27 14:36:20 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	num;

	if (nb < 0)
		return (0);
	num = 1;
	while (nb > 0)
		num = num * nb--;
	return (num);
}
