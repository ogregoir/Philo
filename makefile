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
			utils/utils2.c \
			
OBJS	=	$(SRCS:.c=.o)

NAME	=	philo

RM		=	rm -f

CC		=	gcc 

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=thread

#-------------------------------------------#

all		:	$(NAME)

$(NAME)	: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -pthread -c $< -o $@

clean :
	$(RM)   $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM)

re	: fclean all