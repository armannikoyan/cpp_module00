NAME := phonebook

SRCS := PhoneBook.cpp Contact.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

CXX := c++
CPPFLAGS := -Iinclude
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

-include $(DEPS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
