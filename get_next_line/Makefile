SRCS	= ./get_next_line.c \
		  ./get_next_line_utils.c
SRCS_B	= ./get_next_line_bonus.c	\
		  ./get_next_line_utils_bonus.c

NAME	= get_next_line.a
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
INCS	= .
RM		= rm -f
LIBC	= ar rc
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

bonus : $(NAME) $(OBJS_B)
	$(LIBC) $(NAME) $(OBJS_B)

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME) $(bonus)

re : fclean all
