NAME = cub69d

CXXFLAGS = -Wall -Werror -Wextra -g
CFLAGS = -Imlx -I includes ${CXXFLAGS}

UTILS = ${addprefix utils/, map_maker blayer movements mini_libft event_handler rr0}
SAUCE = ${addprefix sauce/, ${addsuffix .c, main ${UTILS}}}
OBJS = ${SAUCE:c=o}

${NAME}: ${OBJS}
	${CC} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re