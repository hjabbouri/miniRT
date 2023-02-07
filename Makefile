# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 18:39:51 by hjabbour          #+#    #+#              #
#    Updated: 2023/02/06 15:11:53 by hjabbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc

CFLAGS = -Wall -Werror -Wextra 

ifdef debug
	CFLAGS += -g
else
	CFLAGS += -Ofast -flto
endif
LINK = -lmlx -framework OpenGL -framework AppKit

INC =	include/declarations.h \
		include/enums.h \
		include/macros.h \
		include/types.h

RM = rm -f

SRCS =	main.c \
		parser/rt_open.c \
		parser/rt_parse_basic.c \
		parser/rt_parse_object.c \
		parser/rt_parse_object_bonus.c \
		parser/rt_parse_utils.c \
		parser/rt_parse.c \
		objects/rt_solve_object.c \
		objects/rt_solve_object_bonus.c \
		objects/rt_solve_object_normal.c \
		objects/rt_solve_object_normal_bonus.c \
		libft/ft_strlen.c \
		libft/ft_strcmp.c \
		libft/ft_strncpy.c \
		libft/ft_itoa.c \
		libft/ft_isdigit.c \
		linear_algebra/debug_vec.c \
		linear_algebra/is_equal.c \
		linear_algebra/vector.c \
		linear_algebra/vector_utils.c \
		linear_algebra/vector_arithmetic.c \
		linear_algebra/vector_arithmetic_utils.c \
		linear_algebra/color_arithmetic.c \
		linear_algebra/matrix_2x2.c \
		linear_algebra/matrix_3x3.c \
		linear_algebra/matrix_3x3_utils.c \
		linear_algebra/matrix_4x4.c \
		linear_algebra/matrix_4x4_utils.c \
		linear_algebra/matrix_4x4_utils2.c \
		linear_algebra/matrix_transformation.c \
		linear_algebra/geometry_conversion.c \
		linear_algebra/matrix_rotation.c \
		objects/camera.c \
		objects/ray.c \
		objects/light.c \
		objects/debug_obj.c \
		objects/objects.c \
		objects/colors.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINK) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -Iinclude -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean