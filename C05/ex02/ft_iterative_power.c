/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:12:01 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/25 12:12:02 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	num;

	if (power == 0 || nb == 1)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	num = 1;
	while (power-- > 0)
		num *= nb;
	return (num);
}
