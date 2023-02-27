NAME			= philo
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

SRC				= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRC_DIR			= src
SRC_FILES		= main.c utils.c input.c time.c setup.c

OBJ				= $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
OBJ_DIR			= obj
OBJ_FILES		= $(SRC_FILES:.c=.o)

HDR				= $(addprefix $(HDR_DIR)/, $(HDR_FILES))
HDR_DIR			= include
HDR_FILES		= philo.h

GREEN			= "\033[32m"
LGREEN			= "\033[92m"
DEFAULT			= "\033[39m"
RED				= "\033[31m"

ifeq ($(OS),Windows_NT)
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
#		LINK_FLAGS += -ltinfo
		LSANLFLAGS := -rdynamic -LLeakSanitizer -llsan -ldl -lstdc++
	endif
	ifeq ($(UNAME_S),Darwin)
		LSANLFLAGS := -LLeakSanitizer -llsan -lc++
	endif
endif

all:			obj_dir $(NAME)

$(NAME):		$(OBJ) | $(HDR)
				@$(CC) $^ -o $@ $(CFLAGS) $(LINK)
				@echo $(GREEN)Compiled$(DEFAULT) $@

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@echo $(LGREEN)Compiling$(DEFAULT) $<
				@$(CC) -c $< $(CFLAGS) -o $@

LSAN = LeakSanitizer
LSANLIB = /LeakSanitizer/liblsan.a

lsan: 			CFLAGS += -ILeakSanitizer -Wno-gnu-include-next
lsan:			LINK += $(LSANLFLAGS)
lsan:			fclean $(LSANLIB)
lsan:			all

$(LSAN):
				git clone https://github.com/mhahnFr/LeakSanitizer.git

$(LSANLIB): 	$(LSAN)
				@$(MAKE) -C LeakSanitizer
				@echo $(LGREEN)Compiling$(DEFAULT) $<

clean:
				@$(RM) $(OBJ)
				@$(RM) -r $(OBJ_DIR)
				@echo "cleaned $(NAME)"

fclean:
				@make clean
				@$(RM) $(NAME)
				@echo "fcleaned $(NAME)"

re:
				@make fclean
				@make all

obj_dir:
				@mkdir -p $(OBJ_DIR)

.PHONY:			all clean fclean re obj_dir lsan
