# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 21:05:06 by cfabian           #+#    #+#              #
#    Updated: 2022/05/12 00:53:29 by cfabian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libft
CFLAGS		= -Werror -Wall -Wextra
CC			= gcc
RM			= rm -f
HEAD		= libft.h

SRC			= src
SRCS		= \
$(SRC)/ft_memset.c \
$(SRC)/ft_bzero.c \
$(SRC)/ft_memcpy.c \
$(SRC)/ft_memccpy.c \
$(SRC)/ft_memmove.c \
$(SRC)/ft_memchr.c \
$(SRC)/ft_memcmp.c \
$(SRC)/ft_strlen.c \
$(SRC)/ft_strlcpy.c \
$(SRC)/ft_strlcat.c \
$(SRC)/ft_strchr.c \
$(SRC)/ft_strrchr.c \
$(SRC)/ft_strnstr.c \
$(SRC)/ft_strcmp.c \
$(SRC)/ft_strncmp.c \
$(SRC)/ft_atoi.c \
$(SRC)/ft_atoi_digits_only.c \
$(SRC)/ft_atoi_base.c \
$(SRC)/ft_isalpha.c \
$(SRC)/ft_isdigit.c \
$(SRC)/ft_isalnum.c \
$(SRC)/ft_isascii.c \
$(SRC)/ft_isprint.c \
$(SRC)/ft_isspace.c \
$(SRC)/ft_toupper.c \
$(SRC)/ft_tolower.c \
$(SRC)/ft_calloc.c \
$(SRC)/ft_realloc.c \
$(SRC)/ft_strdup.c \
$(SRC)/ft_substr.c \
$(SRC)/ft_strjoin.c \
$(SRC)/ft_strjoin_gnl.c \
$(SRC)/ft_strtrim.c \
$(SRC)/ft_split.c \
$(SRC)/ft_split_slash.c \
$(SRC)/ft_itoa.c \
$(SRC)/ft_strmapi.c \
$(SRC)/ft_putchar_fd.c \
$(SRC)/ft_putstr_fd.c \
$(SRC)/ft_putnbr_fd.c \
$(SRC)/ft_putendl_fd.c \
$(SRC)/ft_lstnew.c \
$(SRC)/ft_lstadd_front.c \
$(SRC)/ft_lstsize.c \
$(SRC)/ft_lstlast.c \
$(SRC)/ft_lstadd_back.c \
$(SRC)/ft_lstdelone.c \
$(SRC)/ft_lstclear.c \
$(SRC)/ft_lstiter.c \
$(SRC)/ft_lstmap.c \
$(SRC)/get_next_line_bonus.c \
$(SRC)/print_c.c \
$(SRC)/ft_printf.c 
#$(SRC)/gnl_delimit.c
# $(wildcard $(SRC)/*.c)

OBJ		= obj
OBJS	= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
NAME	= libft.a
TEST	= tests/main.c


all: $(NAME)

$(NAME):$(OBJS)
	@ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@ -g

$(OBJ):
	mkdir $(OBJ)

test:	norm all $(TEST)
	$(CC) -g -o $(BIN).test $(TEST) -L./bin -lft
	./$(BIN).test | cat -e

clean:
	$(RM) obj/*

fclean:	clean
	$(RM) $(NAME)

re: 	fclean all

norm:
	@norminette $(SRC)/*.c libft.h

bonus: all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re norm