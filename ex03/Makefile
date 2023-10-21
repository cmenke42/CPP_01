# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 18:54:58 by cmenke            #+#    #+#              #
#    Updated: 2023/10/21 13:09:37 by cmenke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := a.out

OBJDIR := objects

SRCS := main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp

OBJS := $(patsubst %.cpp, ${OBJDIR}/%.o, ${SRCS})

HEADER := $(addprefix includes/, HumanA.hpp HumanB.hpp Weapon.hpp)

#Production flags
CPPFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic -I includes

#Development flags
# CPPFLAGS += -g -O0
# CPPFLAGS += -fsanitize=thread
# CPPFLAGS += -fsanitize=address

CC := c++

RM := rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CPPFLAGS} ${OBJS} -o ${NAME}

${OBJDIR}/%.o: %.cpp ${HEADER} | ${OBJDIR}
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