S		= srcs/
O		= objs/
I		= incs/
D		= deps/

NAME	= test

SRCS	= main.c

CC		= gcc

CFLAGS	+=

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
	@$(CC) $(LDFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

clean:
	make clean -C ./mlx
	@$(RM) $D $O

fclean: clean
	make clean -C ./mlx
	@$(RM) $(NAME)

re: fclean all

-include $(DEPS)
