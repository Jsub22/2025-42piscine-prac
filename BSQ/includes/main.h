#ifndef MAIN_H
# define MAIN_H
# define O_RDONLY 00
# define BUF_SIZE 2

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_map
{
    int row;
    int col;
    int size;
    char emp_c;
    char obs_c;
    char ful_c;
} t_map;

int    read_map(char *filename, t_map *info);
char    **save_map(char *filename, t_map *info);
void    save_map_info(char *mi_buf, t_map *info);
void    find_map(char **map, t_map *info, int max);

t_map   *initialize_info();
char    **initialize_map(int row, int col);
void    finalize_map(char **map, int row);
void    finalize_info(t_map *info);

int find_solution(char **map, t_map *info);

char	*ft_strncpy(char *dest, char *src, unsigned int n);

void    print_map(char **map, int row, int col);
void	print_error(char *msg);

int     is_valid_map_info();
int     is_valid_map();

#endif

/* 지도 줄 수, 빈 문자, 장애물 문자, 유효 문자 */
/* 빈 문자를 유효 문자로 바꿔서 가장 큰 정사각형을 표현 */
/* 지도의 맨 위, 가장 왼쪽 정사각형 */
/* 1~n 개의 파일을 매개변수로 처리 */