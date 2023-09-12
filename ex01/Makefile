# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 18:54:58 by cmenke            #+#    #+#              #
#    Updated: 2023/09/11 23:30:18 by cmenke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := moar_brainz

OBJDIR := objects

SRCS := main.cpp \
		Zombie.cpp \
		zombieHorde.cpp

OBJS := $(patsubst %.cpp, ${OBJDIR}/%.o, ${SRCS})

#Production flags
CPPFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic

#Development flags
# CPPFLAGS := -Wall -Wextra -std=c++98 -pedantic
# CPPFLAGS += -g -O0
# CPPFLAGS += -fsanitize=thread
# CPPFLAGS += -fsanitize=address
# CPPFLAGS += -fsanitize=leak

# CC := c++
CC := c++

RM := rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CPPFLAGS} ${OBJS} -o ${NAME}

${OBJDIR}/%.o: %.cpp | ${OBJDIR}
	${CC} ${CPPFLAGS} -c $< -o $@

${OBJDIR}:
	mkdir -p ${OBJDIR}

clean:
	${RM} -r ${OBJDIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: