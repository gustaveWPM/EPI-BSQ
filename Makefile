##
## EPITECH PROJECT, 2020
## BSQ Makefile
## File description:
## All-inclusive Makefile
##

NAME		=	bsq
LIB_NAME	=	libmy.a


LIB_PATH	=	lib
MY_LIB_PATH	=	lib/my
BSQ_LIB_PATH	=	lib/my/bsq
ERR_HANDLE_PATH	=	error_handling
TESTS_PATH	=	tests
TEST_FILE	=	test_bsq.c

UT		=	unit_tests
UT_PATH		=	$(TESTS_PATH)/$(TEST_FILE)
CRITERION_FLAGS	=	--coverage -lcriterion
INC_LIB		=	-L. -lmy

MAIN		=	src/main.c
EXE_SRC		=	src/bsq.c					\
			src/getters.c					\
			src/algo/bsq_algo.c				\
			src/algo/matrix.c				\
			src/algo/free_matrix.c				\
			src/algo/magic.c

LIB_SRC		=	$(MY_LIB_PATH)/my_str_funs.c			\
			$(MY_LIB_PATH)/my_str_funs2.c			\
			$(MY_LIB_PATH)/my_casting_funs.c		\
			$(MY_LIB_PATH)/my_maths.c

BSQ_SRC		=	$(BSQ_LIB_PATH)/file_exists.c

ERR_SRC		=	$(ERR_HANDLE_PATH)/error_handling.c		\
			$(ERR_HANDLE_PATH)/map_checkers.c		\
			$(ERR_HANDLE_PATH)/errors_msg.c

SRC		=	$(EXE_SRC) $(LIB_SRC) $(BSQ_SRC) $(ERR_SRC)
UT_SRC		=	$(UT_PATH) $(LIB_SRC) $(BSQ_SRC) $(ERR_SRC)


SRC_OBJ		=	$(MAIN:.c=.o) $(EXE_SRC:.c=.o)
LIB_OBJ		=	$(LIB_SRC:.c=.o)
BSQ_OBJ		=	$(BSQ_SRC:.c=.o)
ERR_OBJ		=	$(ERR_SRC:.c=.o)

PROG_OBJ	=	$(SRC_OBJ) $(BSQ_OBJ) $(ERR_OBJ)

OBJ		=	$(SRC_OBJ) $(BSQ_OBJ) $(ERR_OBJ) $(LIB_OBJ)


BUILD_PROG	=	gcc -o $(NAME) $(PROG_OBJ) $(INC_LIB) -Wall -Werror -W
BUILD_LIB	=	ar rc $(LIB_NAME) $(LIB_OBJ)

RM_OBJ		=	@rm -f $(OBJ)
RM_LIB		=	@find . -name "$(LIB_NAME)" -type f -delete
RM_TEST_FILES	=	@find . \( -name "*.gcno" -o -name "*.gcda" \) -type f -delete && rm -f unit_tests

.PHONY: all
.PHONY: build_lib
.PHONY: $(UT)
.PHONY: tests_run
.PHONY: clean
.PHONY: fclean
.PHONY: re

all:		$(NAME)

build_lib:	$(LIB_OBJ)
			@$(BUILD_LIB) > /dev/null
			@cp $(LIB_NAME) $(LIB_PATH)/$(LIB_NAME) && cp $(LIB_NAME) $(MY_LIB_PATH)/$(LIB_NAME)

$(NAME):	build_lib $(SRC_OBJ) $(BSQ_OBJ) $(ERR_OBJ)
			@$(BUILD_PROG) > /dev/null

$(UT):
			$(RM_TEST_FILES)
			@gcc -o $(UT) $(UT_SRC) $(CRITERION_FLAGS) $(INC_LIB) > /dev/null

tests_run:	all $(UT)
			@./$(UT)

clean:
			$(RM_OBJ)
			$(RM_LIB)
			$(RM_TEST_FILES)

fclean:		clean
			@rm -f $(NAME)

re: 		fclean all
