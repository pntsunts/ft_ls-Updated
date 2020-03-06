# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 12:39:56 by pntsunts          #+#    #+#              #
#    Updated: 2020/03/06 10:21:36 by pntsunts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

SRC = ft_ls.c recur.c sion.c ft_ls_a.c  ft_perm.c ft_checkf.c ft_confirm.c test.c ft_ls_a.c Permission.c printrev.c printr.c printl.c ft_printl.c ft_isdir.c loopdir.c ft_time.c

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
