/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:09:29 by jonghan           #+#    #+#             */
/*   Updated: 2024/08/28 18:27:50 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define B_SIZE 1048576

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

int		ft_error_check(char *target, char *file, t_dict *dict, int max_len);
void	ft_str_print(char *str, int flag);
void	ft_error_print(char *str);
void	ft_print_dict(char *str, t_dict *dict, int flag);
void	ft_print_char(char c, t_dict *dict, int flag);
void	ft_print_zero(int zero_c, t_dict *dict);
void	ft_free_memory(char *str);
void	ft_free_dict(t_dict *dict, int size);
char	*ft_set_file(int argc, char **argv);
char	*ft_set_target(int argc, char **argv);
int		ft_dict_set(char *file, int line_len, t_dict *dict, int *max_len);
int		ft_colon_get(char *file);
char	*ft_dict_str(char *file);
char	*ft_get_key(char *buf, int *buf_idx);
char	*ft_get_value(char *buf, int *buf_idx);
void	ft_after_space_del(char *dest, int count);
void	ft_get_count(char *buf, int *buf_idx, int flag, int *count);
void	ft_after_space_del(char *dest, int count);
int		ft_convert_num(char *av, t_dict *dict, int max_len);
int		ft_first_convert(char *av, t_dict *dict, int *zero_c, int *i);
int		ft_other_convert(char *av, t_dict *dict, int zero_c, int i);
void	ft_type1(char *str, t_dict *dict, int zero_c, int flag);
int		ft_type2(char *str, t_dict *dict, int zero_c, int flag);
void	ft_type3(char *str, t_dict *dict, int zero_c, int flag);
char	**ft_creat_type2_arr(char *str);
int		ft_first_zero(char *str);
int		ft_atoi(char *str);
void	ft_itoa(int n, char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strncpy(char *str, int size);
char	*ft_strdup(char *str);
int		ft_num_check(char *str);

#endif
