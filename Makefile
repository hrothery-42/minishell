# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:18:52 by cfabian           #+#    #+#              #
#    Updated: 2022/05/20 10:41:17 by hrothery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= 	minishell
SRC 		= 	src
SRCS 		= 	$(SRC)/builtins.c \
				$(SRC)/builtin_parser.c \
				$(SRC)/builtin_utils.c \
				$(SRC)/env_list.c \
				$(SRC)/error_msg.c \
				$(SRC)/exec_utils.c \
				$(SRC)/export.c \
				$(SRC)/export_list.c \
				$(SRC)/free.c \
				$(SRC)/gnl_delimit.c \
				$(SRC)/heredoc.c \
				$(SRC)/init_export_list.c \
				$(SRC)/lexer.c \
				$(SRC)/list_to_string.c \
				$(SRC)/main.c \
				$(SRC)/parser.c \
				$(SRC)/piping.c \
				$(SRC)/quotes_and_envvars.c \
				$(SRC)/redirection.c \
				$(SRC)/signals.c \
				$(SRC)/unset.c
												
OBJ			= 	obj
OBJS		= 	$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
CC			= 	gcc
RL_MAC		= 	-I $(HOME)/goinfre/.brew/opt/readline/include/ -L $(HOME)/goinfre/.brew/opt/readline/lib/
CFLAGS		=   -Wall -Werror -Wextra 
RM			= 	rm -f
LIB 		=	libft.a
INCLUDES	=	minishell.h libft.h

all: $(NAME)

fix:
	./fix.sh

$(OBJ):
	mkdir $(OBJ)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@ -g

ifeq ($(shell uname), Linux)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) $(LIB) -g  -o $(NAME) -lreadline $(CFLAGS)

endif

ifeq ($(shell uname), Darwin)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) $(LIB) -g  -o $(NAME) -lreadline $(CFLAGS) $(RL_MAC)

endif

$(LIB):
	@make -C ./libft/
	mv ./libft/$(LIB) ./$(LIB)
	cp ./libft/libft.h ./libft.h

clean:
	$(RM) $(OBJ)/*
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME) $(LIB)
	make -C libft fclean

re: fclean all

norm:
	@norminette $(SRC)/*.c $(INCLUDES)
	@make norm -C ./libft/

memcheck: all
	valgrind --leak-check=full ./minishell

	
.PHONY: all clean fclean re norm memcheck
