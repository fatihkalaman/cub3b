#include "ray.h"

int ft_init_all(t_vars *game)
{
	game->map.map = ft_calloc(1, sizeof(char *));
	if (!game->map.map)
		return (0);
	game->map.map[0] = NULL;
	game->map.NO = NULL;
	game->map.SO = NULL;
	game->map.EA = NULL;
	game->map.WE = NULL;
	game->map.F_CLR.floor_clr[0] = 256;
	game->map.F_CLR.floor_clr[1] = 256;
	game->map.F_CLR.floor_clr[2] = 256;
	game->map.F_CLR.ceil_clr[0] = 256;
	game->map.F_CLR.ceil_clr[1] = 256;
	game->map.F_CLR.ceil_clr[2] = 256;
}

int main(int argc, char **argv)
{
	t_vars vars;
	char   **map;
	if (argc != 2)
		err("Error\nMap path is not specified");
	if (!ft_init_all)
		err("Error\nInitialize error");
	vars.mlx = mlx_init();
	

	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Cub3D");
	map = read_map(argv[1]);
	up_thinks(map, vars);


	mlx_loop(vars.mlx);
	return 0;
}