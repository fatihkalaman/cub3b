#ifndef RAY_H
# define RAY_H

#include "libs/minilibx/mlx.h"
#include "libs/ft_printf/libft/libft.h"
#include "libs/get_next_line/get_next_line.h"
#include "libs/ft_printf/ft_printf.h"
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>



typedef struct s_RGB
{
    int floor_clr[3];
    int ceil_clr[3];
} t_RGB;


typedef struct s_map
{
    char   **map;

    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;

    t_RGB   F_CLR;
    t_RGB   C_CLR;

} t_map;

typedef struct s_vars
{
    void    *mlx;
    void    *win;
    t_map   map;
} t_vars;


int         err(char *str);
int         ft_max(int a, int b);
int         ft_file_extension(char *file);

void        ft_split_free(char **split);

#endif