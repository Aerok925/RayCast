S		= srcs/
O		= objs/
I		= incs/
D		= deps/

NAME	= cub3d

SRCS	= 	main.c parser_map.c \
			check_valid.c correct_map_init.c \
			free_functions.c init_paths_colors.c

LIBFT	=	/libft/libft.a

CC		= gcc

CFLAGS	+= -Wall -Wextra -Werror

CFLAGS	+= -I$I

SRCS	:= $(foreach file,$(SRCS),$S$(file))
OBJS	= $(SRCS:$S%=$O%.o)
DEPS	= $(SRCS:$S%=$D%.d)

RM		= /bin/rm -rf

.PHONY: all clean fclean re

all: $(NAME)


$O:
	@mkdir $@

$(OBJS): | $O

$(OBJS): $O%.o: $S%
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$D:
	@mkdir $@

$(DEPS): | $D

$(DEPS): $D%.d: $S%
	@$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): $(OBJS)
	@make -C ./mlx
	@make -C ./libft
	@$(CC) $(LDFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@ -L./libft -lft

clean:
	make clean -C ./mlx
	@$(RM) $D $O
	@make clean -C ./libft

fclean: clean
	make clean -C ./mlx
	@$(RM) $(NAME)
	@make clean -C ./libft

re: fclean all

-include $(DEPS)
