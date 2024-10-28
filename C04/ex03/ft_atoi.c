/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:18:45 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/24 19:18:46 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
	|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

int	is_nbr(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	while (is_sign(str[i]))
		if (str[i++] == '-')
			sign *= -1;
	while (1)
	{
		if(!is_nbr(str[i]))
			break ;
		num = (num * 10) + (sign * (str[i] - '0'));
		i++;
	}
	return (num);
}
