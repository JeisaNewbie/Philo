# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 17:19:40 by jhwang2           #+#    #+#              #
#    Updated: 2023/05/06 17:03:59 by jhwang2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO_BONUS	=	philo_bonus
NAME		=	$(PHILO_BONUS)
CC			=	cc
RM			=	rm -rf
LIBC		=	ar rcs
CFLAGS		=	-Wall -Wextra -Werror
BONUS_SRCS	=	main.c \
				init.c \
				check_error.c \
				fork.c \
				close_sem.c \
				do_routine.c \
				do_routine_odd.c \
				take_fork.c \
				philo_function1.c \
				philo_function2.c \
				philo_function3.c \
				wait_and_kill.c
BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

all :
	@$(MAKE) -j6 $(NAME)

$(NAME) : $(BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(BONUS_OBJS)

fclean : clean
	@$(RM) $(PHILO_BONUS)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re
