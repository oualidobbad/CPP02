CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = fixed
SRC = Fixed.cpp  main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) -o $@ $<
%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $^
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
.PHONY: all clean fclean re