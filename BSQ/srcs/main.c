#include "../includes/main.h"

int main(int argc, char *argv[])
{
    t_map *info;
	char **map;
	int	round;

	round = 0;
	while (++round < argc)
	{
        info = initialize_info();
        if (info == NULL \
        || !read_map(argv[round], info))
        {
            print_error("map error\n");
            finalize_info(info);
			continue ;
        }
        map = save_map(argv[round], info);
        if (!is_valid_map(map, info) || !find_solution(map, info))
			print_error("map error\n");
        else
    		print_map(map, info->row, info->col);
        finalize_map(map, info->row);
        finalize_info(info);
        write(1, "\n", 1);
	}
    return (0);
}
