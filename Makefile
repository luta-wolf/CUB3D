NAME	=	cub3D

SRC_DIR	=	./srcs

LIBFT	=	${SRC_DIR}/libft/libft.a

MLX		=	${SRC_DIR}/mlx/libmlx.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

HEADER	=	$(addprefix includes/, constants.h cub.h strings.h structs.h)

FILES	=	$(addprefix parser/, check_id.c check_valid_map.c convert_line_to_data.c		\
						convert_line_to_map.c create_data.c create_map.c get_index.c 		\
						get_subline.c parse.c put_error.c read_file.c up_atoi.c				\
						validation_check.c)													\
			$(addprefix mlx_utils/, init_mlx.c draw.c draw_mini_map.c)						\
			$(addprefix game/, init_game.c exit.c action.c recasting.c)

SRCS	=	$(addprefix ${SRC_DIR}/, main.c ${FILES})

OBJS	=	${SRCS:.c=.o}

OS		=	$(shell uname)

.PHONY		:	re clean fclean test libft bonus norm

all			:	${NAME}

ifeq (${OS},Darwin)
${NAME}		:	${LIBFT} ${OBJS} ${MLX}
				${CC} ${CFLAGS} -framework OpenGL -framework AppKit \
				${OBJS} ${MLX} ${LIBFT} -o ${NAME}

%.o			:	%.c ${HEADER}
				${CC} ${CFLAGS} -c $< -o $@

${MLX}		:    mlx ;

mlx			:
				${MAKE} -C ${SRC_DIR}/mlx

clean		:
				rm -rf ${OBJS}
				${MAKE} -C ${SRC_DIR}/libft clean
				${MAKE} -C ${SRC_DIR}/mlx clean

fclean		:	clean
				rm -rf ${NAME}
				${MAKE} -C ${SRC_DIR}/libft fclean
else
MLX_DIR		=	${SRC_DIR}/mlx/minilibx-linux

MLX			=	${MLX_DIR}/libmlx.a

%.o			:	%.c ${HEADER}
				${CC} ${CFLAGS} -I/usr/include -I./includes -I${MLX_DIR} -c $< -o $@

${NAME}		:	${LIBFT} ${MLX} ${OBJS}
				${CC} ${CFLAGS} ${OBJS} -I./includes -I/usr/include \
				-L${MLX_DIR} -lmlx \
				-L/usr/lib -I${MLX_DIR} -lXext -lX11 -lm -lz \
 				-L./srcs/libft -lft \
 				-o ${NAME}

${MLX}		:    mlx ;

mlx			:
				cd ${MLX_DIR} && ./configure

clean		:
				rm -rf ${OBJS}
				${MAKE} -C ${SRC_DIR}/libft clean
				rm -rf ${SRC_DIR}/mlx/minilibx-linux/obj/*

fclean		:	clean
				rm -rf ${NAME}
				${MAKE} -C ${SRC_DIR}/libft fclean
				rm -rf ${SRC_DIR}/mlx/minilibx-linux/obj/*
				rm -rf ${SRC_DIR}/mlx/minilibx-linux/libmlx*.a
				rm -rf ${SRC_DIR}/mlx/minilibx-linux/Makefile.gen
endif

${LIBFT}	:	libft ;

libft		:
				${MAKE} -C ${SRC_DIR}/libft

bonus		:	all

norm		:
				@${MAKE} -C ${SRC_DIR}/libft norm
				@norminette ${SRCS} ${HEADER}

re			:	fclean all