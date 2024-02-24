#include <stdio.h>
#include "ray.h"
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>

int find_clr(t_vars *game, char **map, int i, int j)
{
	int a = 0;
 	while (map[i]++[j])
	{
		while (map[i][j] == ' ')
			j++;
		while (map[i][j] >= '0' && map[i][j] <= '9' && a == 0)
		{
			if (map[i][j + 1] == ',')
				j++;
			ft_printf("A: %c\n", map[i][j]);
			j++;
		}
		while (map[i][j] >= '0' && map[i][j] <= '9' && a == 1)
		{
			if (map[i][j + 1] == ',')
				a++;
			ft_printf("B: %c\n", map[i][j]);
			j++;
		}
		while (map[i][j] >= '0' && map[i][j] <= '9' && a == 2)
		{
			if (map[i][j + 1] == ',')
				a++;
			ft_printf("C: %c\n", map[i][j]);
			j++;
		}
	}
	return 0;
}

int color_fc(t_vars *game, char **map, int i, int j)
{
	if (map[i][j] == 'F')
	{
		find_clr(game, map, i, j);
		//game->map.F_CLR.R = ft_substr(map[i], 2, ft_strlen(map[i]) - 3);
	}
	//if (map[i][j] == 'C')
		//game->map.F_CLR.R = ft_substr(map[i], 2, ft_strlen(map[i]) - 3);
	return 0;
}

int	direction(t_vars *game, char **map, int i, int j)
{
	if (map[i][j] == 'N')
		game->map.NO = ft_substr(map[i], 2, ft_strlen(map[i]) - 3);
	else if (map[i][j] == 'E')
		game->map.EA = ft_substr(map[i], 2, ft_strlen(map[i]) - 3);
	else if (map[i][j] == 'W')
		game->map.WE = ft_substr(map[i], 2, ft_strlen(map[i]) - 3);
	else if (map[i][j] == 'S')
		game->map.SO = ft_substr(map[i], 2, ft_strlen(map[i]) - 3);
	return 0;
}

void up_thinks(char **map, t_vars game)
{
	int	i;
	int	j;
	int len_tmp;

	i = 0;
	j = 0;

	while(map[i])
	{
		j = 0;
		len_tmp = ft_strlen(map[i]);
		while (map[i][j] && j < len_tmp)
		{
			// if (map[i][j] != '\n' || map[i][j] != ' ' || map[i][j] != '\t')
			// 	j++;
			if (map[i][j] == 'F' || map[i][j] == 'C')
				color_fc(&game, map, i, j);
			if (map[i][j] == 'N' && map[i][j + 1] == 'O')
				direction(&game, map, i, j);
			else if (map[i][j] == 'S' && map[i][j + 1] == 'O')
				direction(&game, map, i, j);
			else if (map[i][j] == 'W' && map[i][j + 1] == 'E')
				direction(&game, map, i, j);
			else if (map[i][j] == 'E' && map[i][j + 1] == 'A')
				direction(&game, map, i, j);
			else
				return (void)0;
			j++;
		}
		i++;
	}
}

char  **read_map(char *map)
{
	int fd;
	char *line;
	char **str;
	int i;

	i = 0;

	fd = open(map, O_RDONLY);
	str = (char **)malloc(sizeof(char *) * 1000);
	if (!str)
	{
		ft_printf("Error\n");
		return 0;
	}
	line = get_next_line(fd);
	while (line)
	{
		str[i] = line;
		line = get_next_line(fd);
		i++;
	}
	return str;
}

int main(int argc, char **argv)
{
	t_vars vars;
	char   **map;
	vars.mlx = mlx_init();



	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Cub3D");
	map = read_map(argv[1]);
	up_thinks(map, vars);


	mlx_loop(vars.mlx);
	return 0;
}