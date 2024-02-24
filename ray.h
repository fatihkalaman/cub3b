#ifndef RAY_H
# define RAY_H

#include "libs/minilibx/mlx.h"
#include "libs/ft_printf/libft/libft.h"
#include "libs/get_next_line/get_next_line.h"
#include "libs/ft_printf/ft_printf.h"


typedef struct s_RGB
{
    int R;
    int G;
    int B;
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

#endif