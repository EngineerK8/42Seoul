SRCS		= ./ft_printf.c \
			  ./ft_printf_utils.c \
			  ./ft_check.c \
			  ./ft_getlen.c \
			  ./ft_is.c \
			  ./ft_isrightcont.c \
			  ./ft_calc_print.c \
			  ./ft_print_c.c \
			  ./ft_print_d.c \
			  ./ft_print_p.c \
			  ./ft_print_percent.c \
			  ./ft_print_u.c \
			  ./ft_print_x.c \
			  ./ft_inputpad.c
	
LIBFTDIR	= ./libft/
LIBFT		= libft.a

NAME		= libftprintf.a
OBJS		= $(SRCS:.c=.o)
RM			= rm -f
LIBC		= ar -rcs
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	cp $(LIBFTDIR)$(LIBFT) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

$(OBJS) :
	$(CC) $(CFLAGS) -c $(SRCS)

clean :
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFTDIR)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFTDIR)

re : fclean all

.PHONY: all clean fclean re
