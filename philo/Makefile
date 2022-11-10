NAME = philo

CFLAGS	= -pthread -Wall -Wextra -Werror
RM		= rm -f
SRCS	= philo.c   \
		  init.c    \
		  check.c   \
		  ft_atoi.c \
		  utils.c


OBJS	= $(SRCS:.c=.o)

.c.o:
		cc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			cc $(OBJS) $(CFLAGS) -o $(NAME)

all:		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
