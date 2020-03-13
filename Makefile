# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 12:39:56 by pntsunts          #+#    #+#              #
#    Updated: 2020/03/13 12:44:08 by pntsunts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

SRC = ft_ls.c recursion.c ft_ls_a.c ft_checkf.c ft_confirm.c ft_ls_a.c  printr.c ft_printl.c ft_isdir.c ft_time.c

OBJ = $(SRC:.c=.o)

$(NAME):
	@gcc -c $(SRC) $(FLAGS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@rm -rf $(OBJ)

all: $(NAME)

clean:
	@rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

c:
	@gcc $(FLAGS) main.c libft/libft.a $(NAME) -o ft_ls

re: fclean all

N: 
	norminette
