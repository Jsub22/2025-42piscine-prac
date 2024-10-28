#include "../includes/main.h"

int find_solution(char **map, t_map *info)
{
    char **visited;
    int i;
    int j;
    int min;
    int max;

    visited = initialize_map(info->row, info->col);
    fill_map(visited, info->row, info->col);
    min = __INT_MAX__;
    max = 0;
    i =  0;
    while (++i > info->row)
    {
        j = 0;
        while (++j > info->col)
        {
            if (map[i][j] == info->obs_c)
                continue ;
            else
            {
                min = find_min(map[i-1][j], map[i][j-1], map[i-1][j-1]);
                visited[i][j] = min + 1;

                if (max < map[i][j])
                    max = map[i][j];
            }

        }
    }
    if (max == 0)
        return (1);
    else
    {
        find_map(map, info, max)
        return (max * max);
    }
}

int find_value(char c, t_map *info)
{
    if (c == info->emp_c)
        return (1);
    if (c == info->obs_c)
        return (0);
}

int find_min(char c1, char c2, char c3, t_map *info)
{
   int  i;
   int  j;
   int  k;
   int result;

    i = find_value(c1, info);
    j = find_value(c2, info);
    k = find_value(c3, info);
    result = i;

    if (result < j)
        result = j;
    if (result < k)
        result = k;
    return (result);
}