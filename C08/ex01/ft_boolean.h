/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 06:21:44 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/27 06:21:45 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE       1
# define FALSE      0
# define SUCCESS    0
# define EVEN_MSG   "I have an even number of arguments.\n"
# define ODD_MSG    "I have an odd number of arguments.\n"
# define EVEN(nbr) (!((nbr) % 2))

typedef int	t_bool;

#endif
