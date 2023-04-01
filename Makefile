# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 17:23:30 by bfaure            #+#    #+#              #
#    Updated: 2023/04/01 15:51:49 by bfaure           ###   ########lyon.fr    #
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
					
SRCS			=	${DIR_SRCS}main.c\
					${DIR_SRCS}utils.c\
					${DIR_SRCS}list/create_list.c\
					${DIR_SRCS}list/src/ft_lstadd_back.c\
					${DIR_SRCS}list/src/ft_lstlast.c\
					${DIR_SRCS}list/src/ft_lstclear.c\
					${DIR_SRCS}list/src/ft_lstnew.c\
					${DIR_SRCS}list/src/ft_print_list.c\

OBJS			=	${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

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

${DIR_OBJS}%.o:%.c ${HEAD} $(LIBFT_A)
	@				${MKDIR} ${DIR_OBJS}/srcs/list/src
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
