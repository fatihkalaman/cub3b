CC	= gcc
MINILIBX	= libs/minilibx/libmlx.a
PRINTF		= libs/ft_printf/libftprintf.a
GNL			= libs/get_next_line/gnl.a
NAME 		= cub3d
FLAGS		= -Wall -Wextra -Werror 
OFLAGS		= -framework OpenGL -framework AppKit
SRCS 		= ./main.c
OBJS 		= $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(MINILIBX) $(OBJS) d
	
	@$(CC) $(OFLAGS) $(FLAGS) $(OBJS) -o $(NAME) $(MINILIBX) $(PRINTF) $(GNL)

$(MINILIBX):
	@echo "\n\033[0;35m⏳ LOADING...\033[0m\n"
	@make -s -C libs/minilibx 2>/dev/null

d: 
	@make -s -C libs/ft_printf
	@make -s -C libs/ft_printf/libft
	@make -s -C libs/get_next_line
	
	@echo "✅"

re: fclean all

clean:
	@rm -f main/*.o
	@rm -f libs/minilibx/*.o
	@rm -f libs/ft_printf/libft/*.o
	@rm -f libs/ft_printf/*.o
	@rm -f libs/get_next_line/*.o
fclean: clean
	@rm -rf $(NAME)
	@rm -rf libs/minilibx/*.a
	@rm -rf libs/ft_printf/libft/*.a
	@rm -rf libs/ft_printf/*.a
	@rm -rf libs/get_next_line/*.a
	@echo "🗑️"

norm:
	@norminette main

.PHONY: clean run fclean re all d bonus norm