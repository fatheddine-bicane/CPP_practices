TARGET = megaphone
SOURCE_FILE = ./megaphone.cpp
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98
COMPILER = c++


GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m


#--------------------------------------------------------#

.phony : all clean re

all : $(TARGET)

$(TARGET) : $(SOURCE_FILE)
	@echo "$(GREEN)Building megaphone$(RESET)"
	@$(COMPILER) $(CPP_FLAGS) $(SOURCE_FILE) -o $(TARGET)

clean :
	@echo "$(RED)Removing megaphone$(RESET)"
	@rm -f megaphone

re : clean all
