NAME = Bsq

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = -Iinclude

SRCDIR = src
OBJDIR = .obj

SRCS = src/bsq.cpp  src/Fixed.cpp  src/main.cpp  src/Point.cpp

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re