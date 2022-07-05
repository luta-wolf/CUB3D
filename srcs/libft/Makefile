NAME	=	libft.a

SRC 	=	ft_atoi.c			ft_bzero.c			ft_isalnum.c		\
			ft_isalpha.c		ft_isascii.c		ft_isdigit.c		\
			ft_isprint.c		ft_itoa.c			ft_memchr.c			\
			ft_memcmp.c			ft_memmove.c		ft_memset.c			\
			ft_split.c			ft_strchr.c			ft_strjoin.c		\
			ft_strlcat.c		ft_strlcpy.c		ft_strlen.c			\
			ft_strmapi.c		ft_strncmp.c		ft_strnstr.c		\
			ft_strrchr.c		ft_strtrim.c		ft_substr.c			\
			ft_tolower.c		ft_toupper.c		ft_memcpy.c			\
			ft_striteri.c		ft_putchar_fd.c		ft_putstr_fd.c		\
			ft_putendl_fd.c		ft_putnbr_fd.c		ft_calloc.c			\
			ft_strdup.c			ft_lstnew.c			ft_lstadd_front.c	\
			ft_lstsize.c		ft_lstlast.c		ft_lstadd_back.c	\
			ft_lstdelone.c		ft_lstclear.c		ft_strlen_char.c


OBJ		=	${SRC:.c=.o}

.PHONY	: 	all clean fclean re bonus norm

bonus	:	all

all		:	${NAME}

${NAME}	:	${OBJ}
			ar rcs ${NAME} $?

%.o		:	%.c libft.h
			cc -c -Werror -Wall -Wextra $< -o $@

clean	:
			rm -f ${OBJ}

fclean	:	clean
			rm -f ${NAME}

norm		:
				norminette ${SRCS} ${HEADER}

re		:	fclean all
