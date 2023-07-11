NAME			= push_swap
NAME_BONUS		= checker
BUILD			= ./build
SRCDIR			= src
BSRCDIR			= src_bonus
SRCS			= $(wildcard $(SRCDIR)/*.c)
SRCS_BONUS		= $(wildcard $(BSRCDIR)/*.c)
OBJS			= $(patsubst $(SRCDIR)/%.c, $(BUILD)/%.o, $(SRCS))
OBJS_BONUS		= $(patsubst $(BSRCDIR)/%.c, $(BUILD)/%.o, $(SRCS_BONUS))
INCS			= -Iincludes -ILibft
INCS_BONUS		= $(INCS) -Iincludes_bonus
HEADER			= $(wildcard includes/*.h)
HEADER_BONUS	= $(wildcard includes_bonus/*.h)
RM				= rm -rf
CC				= cc
FLAGS			= -Wall -Wextra -Werror #-fsanitize=address -g
LINKERS			= -LLibft -lft


all:	$(BUILD) lib $(NAME)


$(BUILD)/%.o:	$(SRCDIR)/%.c $(HEADER)
				$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) $(INCS) -o $(NAME) $(LINKERS)

$(BUILD)/%.o:	$(BSRCDIR)/%.c $(HEADER_BONUS)
				$(CC) $(FLAGS) $(INCS_BONUS) -c $< -o $@

bonus:	$(BUILD) lib $(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS)
			$(CC) $(FLAGS) $(OBJS_BONUS) $(INCS_BONUS) -o $(NAME_BONUS) $(LINKERS) 

$(BUILD):	$(SRCDIR) $(BSRCDIR)
			@mkdir $@

lib:
		$(MAKE) -C Libft
		
re: fclean all bonus

clean:
		$(RM) $(BUILD)
		@make clean -C Libft

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(NAME_BONUS)
		@make fclean -C Libft


.PHONY : all clean fclean re lib bonus


# test:			$(NAME)	
# 				$(eval ARG = $(shell jot -r 100 0 20000000))
# 				./push_swap $(ARG) | ./checker_Mac $(ARG)
# 				@echo -n "Instructions: "
# 				@./push_swap $(ARG) | wc -l

# test_my:		$(NAME)	$(BONUS_NAME)
# 				$(eval ARG = $(shell jot -r 500 0 20000000))
# 				./push_swap $(ARG) | ./checker $(ARG)
# 				@echo -n "Instructions: "
# 				@./push_swap $(ARG) | wc -l