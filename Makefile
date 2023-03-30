# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 17:23:30 by bfaure            #+#    #+#              #
#    Updated: 2023/03/30 19:32:33 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	push_swap

LIBFT		=	libft.a

# ---- Directories ---- #

DIR_OBJS		=	.objs/

DIR_SRCS		=	srcs/

DIR_LIBFT		=	Libft/

LIBFT_A = $(DIR_LIBFT)$(LIBFT)

# ---- Files ---- #

HEAD			=	headers/push_swap.h\
					srcs/list/headers/push_swap_list.h\
					
SRCS			=	main.c\
					../srcs/list/src/ft_lstadd_back.c\
					../srcs/list/src/ft_lstlast.c\
					../srcs/list/src/ft_lstclear.c\
					../srcs/list/src/ft_lstnew.c\
					../srcs/list/src/ft_print_list.c\

OBJS = ${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

	
all		:	$(NAME)

$(LIBFT_A):	force
	@ ${MAKE} ${LIBFT} -C ${DIR_LIBFT} -j4

.PHONY:	all clean fclean re fclean_lib fclean_all force

# ---- Variables Rules ---- #

${NAME}	:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft

# ---- Compiled Rules ---- #

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEAD} $(LIBFT_A)
	@				${MKDIR} ${DIR_OBJS}
					${CC} ${CFLAGS} -I $(DIR_LIBFT) -I. -c $< -o $@	

# ---- Usual Commands ---- #

fclean_lib		:
					make fclean -C ${DIR_LIBFT}

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

fclean_all		:	fclean fclean_lib

re				:	fclean_all
					$(MAKE)
