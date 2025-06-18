NAME = megaphone

SRC = megaphone.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
