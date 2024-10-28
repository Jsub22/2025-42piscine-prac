# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/30 11:01:34 by subjeong          #+#    #+#              #
#    Updated: 2024/09/01 10:20:08 by subjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

cc="cc"
src=*.c
flags="-c -Wall -Werror -Wextra"
lib_name="libft.a"

$cc $flags $src
ar rc $lib_name *.o
ranlib $lib_name
rm *.o
