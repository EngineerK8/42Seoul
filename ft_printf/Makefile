SRCS		= ./ft_printf.c \
			  ./ft_printf_utils.c \
	
LIBFTDIR	= ./libft/
LIBFT		= libft.a

NAME		= libftprintf.a
OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	cp $(LIBFTDIR)$(LIBFT) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)
	$(MAKE) -C clean

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
