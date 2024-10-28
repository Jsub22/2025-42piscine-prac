/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:50:11 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/31 14:50:12 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

int	count_sep(char *str, char *charset)
{
	int	i;
	int	count;
	int	flag;

	flag = 1;
	count = 0;
	i = -1;
	while (str[++i])
	{
		if (is_sep(str[i], charset))
		{
			if (!flag)
			{
				count++;
				flag = 1;
			}
		}
		else
			flag = 0;
	}
	if (flag == 1 && i > 0)
		count--;
	return (count);
}

int	count_idx(char *str, char *charset, int fst_idx, int size)
{
	int	i;

	i = fst_idx - 1;
	while (++i < size)
		if (is_sep(str[i], charset))
			break ;
	return (i);
}

void	copy_arr(char *str1, char *str2, int fst, int lst)
{
	int	i;

	i = 0;
	while (fst < lst)
		str1[i++] = str2[fst++];
	str1[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		size[2];
	int		idx[2];
	int		s_i;

	size[0] = count_sep(str, charset) + 1;
	size[1] = 0;
	while (str[size[1]])
		size[1]++;
	strs = (char **)malloc(sizeof(char *) * (size[0] + 1));
	strs[size[0]] = 0;
	s_i = 0;
	idx[0] = -1;
	while (s_i < size[0] && idx[0] + 1 < size[1])
	{
		idx[1] = count_idx(str, charset, ++idx[0], size[1]);
		if (idx[0] == idx[1])
			continue ;
		strs[s_i] = (char *)malloc(sizeof(char) * (idx[1] - idx[0] + 1));
		copy_arr(strs[s_i], str, idx[0], idx[1]);
		idx[0] = idx[1];
		s_i++;
	}
	return (strs);
}
