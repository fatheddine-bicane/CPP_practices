TARGET = harlFilter
SOURCE_FILES = $(wildcard ./Sources/*.cpp)
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -g
COMPILER = c++
OBJ_FILES = $(SOURCE_FILES:./Sources/%.cpp=./Sources/%.o)


GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m


#--------------------------------------------------------#

.phony : all clean fclean re

all : $(TARGET)

$(TARGET) : $(OBJ_FILES)
	@echo "$(GREEN)Building harlFilter$(RESET)"
	@$(COMPILER) $(CPP_FLAGS) $(OBJ_FILES) -o $(TARGET)

./Sources/%.o : ./Sources/%.cpp
	@$(COMPILER) $(CPP_FLAGS) -c $< -o $@

clean :
	@echo "$(RED)Removing object files$(RESET)"
	@rm -f $(OBJ_FILES)

fclean : clean
	@echo "$(RED)Removing harlFilter$(RESET)"
	@rm -f harlFilter

re : fclean all
