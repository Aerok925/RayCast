# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 19:33:46 by jkieth            #+#    #+#              #
#    Updated: 2021/10/31 17:15:27 by jkieth           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_strchr.c ft_strdup.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_tolower.c \
			ft_toupper.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_striteri.c

BNS		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

NAME	=	libft.a

CC		=	gcc

OBJS	=	${SRCS:.c=.o}

OBJSBNS	=	${BNS:.c=.o}

ARLIB	=	ar r

RANLIB	=	ranlib

RM		=	rm -f

HEAD	=	libft.h

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEAD}
			${ARLIB} ${NAME} ${OBJS}
			${RANLIB} ${NAME}

bonus:		${OBJS} ${OBJSBNS} ${HEAD}
			${ARLIB} ${NAME} ${OBJS} ${OBJSBNS}
			${RANLIB} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSBNS}

re:         fclean all

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean bonus re
