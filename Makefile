NAME 	= fractol

SRCS 	= $(wildcard *.c)
OBJS 	= $(SRCS:.c=.o)

GCC 	= gcc
MLX		= -lmlx -framework OpenGL -framework AppKit
RM		= rm -f
CFLAGS 	= -Wall -Werror -Wextra

%.o: %.c
			$(GCC) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
			$(GCC) $(MLX) $(OBJS) -o $(NAME)

all: 		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re