
NAME	=	minitalk

CC		=	cc

FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

CL	=	client

SV	=	server

all:		$(NAME)

$(CL):	$(CL).c minitalk.h
		@$(CC) -o $(CL) $(CL).c $(FLAGS)

$(SV):	$(SV).c minitalk.h
		@$(CC) -o $(SV) $(SV).c $(FLAGS)

$(NAME):	$(CL) $(SV)

clean:
			@$(RM) $(CL) $(SV)

fclean:		clean

re:			fclean all