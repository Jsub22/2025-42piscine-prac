/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:53:06 by subjeong          #+#    #+#             */
/*   Updated: 2024/09/27 14:53:10 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# define O_RDONLY 00
# define BUF_SIZE 2

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

int		isfile(char filename[]);
void	putstr(char str[]);
void	ft_putchar(char c);

#endif
