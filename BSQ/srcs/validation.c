#include "../includes/main.h"

int is_valid_map_info()
{
    if (1)
        return (0);
    else
        return (1);
}

int is_valid_map()
{
    return (1);
}

void	print_error(char *msg)
{
	int	i;

	i = -1;
	while (msg[++i])
		write(1, &msg[i], 1);
}