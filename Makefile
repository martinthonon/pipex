NAME 		= pipex

FILES 		= main init utils process

SRCS		= $(addprefix srcs/, $(addsuffix .c, $(FILES)))

OBJS		= ${SRCS:.c=.o}

LIBFT		= lib/libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			make bonus -C lib/libft
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

all :		$(NAME)

clean:
			make fclean -C lib/libft
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
			$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re