#include <ray.h>

int ft_max(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}

int ft_file_extension(char *file)
{
    char    **split;
    int     i;

    split = ft_split(file, '.');
    i = 0;

    while (split[i])
        i++;
    if (i <= 1)
    {
        ft_printf("Error\nWrong file format\n");
        return 0;
    }

    if (ft_strncmp(split[i - 1], "cub", ft_max(3, ft_strlen(split[i - 1]))))
    {
        ft_printf("Error\nFile format must be .cub\n");
        return 0;
    }
    return (1);
}