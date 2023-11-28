# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 18:24:56 by marvin            #+#    #+#              #
#    Updated: 2023/09/27 18:24:56 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c \
			routine.c \
			parse.c \
			utils/utils.c \
			
OBJS	=	$(SRCS:.c=.o)

NAME	=	philo

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	utils/libft/libft.a

#-------------------------------------------#

all		:	$(NAME)

$(NAME)	:  $(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) ${LIBS} -pthread -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM)   $(OBJS)
	make	clean -C utils/libft

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	make fclean -C utils/libft

$(LIBFT) :
	make -C utils/libft

re	: fclean all