/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:34:41 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/25 12:34:44 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0 || nb == 1)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	return (ft_recursive_power(nb, power - 1) * nb);
}
