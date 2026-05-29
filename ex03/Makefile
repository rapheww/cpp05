NAME        = bureaucrat

CXX         = c++   
CXXFLAGS    = -Wall -Werror -Wextra -std=c++98 -MMD -I includes

SRC         = src/main.cpp \
			src/Bureaucrat.cpp \
			src/AForm.cpp \
			src/ShrubberyCreationForm.cpp \
			src/RobotomyRequestForm.cpp \
			src/PresidentialPardonForm.cpp

OBJ_DIR     = obj
OBJ         = $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)
DEPS        = $(OBJ:.o=.d)

all:    $(NAME)

$(NAME):    $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@printf "\033[1;92m$(NAME) created\n\033[0;39m"

$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)
	@printf "\033[1;91mObjects removed\n\033[0;39m"

fclean: clean
	rm -f $(NAME)
	@printf "\033[1;91mExecutable removed\n\033[0;39m"

re: fclean all

.PHONY: all clean fclean re