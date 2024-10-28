#include "../includes/main.h"

int    read_map(char *filename, t_map *info)
{
    char	buf[BUF_SIZE];
    int     n_cnt;
    int     c_cnt;
	int		fd;
	long	ret;

	c_cnt = 0;
    n_cnt = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	ret = 1;
	while (ret)
	{
        if (buf[0] == '\n')
            n_cnt++;
        if (n_cnt == 0)
            info->size = c_cnt;
        if (n_cnt == 1)
			info->col = c_cnt - info->size - 1;
		if (n_cnt == 2)
			break ;
		ret = read(fd, buf, BUF_SIZE - 1);
		if (ret < 0)
		{
			close(fd);
			return (0);
		}
        c_cnt++;
	}
	close(fd);
	return (1);
}

char    **save_map(char *filename, t_map *info)
{
    char	**m_buf;
    char	*mi_buf;
    int     i;
	int		fd;
	long	ret;

    mi_buf = (char *)malloc(sizeof(char) * (info->size + 1));
    if (mi_buf == NULL)
	{
		free(mi_buf);
        return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		free(mi_buf);
		return (0);
	}
	ret = read(fd, mi_buf, info->size + 1);
    if (ret < 0)
    {
        close(fd);
		free(mi_buf);
        return (0);
    }
    save_map_info(mi_buf, info);
	m_buf = initialize_map(info->row, info->col);
    i = -1;
    while (ret && ++i < info->row + 1)
    {
        ret = read(fd, m_buf[i], info->col);
		if (ret <= 0)
            break ;
        ret = read(fd, mi_buf, 1);
    }
    free(mi_buf);
	close(fd);
    return (m_buf);
}

void    save_map_info(char *mi_buf, t_map *info)
{
    int fst_i;
    int lst_i;
    int num;

    num = 0;
    fst_i = -1;
    lst_i = info->size;
    info->ful_c = mi_buf[--lst_i];
    info->obs_c = mi_buf[--lst_i];
    info->emp_c = mi_buf[--lst_i];
    while (++fst_i < lst_i)
        num = num * 10 + (mi_buf[fst_i] - '0');
    info->row = num;
}