NAME = pipex

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

SRC = mian.c\
	ft_strjoin.c\
	ft_split.c\
	ft_strchr.c\
	ft_substr.c\
	outils.c\
	outils2.c\
	cmd_handel.c\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all