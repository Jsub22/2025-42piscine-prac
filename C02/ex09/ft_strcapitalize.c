/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:19:39 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/18 23:19:40 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (flag)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			flag = 0;
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		}
		if (!(str[i] >= 'a' && str[i] <= 'z') \
		&& !(str[i] >= 'A' && str[i] <= 'Z') \
		&& !(str[i] >= '0' && str[i] <= '9'))
			flag = 1;
		i++;
	}
	return (str);
}
