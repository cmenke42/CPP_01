# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 18:54:58 by cmenke            #+#    #+#              #
#    Updated: 2023/09/16 18:05:08 by cmenke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := unnecessary_violence

OBJDIR := objects

SRCS := main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp

OBJS := $(patsubst %.cpp, ${OBJDIR}/%.o, ${SRCS})

HEADER := Weapon.hpp \
		HumanA.hpp \
		HumanB.hpp

#Production flags
CPPFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic

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