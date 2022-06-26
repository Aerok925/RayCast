S		= srcs/
O		= objs/
I		= incs/
D		= deps/
DB		= deps_b/
OB		= objs_b/

NAME	= cub3d

NAME_BONUS	= cub3d_bonus

SRCS	= 	main_no_bonus.c parser_map.c \
			parse_utils.c read_file.c colors.c \
			check_valid.c correct_map_init.c \
			free_functions.c paths_colors.c \
			calculations_for_raycast.c \
			draw_line.c SetImgToTemplate.c \
			raycast.c \
			check_dist.c \
			draw_all_no_bonus.c \
			init.c \
			destroy.c button_keyboard_no_bonus.c

SRCS_BONUS = main.c parser_map.c \
             parse_utils.c read_file.c colors.c \
             check_valid.c correct_map_init.c \
             free_functions.c paths_colors.c \
             calculations_for_raycast.c \
             draw_line.c SetImgToTemplate.c \
             minimap_bonus.c raycast.c \
             check_dist.c mini_mini_bonus.c \
             draw_all.c button_keyboard.c \
             mouse_bonus.c init.c \
             destroy.c

LIBFT	=	/libft/libft.a

CC		= gcc

CFLAGS	+= -Wall -Wextra -Werror

CFLAGS	+= -I$I

SRCS	:= $(foreach file,$(SRCS),$S$(file))
SRCS_BONUS := $(foreach file,$(SRCS_BONUS),$S$(file))

OBJS	= $(SRCS:$S%.c=$O%.o)
DEPS	= $(SRCS:$S%.c=$D%.d)

OBJS_BONUS	= $(SRCS_BONUS:$S%.c=$(OB)%.o)
DEPS_BONUS	= $(SRCS_BONUS:$S%.c=$(DB)%.d)

RM		= /bin/rm -rf

.PHONY: all clean fclean re bonus

all:  $(NAME)

bonus:  $(NAME_BONUS)

$(OBJS_BONUS): | $(OB)

$(OBJS_BONUS): $(OB)%.o: $S%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(DEPS_BONUS): | $(DB)

$(DEPS_BONUS): $(DB)%.d: $S%.c
	@$(CC) $(CFLAGS) -MM -MF $@ -MT "$(OB)$*.o $@" $<

$(OB):
	@mkdir $@

$(DB):
	@mkdir $@

$(NAME_BONUS): $(OBJS_BONUS)
	@make -C ./mlx123
	@make -C ./libft
	@$(CC) $(LDFLAGS) -Lmlx123 -lmlx -framework OpenGL -framework AppKit  $^ -o $@ -L./libft -lft

$O:
	@mkdir $@

$(OBJS): | $O

$(OBJS): $O%.o: $S%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$D:
	@mkdir $@

$(DEPS): | $D

$(DEPS): $D%.d: $S%.c
	@$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<


$(NAME): $(OBJS)
	@make -C ./mlx123
	@make -C ./libft
	@$(CC) $(LDFLAGS) -Lmlx123 -lmlx -framework OpenGL -framework AppKit  $^ -o $@ -L./libft -lft

clean:
	make clean -C ./mlx123
	@$(RM) $D $O $(DB) $(OB)
	@make clean -C ./libft

fclean: clean
	make clean -C ./mlx123
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@make fclean -C ./libft

re: fclean all bonus

-include $(DEPS_BONUS)
-include $(DEPS)