#include "../includes/main.h"

t_map   *initialize_info()
{
    t_map *info;
    
    info = (t_map *)malloc(sizeof(t_map));
    if (info == NULL)
        return (NULL);
    info->row = 0;
    info->col = 0;
    info->size = 0;
    info->emp_c = '.';
    info->obs_c = '.';
    info->ful_c = '.';
    return info;
}

char    **initialize_map(int row, int col)
{
    char **map;
    int i;

    i = -1;
    map = (char **)malloc(sizeof(char *) * (row + 1));
    if (!map)
        return (NULL);
    while (++i < row)
    {
        map[i] = (char *)malloc(sizeof(char) * (col + 1));
        if (!map[i])
            return (NULL);
    } 
    map[row] = NULL;
    return (map);
}

void    fill_map(char **map, int row, int col)
{
    int i;
    int j;

    i = -1;
    while (++i < row)
    {
        j = -1;
        while (++j < col)
            map[i][j] = '0';
    }
}

void    finalize_info(t_map *info)
{    
    if (info == NULL)
        return ;
    free(info);
}

void    finalize_map(char **map, int row)
{
    int i;
    
    if (map == NULL)
        return ;
    i = -1;
    while (++i < row)
    {
        if (map[i] != NULL)
            free(map[i]);
    }
    free(map);
}

void    print_map(char **map, int row, int col)
{
    int i;
    int j;

    i = -1;
    while (++i < row)
    {
        j = -1;
        while (++j < col)
            write(1, &map[i][j], 1);
        write(1, "\n", 1);
    }
}

void    find_map(char **map, t_map *info, int max)
{
    int i;
    int j;
    int flag;
    int x;
    int y;

    x = 0;
    y = 0;
    flag = 0;
    i = -1;
    while (++i < info->row)
    {
        j = -1;
        while (++j < info->col)
        {
            if (map[i][j] == max)
            {
                x = i;
                y = j;
                flag = 1;
                break ;
            }
        }
        if (flag)
            break ;
    }
    while (i-- >  x - max)
    {
        while (j-- >  y - max)
            map[i][j] = info->ful_c;
    }
}